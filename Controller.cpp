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

using namespace std;

Controller::Controller() : turn(0) {}

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
    switch(c) {
        case PRINT:
            // Ne fais rien, on affiche après le switch
            break;

        case EMBARK:
            cout << "embark" << endl;
            break;

        case DISEMBARK:
            cout << "disembark" << endl;
            break;

        case MOVE:
            cout << "move" << endl;

//            if(boat.getBank() == *leftBank) {
//                boat.setBank(rightBank);
//            } else {
//                boat.setBank(leftBank);
//            }
            break;

        case RESET:
            cout << "reset" << endl;
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

Controller::~Controller() {}