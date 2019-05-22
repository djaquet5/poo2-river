/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Person.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Person

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "Person.hpp"

Person::Person(const std::string& name, const Type& type) : name(name), type(type) {};

const std::string& Person::getName() const {
    return name;
}

const Type& Person::getType() const {
    return type;
}