//
// Created by christoph on 21.05.19.
//

#pragma once

#include "Person.hpp"

class Driver : public Person {
public:
    Driver(const std::string& name, const Type& type);

    bool canDrive() const override;
};
