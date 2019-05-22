/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Boat.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Boat

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container {
    Bank* currentBank;
    const size_t CAPACITY_MAX = 2;

public:

    /**
     * Constructeur
     *
     * @param currentBank   Rive sur laquelle le bateau est amaré
     */
    Boat(Bank* currentBank);

    /**
     * Recupère la rive actuelle du bateau
     *
     * @return  Pointeur sur la rive sur laquelle le bateau est amaré
     */
    Bank* getBank() const; // const ??

    /**
     * Déplace le bateau sur la rive reçue en paramètre
     *
     * @param bank  Pointeur sur la nouvelle rive
     */
    void move(Bank* bank);

    /**
     * Récupère la capacité maximum du bateau
     *
     * @return  Capacité maximum du bateau
     */
    size_t getCapacityMax() const;

    /**
     * Retourne le nombre de personne actuellement sur le bateau
     *
     * @return  Nombre de personne sur le bateau
     */
    size_t getNbPeople() const;
};
