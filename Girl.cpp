/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Girl.cpp
 Auteur(s)   : David Jaquet & Christoph Rueff
 Date        : 21.05.2019
 But         : Implémentation de la classe Girl

 Remarque(s) :

 -----------------------------------------------------------------------------------
*/

#include "Girl.hpp"

Girl::Girl(const std::string& name) : NonDriver(name, Type::GIRL) {}