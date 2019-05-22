/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Bank.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Bank

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once


#include "Container.hpp"

class Bank : public Container {
public:

    /**
     * Constructeur
     *
     * @param name  Nom de la rivière
     */
    Bank(std::string name);
};