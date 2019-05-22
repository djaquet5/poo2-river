/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Policeman.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Policeman

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Driver.hpp"

class Policeman : public Driver {
public:

    /**
     * Constructeur
     *
     * @param name  Nom du policier
     */
    Policeman(const std::string& name);
};
