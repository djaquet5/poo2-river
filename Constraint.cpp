/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Constraint.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation des contraintes

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "Constraint.hpp"

Constraint::Constraint(const Type &guardian, std::list<Type>& blacklist): guardian(guardian), blacklist(blacklist) {}

Constraint::Constraint(const Type &guardian, std::initializer_list<Type> blacklist): guardian(guardian) {
    for(Type type : blacklist) {
        this->blacklist.push_back(type);
    }
}

const Type& Constraint::getGuardian() const {
    return guardian;
}

std::list<Type>& Constraint::getBlacklist() {
    return blacklist;
}

