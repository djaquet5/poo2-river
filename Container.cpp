//
// Created by jostoph on 5/7/19.
//

#include <algorithm>
#include "Container.hpp"

using namespace std;

Container::Container(const string& name) : name(name) {}

bool Container::add(Person* person){
    if(!contains(person)) {
        people.push_back(person);
        return true;
    }

    return false;
}

void Container::remove(Person* person) {
    people.remove(person);
}

bool Container::contains(Person* person) const {
    return find(people.begin(), people.end(), person) != people.end();
}

const string& Container::getName() const {
    return name;
}