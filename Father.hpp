/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Father.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe du père

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Driver.hpp"

class Father : public Driver {
public:

    /**
     * Constructeur
     *
     * @param name  Nom du père
     */
    explicit Father(const std::string& name);
};
