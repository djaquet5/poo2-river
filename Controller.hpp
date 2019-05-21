/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Controller.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Controller

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <list>

#include "Person.hpp"
#include "Bank.hpp"
#include "Boat.hpp"

class Controller {
private:
    static const char PRINT = 'p';
    static const char EMBARK = 'e';
    static const char DISEMBARK = 'd';
    static const char MOVE = 'm';
    static const char RESET = 'r';
    static const char QUIT = 'q';
    static const char HELP = 'h';

    const char LINE = '-';
    const char RIVER = '=';

    const size_t LINE_LENGTH = 57;

    size_t turn;
//    std::list<Person*> people;
//    Bank rightBank;
//    Bank leftBank;
//    Boat boat;

    void executeCommand(std::string input);

public:
    Controller();

    ~Controller();

    void showMenu() const;

    void display() const;

    void nextTurn();

    void launch();
};