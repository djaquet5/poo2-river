//
// Created by christoph on 21.05.19.
//


#include "Driver.hpp"

Driver::Driver(const std::string& name): Person::Person(name) {}

bool Driver::canDrive() {
    return true;
}
