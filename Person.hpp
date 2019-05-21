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

class Person {
private:
    const std::string name; // const ?

public:
    Person(const std::string& name); // ref or value ?

    const std::string& getName() const; // const string ?

    virtual bool canDrive() const = 0;

};