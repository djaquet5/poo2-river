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
#include <algorithm>

Person::Person(const std::string& name, const Type& type) : name(name), type(type) {};

const std::string& Person::getName() const {
    return name;
}

const Type& Person::getType() const {
    return type;
}

bool Person::isConstraintExist(const Constraint *constraint) const {
    return find(constraints.begin(), constraints.end(), constraint) != constraints.end();
}

void Person::addConstraint(Constraint *constraint) {
    if(isConstraintExist(constraint)) {
        return;
    }

    constraints.push_back(constraint);
}

void Person::removeConstraint(Constraint *constraint) {
    if(!isConstraintExist(constraint)) {
        return;
    }

    constraints.remove(constraint);
}