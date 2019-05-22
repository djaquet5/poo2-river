/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Son.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Son

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "Son.hpp"

Son::Son(const std::string& name) : NonDriver(name, Type::SON) {}