/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Type.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de l'énumaration Type

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <string>

//enum Type {THIEF, SON, GIRL, POLICEMAN, FATHER, MOTHER};

class Type {
    Type(const char* name);

    const char* name;
    unsigned int index;

    static unsigned int count;
    static const Type* type[];

public:
    const std::string getName() const;

    static const Type THIEF, SON, GIRL, POLICEMAN, FATHER, MOTHER;

    bool operator == (const Type& other) const;
};