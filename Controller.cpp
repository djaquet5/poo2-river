/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Controller.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Controller

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Controller.hpp"
#include "utils.h"
#include "Son.hpp"
#include "Father.hpp"
#include "Mother.hpp"
#include "Girl.hpp"
#include "Policeman.hpp"
#include "Thief.hpp"

using namespace std;

Controller::Controller() : turn(0) {
    initialize();
}

void Controller::showMenu() const {
    cout << left << setw(7) << PRINT << ": afficher" << endl;
    cout << EMBARK << " <nom>: embarquer <nom>" << endl;
    cout << DISEMBARK << " <nom>: debarquer <nom>" << endl;
    cout << left << setw(7) << MOVE << ": deplacer bateau" << endl;
    cout << left << setw(7) << RESET << ": reinitialiser" << endl;
    cout << left << setw(7) << QUIT << ": quitter" << endl;
    cout << left << setw(7) << HELP << ": menu" << endl << endl;
}

void Controller::launch() {
    showMenu();
    display();
    nextTurn();
}

void Controller::display() const {
    cout << *leftBank << endl;

    if(boat->getBank() == leftBank) {
        cout << *boat << endl;
        cout << makeLine('=') << endl << endl;
    } else {
        cout << endl << makeLine('=') << endl;
        cout << *boat << endl;
    }


    cout << *rightBank << endl;
    cout << endl;
}

void Controller::nextTurn() {
    string input;

    cout << turn << "> ";

    while(getline(cin, input)) {
        executeCommand(input);
        cout << ++turn << "> ";
    }
}

void Controller::executeCommand(string input) {
    char c = input[0];
    string person;

    switch(c) {
        case PRINT:
            // Ne fais rien, on affiche après le switch
            break;

        case EMBARK:
            person = input.substr(2);
            embark(person);
            break;

        case DISEMBARK:
            person = input.substr(2);
            disembark(person);
            break;

        case MOVE:
            move();
            break;

        case RESET:
            reset();
            break;

        case HELP:
            showMenu();
            break;

        case QUIT:
            exit(EXIT_SUCCESS);

        default:
            cout << "Commande non reconnue" << endl;
    }

    display();
}

Controller::~Controller() {
    free();
}

void Controller::move() {

    // Il y a au moins 1 conducteur
    if (!isThereADriverOnBoat()) {
        displayErrorMessage("Il faut au moins un conducteur");
        return;
    }

    if (boat->getBank() == rightBank) {
        boat->move(leftBank);
    } else {
        boat->move(rightBank);
    }
}

void Controller::embark(string person) {
    // On ne surcharge pas le bateau
    if(boat->getNbPeople() == boat->getCapacityMax()) {
        displayErrorMessage("Le bateau ne peut avoir plus de personne a son bord.");
        return;
    }

    Person *p = peopleMap.at(person);
    std::list<Constraint*> constraints;
    std::list<Type> blackList;
    std::list<Person*> bankedPeople;

    if(!boat->getPeople().empty()) {
        for(Constraint *constraint : boat->getPeople().front()->getConstraints()) {
            blackList = constraint->getBlacklist();
            std::list<Type>::iterator it = find(blackList.begin(), blackList.end(), p->getType());

            if(it != blackList.end()) {
                displayErrorMessage(p->getType().getName() + " avec " + it->getName() + " sans " + constraint->getGuardian().getName());
                return;
            }
        }
    }

    boat->getBank()->remove(p);
    // TODO : tester si la personne peux quitter la rive
    bankedPeople = boat->getBank()->getPeople();
    for(Person *bankedPerson : bankedPeople) {
        for(Constraint *constraint : bankedPerson->getConstraints()) {
            if(p->getType() == constraint->getGuardian()) {
//                find(bankedPeople..begin(), bankedPeople.end(), p->getType()) != bankedPeople.end());
//                    displayErrorMessage("C'est pas mal la merde la");
//                    boat->getBank()->add(p);
//                    return;

            }
        }
    }

    boat->add(p);
}

void Controller::disembark(string person) {
    Person *p = peopleMap.at(person);

    std::list<Person *> bankedPeople = boat->getBank()->getPeople();
    std::list<Type> blackList;

    // TODO : tester si la personne peux aller sur la rive
//    for(Person *bankedPerson : bankedPeople) {
//        for(Constraint *constraint : bankedPerson->getConstraints()) {
//            blackList = constraint->getBlacklist();
//
//            if(find(blackList.begin(), blackList.end(), p->getType()) != blackList.end() &&
//               find(bankedPeople.begin(), bankedPeople.end(), constraint->getGuardian()) != bankedPeople.end()) {
//                displayErrorMessage("C'est la merde");
//                return;
//            }
//        }
//    }

    boat->remove(p);
    boat->getBank()->add(p);
}

void Controller::reset() {
    free();
    peopleMap.clear();
    initialize();
    turn = -1;  // TODO: Pour recommencer au tour 0 ?
}

void Controller::displayErrorMessage(std::string message) const {
    cout << "### " << message << endl;
}

bool Controller::isThereADriverOnBoat() const {
    // Il y a au moins 1 conducteur
    for (Person *p : boat->getPeople()) {
        if (p->canDrive()) {
            return true;
        }
    }

    return false;
}

void Controller::initialize() {
    rightBank = new Bank("Droite");
    leftBank = new Bank("Gauche");
    boat = new Boat(leftBank);

    // fill people map
    peopleMap.insert({"pere", new Father("pere") });
    peopleMap.insert({"mere", new Mother("mere") });
    peopleMap.insert({"paul", new Son("paul") });
    peopleMap.insert({"pierre", new Son("pierre") });
    peopleMap.insert({"julie", new Girl("julie") });
    peopleMap.insert({"jeanne", new Girl("jeanne") });
    peopleMap.insert({"policier", new Policeman("policier") });
    peopleMap.insert({"voleur", new Thief("voleur") });


    // create constraints
    constraints.push_back(new Constraint(Type::MOTHER, {Type::GIRL})); // 0
    constraints.push_back(new Constraint(Type::FATHER, {Type::SON})); // 1
    constraints.push_back(new Constraint(Type::MOTHER, {Type::FATHER})); // 2
    constraints.push_back(new Constraint(Type::FATHER, {Type::MOTHER})); // 3
    constraints.push_back(new Constraint(Type::POLICEMAN, {Type::THIEF})); // 4
    constraints.push_back(new Constraint(Type::POLICEMAN, {Type::MOTHER, Type::FATHER, Type::GIRL, Type::SON})); // 5

    // add constraints

    // can't have father with girl wihout mother
    peopleMap.at("pere")->addConstraint(constraints.at(0));
    peopleMap.at("julie")->addConstraint(constraints.at(2));
    peopleMap.at("jeanne")->addConstraint(constraints.at(2));

    // can't have mother with son without father
    peopleMap.at("mere")->addConstraint(constraints.at(1));
    peopleMap.at("paul")->addConstraint(constraints.at(3));
    peopleMap.at("pierre")->addConstraint(constraints.at(3));

    // can't have family with thief without policeman
    peopleMap.at("pere")->addConstraint(constraints.at(4));
    peopleMap.at("mere")->addConstraint(constraints.at(4));
    peopleMap.at("paul")->addConstraint(constraints.at(4));
    peopleMap.at("pierre")->addConstraint(constraints.at(4));
    peopleMap.at("julie")->addConstraint(constraints.at(4));
    peopleMap.at("jeanne")->addConstraint(constraints.at(4));
    peopleMap.at("voleur")->addConstraint(constraints.at(5));

    leftBank->add(peopleMap.at("pere"));
    leftBank->add(peopleMap.at("mere"));
    leftBank->add(peopleMap.at("paul"));
    leftBank->add(peopleMap.at("pierre"));
    leftBank->add(peopleMap.at("julie"));
    leftBank->add(peopleMap.at("jeanne"));
    leftBank->add(peopleMap.at("policier"));
    leftBank->add(peopleMap.at("voleur"));
}

void Controller::free() {
    delete rightBank;
    delete leftBank;
    delete boat;

    // delete people
    for (auto it : peopleMap) {
        delete it.second;
    }

    // delete constraints
    for (auto it : constraints) {
        delete it;
    }
}