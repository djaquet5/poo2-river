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

Bank* Boat::getBank() const {
    return currentBank;
}

void Boat::move(Bank* bank) {
    currentBank = bank;
}