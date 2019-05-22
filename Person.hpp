/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Person.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Person

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <string>

#include "Type.hpp"
#include "Constraint.hpp"

class Person {
    const std::string name;
    Type type;
    std::list<Constraint *> constraints;

    /**
     * Indique si la contrainte est déjà présente
     *
     * @param constraint    Contrainte à vérifier
     * @return      True si la contrainte est déjà présente, False sinon.
     */
    bool isConstraintExist(const Constraint *constraint) const;

public:

    /**
     * Constructeur
     *
     * @param name  Nom de la personne
     * @param type  Type de la personne
     */
    Person(const std::string& name, const Type& type);

    /**
     * Destructeur
     */
    virtual ~Person();

    /**
     * Retourne le nom de la personne
     *
     * @return      Nom de la personne
     */
    const std::string& getName() const;

    /**
     * Retourne le type de la personne
     *
     * @return      Type de la personne
     */
    const Type& getType() const;

    /**
     * Indique si la personne peut conduire un bateau
     *
     * @return       True si l'instance peut conduire un bateau, False sinon.
     */
    virtual bool canDrive() const = 0;

    /**
     * Ajoute une contrainte
     *
     * @param constraint    Contrainte à ajouter
     */
    void addConstraint(Constraint *constraint);

    /**
     * Supprime une contrainte
     *
     * @param constraint    Contrainte à supprimer
     */
    void removeConstraint(Constraint *constraint);

    /**
     * Retourne la liste des contraintes
     *
     * @return      list de Constraint*
     */
    std::list<Constraint*> getConstraints() const;
};