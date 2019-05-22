/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : NonDriver.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe NonDriver

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Person.hpp"

class NonDriver : public Person {
public:

    /**
     * Constructeur
     *
     * @param name  Nom de la personne
     * @param type  Type de la personne
     */
    NonDriver(const std::string& name, const Type& type);

    /**
     * Indique si la personne peut conduire un bateau
     *
     * @return       True si l'instance peut conduire un bateau, False sinon.
     */
    bool canDrive() const override;
};