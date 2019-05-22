/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Thief.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Thief

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "Thief.hpp"

Thief::Thief(const std::string& name) : NonDriver(name, Type::THIEF) {}