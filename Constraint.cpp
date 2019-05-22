//
// Created by christoph on 22.05.19.
//

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

