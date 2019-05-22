/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Son.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Son

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "NonDriver.hpp"

class Son : public NonDriver {
public:

    /**
     * Constructeur
     *
     * @param name  Nom du fils
     */
    Son(const std::string& name);
};