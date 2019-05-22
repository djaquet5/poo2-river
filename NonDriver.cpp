/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : NonDriver.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe NonDriver

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "NonDriver.hpp"

NonDriver::NonDriver(const std::string& name, const Type& type): Person::Person(name, type) {}

bool NonDriver::canDrive() const {
    return false;
}