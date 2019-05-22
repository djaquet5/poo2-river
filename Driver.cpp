//
// Created by christoph on 21.05.19.
//


#include "Driver.hpp"

Driver::Driver(const std::string& name, const Type& type): Person::Person(name, type) {}

bool Driver::canDrive() const {
    return true;
}
