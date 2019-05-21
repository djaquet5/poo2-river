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

list<Person*>& Container::getPeople() {
    return people;
}