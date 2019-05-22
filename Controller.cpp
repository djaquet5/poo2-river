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

#include "Controller.hpp"
#include "utils.h"
#include "Son.hpp"
#include "Father.hpp"
#include "Mother.hpp"
#include "Girl.hpp"
#include "Policeman.hpp"
#include "Thief.hpp"

using namespace std;

Controller::Controller() {
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
    displayLine(LINE, LINE_LENGTH);
    cout << "Gauche: pere mere paul pierre julie jeann policier voleur" << endl;
    displayLine(LINE, LINE_LENGTH);
    cout << "Bateau: " << endl;
    displayLine(RIVER, LINE_LENGTH);
    cout << endl;
    displayLine(LINE, LINE_LENGTH);
    cout << "Droite: " << endl;
    displayLine(LINE, LINE_LENGTH);
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
    // TODO : Check inputs ?
    char c = input[0];
    string person;

    switch(c) {
        case PRINT:
            // Ne fais rien, on affiche après le switch
            break;

        case EMBARK:
            cout << "embark" << endl;
            // TODO : get nom de la personne
//            embark(person);
            break;

        case DISEMBARK:
            cout << "disembark" << endl;
            // TODO : get nom de la personne
//            disembark(person);
            break;

        case MOVE:
            cout << "move" << endl;
//            move();
            break;

        case RESET:
            cout << "reset" << endl;
//            reset();
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
    // TODO : tester les contraintes

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

    // TODO : Vérifier les contraintes avec les personnes restant sur lîle et allant sur le bateau
}

void Controller::disembark(string person) {
    // TODO : vérifier les contraintes avec les personnes allant sur la rive (et checker sur les personnes restantes sur le bateau ?)
}

void Controller::reset() {
    free();
    initialize();
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

    turn = 0;

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
    constraints.push_back(new Constraint(MOTHER, {GIRL})); // 0
    constraints.push_back(new Constraint(FATHER, {SON})); // 1
    constraints.push_back(new Constraint(MOTHER, {FATHER})); // 2
    constraints.push_back(new Constraint(FATHER, {MOTHER})); // 3
    constraints.push_back(new Constraint(POLICEMAN, {THIEF})); // 4
    constraints.push_back(new Constraint(POLICEMAN, {MOTHER, FATHER, GIRL, SON})); // 5

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