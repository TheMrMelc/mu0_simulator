/*
 * Multiplexeur.h
 *
 *  Created on: 16 avr. 2015
 *      Author: Romain Gobard
 */

#ifndef MULTIPLEXEUR_H_
#define MULTIPLEXEUR_H_

#include <vector>
#include "Bus.h"
#include "Composant.h"


class Multiplexeur : public Composant {

public:

	std::vector <int> entree; // Pour pouvoir gérer les différentes entrées du multiplexeur

public:
	//Constructeur et Destructeur

	virtual ~Multiplexeur();

	Multiplexeur(std::string nc, int nombreEntree, int nombreSortie,std::string ns, short int sig, short int val, bool activite);
	Multiplexeur(std::string nc, int nombreEntree, int nombreSortie,std::string ns, short int sig, short int val, bool activite, Bus* busEntrant, Bus* busSortant);

	void setValeur(short int v){valeur = v;}
	short int getValeur(void){return valeur;}



	//Méthodes//
	void fonction(void);		//Prototype à revoir (Voir mes commentaires dans Multiplexeur.cpp) Nouvelle proposition ->
};

#endif
