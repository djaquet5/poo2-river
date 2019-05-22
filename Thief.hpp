/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Thief.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Thief

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "NonDriver.hpp"

class Thief : public NonDriver {
public:

    /**
     * Constructeur
     *
     * @param name  Nom du voleur
     */
    Thief(const std::string& name);
};