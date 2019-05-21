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
    int turn;
    std::list<Person*> people;
    Bank rightBank;
    Bank leftBank;
    Boat boat;

public:
    Controller();

    ~Controller();

    void showMenu() const;

    void display() const;

    void nextTurn();
};