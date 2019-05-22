//
// Created by christoph on 21.05.19.
//

#pragma once

#include "Person.hpp"

class NonDriver : public Person {
public:
    NonDriver(const std::string& name, const Type& type);

    bool canDrive();
};