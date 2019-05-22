//
// Created by christoph on 21.05.19.
//

#include "NonDriver.hpp"

NonDriver::NonDriver(const std::string& name, const Type& type): Person::Person(name, type) {}

bool NonDriver::canDrive() {
    return false;
}