//
// Created by David on 23.05.2019.
//

#include "Type.hpp"

const Type Type::THIEF("voleur");
const Type Type::SON("fils");
const Type Type::GIRL("fille");
const Type Type::POLICEMAN("policier");
const Type Type::FATHER("pere");
const Type Type::MOTHER("mere");

Type::Type(const char* name) : name(name) {}

const char* Type::getName() const {
    return name;
}

bool Type::operator == (const Type& other) const {
    return name == other.getName();
}
