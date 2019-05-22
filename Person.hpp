/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Person.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Person

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <string>
#include "Type.hpp"

class Person {
private:
    const std::string name; // const ?
    Type type;

public:
    Person(const std::string& name, const Type& type); // ref or value ?

    const std::string& getName() const; // const string ?

    const Type& getType() const;

    virtual bool canDrive() const = 0;

};