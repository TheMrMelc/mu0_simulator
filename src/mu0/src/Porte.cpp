/*
 * Porte.cpp
 *
 *  Created on: 16 avr. 2015
 *      Author: Romain Gobard
 */

#include "../include/Porte.h"





Porte::Porte(std::string nc, int nombreEntree, int nombreSortie,std::string ns, short int sig, short int val, bool activite, Bus* busEntrant, Bus* busSortant ) :
Composant(nc, nombreEntree, nombreSortie, ns,sig, val, activite, busEntrant, busSortant){}

Porte::Porte(std::string nc, int nombreEntree, int nombreSortie,std::string ns, short int sig, short int val, bool activite) :
Composant(nc, nombreEntree, nombreSortie, ns, sig, val, activite){}



Porte::~Porte(void){}
