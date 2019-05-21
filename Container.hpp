/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Container.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Container

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <string>
#include <list>

#include "Person.hpp"


class Container {
private:
    const std::string name;
    std::list<Person*> people;

public:
    Container(const std::string& name);

    virtual bool add(Person* person);

    void remove(Person* person);

    bool contains(Person* person) const;

    const std::string& getName() const;

    std::list<Person*>& getPeople();
};