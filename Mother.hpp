/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Mother.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Mother

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Driver.hpp"

class Mother : public Driver {
public:

    /**
     * Constructeur
     *
     * @param name  Nom de la mère
     */
    Mother(const std::string& name);
};
