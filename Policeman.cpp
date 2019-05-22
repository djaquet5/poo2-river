/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Policeman.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Policeman

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "Policeman.hpp"

Policeman::Policeman(const std::string &name): Driver(name, Type::POLICEMAN) {}