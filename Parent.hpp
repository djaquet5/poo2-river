//
// Created by christoph on 21.05.19.
//

#pragma once

#include <list>

#include "Driver.hpp"
#include "Child.hpp"

class Parent : public Driver {
private:
    const std::list<Child*> children;

public:
    Parent(const std::string& name, const std::list<Child*>& children);

    const std::list<Child*>& getChildren();

    const Parent& getSpouse(); // TODO ?????
};
