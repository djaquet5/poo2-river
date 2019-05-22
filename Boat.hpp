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
public:
    Boat(Bank* currentBank);

    Bank* getBank() const; // const ??

    void move(Bank* bank);
};
