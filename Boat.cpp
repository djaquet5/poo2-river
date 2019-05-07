//
// Created by jostoph on 5/7/19.
//

#include "Boat.hpp"

using namespace std;

Boat::Boat(Bank* bank) : Container("boat"), currentBank(bank) {}

bool Boat::add(Person *person) {
    if(getPeople().size() < 2) {
        return Container::add(person);
    }

    return false;
}

Bank* Boat::getBank() const {
    return currentBank;
}

void Boat::move(Bank* bank) {
    currentBank = bank;
}