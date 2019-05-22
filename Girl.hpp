/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Girl.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Girl

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "NonDriver.hpp"

class Girl : public NonDriver {
public:

    /**
     * Constructeur
     *
     * @param name  Nom de la fille
     */
    Girl(const std::string& name);
};
