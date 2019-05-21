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

#include "Boat.hpp"

using namespace std;

Boat::Boat(Bank* bank) : Container("boat"), currentBank(bank) {}

bool Boat::add(Person *person) {
    if(getPeople().size() < 2) {
        return Container::add(person);
    }

    return false;
}

Bank* Boat::getBank() const {
    return currentBank;
}

void Boat::move(Bank* bank) {
    currentBank = bank;
}