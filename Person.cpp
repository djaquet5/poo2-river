//
// Created by jostoph on 5/7/19.
//

#include "Person.hpp"

Person::Person(std::string& name) : name(name){};

const std::string& Person::getName() const {
    return name;
}