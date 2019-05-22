/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Boat.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Boat

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container {
private:
    Bank* currentBank;
    const size_t CAPACITY_MAX = 2;
public:
    Boat(Bank* currentBank);

    Bank* getBank() const; // const ??

    void move(Bank* bank);

    size_t getCapacityMax() const;

    size_t getNbPeople() const;
};
