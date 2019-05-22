//
// Created by christoph on 22.05.19.
//

#pragma once

#include "Type.hpp"
#include <list>

class Constraint {
private:
    const Type& guardian;
    std::list<Type> blacklist;

public:
    Constraint(const Type& guardian, std::list<Type>& blacklist);

    Constraint(const Type& guardian, std::initializer_list<Type> blacklist);

    const Type& getGuardian() const;

    std::list<Type>& getBlacklist();
};
