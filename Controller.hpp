//
// Created by jostoph on 5/7/19.
//

#ifndef POO2_RIVER_CONTROLLER_HPP
#define POO2_RIVER_CONTROLLER_HPP

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


#endif //POO2_RIVER_CONTROLLER_HPP
