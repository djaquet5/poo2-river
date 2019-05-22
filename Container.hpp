/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Container.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Container

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <string>
#include <list>

#include "Person.hpp"


class Container {
    const std::string name;
    std::list<Person*> people;

public:
    /**
     * Constructeur du container
     *
     * @param name      Nom du container
     */
    Container(const std::string& name);

    /**
     * Ajoute une personne dans le container
     *
     * @param person    Personne à ajouter
     * @return          True si la personne a pu être ajouter, False sinon.
     */
    virtual bool add(Person* person);

    /**
     * Supprime une personne du container
     *
     * @param person    Personne à supprimer
     */
    void remove(Person* person);

    /**
     * Indique si la personne est dans le container
     *
     * @param person    Personne à vérifier
     * @return          True si la personne est dans le container, False sinon.
     */
    bool contains(Person* person) const;

    /**
     * Retourne le nom du container
     *
     * @return          Nom du container
     */
    const std::string& getName() const;

    /**
     * Retourne la liste des personnes actuellement dans le container
     *
     * @return          Liste des personnes dans le container
     */
    const std::list<Person*>& getPeople() const;
};