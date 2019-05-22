/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Constraint.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe des contraintes

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Type.hpp"
#include <list>

class Constraint {
    const Type& guardian;
    std::list<Type> blacklist;

public:
    /**
     * Constructeur avec une liste de blacklist
     *
     * @param guardian      Type gardien de la contrainte
     * @param blacklist     list de type à blacklisté
     */
    Constraint(const Type& guardian, std::list<Type>& blacklist);

    /**
     * Constructeur avec une liste d’initialiseurs
     *
     * @param guardian      Type gardien de la contrainte
     * @param blacklist     list d’initialiseurs de Type à blacklisté
     */
    Constraint(const Type& guardian, std::initializer_list<Type> blacklist);

    /**
     * Récupère le type du gardien de la contrainte
     *
     * @return  Type du gardien de la contrainte
     */
    const Type& getGuardian() const;

    /**
     * Liste des Types blacklisté
     * @return
     */
    std::list<Type>& getBlacklist();
};
