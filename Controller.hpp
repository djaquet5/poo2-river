/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Controller.hpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Structure de la classe Controller

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#pragma once

#include <map>
#include <vector>

#include "Person.hpp"
#include "Bank.hpp"
#include "Boat.hpp"

class Controller {
    static const char PRINT = 'p';
    static const char EMBARK = 'e';
    static const char DISEMBARK = 'd';
    static const char MOVE = 'm';
    static const char RESET = 'r';
    static const char QUIT = 'q';
    static const char HELP = 'h';

    const char LINE = '-';
    const char RIVER = '=';

    const size_t LINE_LENGTH = 57;

    size_t turn;
    std::map<std::string, Person*> peopleMap;
    std::vector<Constraint*> constraints;
    Bank *rightBank;
    Bank *leftBank;
    Boat *boat;

    /**
     * Execute la commande choisie voulue par l'utilisateur
     *
     * @param input     Commande voulue par l'utilisateur
     */
    void executeCommand(std::string input);

    /**
     * Déplace le bateau d'unerive à l'autre
     */
    void move();

    /**
     * Ajoute une personne dans le bateau
     *
     * @param person    Personne à ajouter dans le bateau
     */
    void embark(std::string person);

    /**
     * Enlève une personne du bateau
     *
     * @param person    Personne à enlever du bateau
     */
    void disembark(std::string person);

    /**
     * Affiche un message d'erreur
     *
     * @param message   Message d'erreur à afficher
     */
    void displayErrorMessage(std::string message) const;

    /**
     * Vérifie si il y a une personne pouvant conduire le bateau dans le-dit bateau
     *
     * @return          True si un conducteur est dans le bateau, False sinon.
     */
    bool isThereADriverOnBoat() const;

    /**
     * Ré-initialise le jeu
     */
    void reset();

    /**
     * Initilalise le jeu
     */
    void initialize();

    /**
     * Libère les différents pointeurs
     */
    void free();

public:

    /**
     * Constructeur
     */
    Controller();

    /**
     * Destructeur
     */
    ~Controller();

    /**
     * Affiche le menu
     */
    void showMenu() const;

    /**
     * Affiche les rives et le bateau
     */
    void display() const;

    /**
     * Gère les différents tours
     */
    void nextTurn();

    /**
     * Démarre la partie
     */
    void launch();
};