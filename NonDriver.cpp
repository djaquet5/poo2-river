//
// Created by christoph on 21.05.19.
//

#include "NonDriver.hpp"

NonDriver::NonDriver(const std::string& name): Person::Person(name) {}

bool NonDriver::canDrive() {
    return false;
}