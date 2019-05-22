/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Driver.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe des conducteurs

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/


#include "Driver.hpp"

Driver::Driver(const std::string& name, const Type& type): Person::Person(name, type) {}

bool Driver::canDrive() const {
    return true;
}
