/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Boat.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Boat

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include <iostream>

#include "Boat.hpp"

using namespace std;

Boat::Boat(Bank* bank) : Container("Bateau"), currentBank(bank) {}

Bank* Boat::getBank() const {
    return currentBank;
}

void Boat::move(Bank* bank) {
    currentBank = bank;
}

size_t Boat::getCapacityMax() const {
    return CAPACITY_MAX;
}

size_t Boat::getNbPeople() const {
    return getPeople().size();
}

ostream& operator << (ostream& os, const Boat& boat) {
    os << boat.getName() << ": < ";

    for(Person *p : boat.getPeople()) {
        os << p->getName() << " ";
    }

    os << ">";

    return os;
}