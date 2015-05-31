/*
 * Registre.cpp
 *
 *  Created on: 10 avr. 2015
 *      Author: mailis
 */
#include "../include/Registre.h"

Registre::Registre(std::string nc,int _nbEntree, int _nbSortie,std::string ns, short int _signal, short int _valeur, bool _actif):
Composant(nc, _nbEntree, _nbSortie, ns, _signal, _valeur, _actif){}

Registre::Registre(std::string nc,int _nbEntree, int _nbSortie, std::string ns,short int _signal, short int _valeur, bool _actif, Bus* _busEntrant, Bus* _busSortant):
Composant(nc, _nbEntree, _nbSortie,ns,  _signal, _valeur, _actif, _busEntrant, _busSortant){}


Registre::Registre(std::string nc,int _nbEntree, int _nbSortie, std::string ns,short int _signal, short int _valeur, bool _actif, std::vector<Bus*> _busEntrant, std::vector<Bus*> _busSortant):
Composant(nc, _nbEntree, _nbSortie,ns,  _signal, _valeur, _actif, _busEntrant, _busSortant){}




void Registre::fonction(short int entree){

	short int sortie;

	if (getSignal() == 1){
		setValeur(entree);
	}
	sortie = getValeur();
	setValeur(sortie);

}

Registre::~Registre(void){}

