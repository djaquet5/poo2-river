/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Container.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Container

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include <algorithm>
#include <iostream>

#include "Container.hpp"
#include "utils.h"

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

const list<Person*>& Container::getPeople() const {
    return people;
}

ostream& operator << (ostream& os, const Container& container) {
    os << makeLine('-') << endl;
    os << container.name << ": ";

    for (Person *p : container.people) {
        os << p->getName() << " ";
    }

    os << endl << makeLine('-');

    return os;
}