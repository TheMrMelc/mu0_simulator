/*
 * InterfaceGraphique.cpp
 *
 *  Created on: 2015-05-14
 *      Author: Maïlis Cohen romain
 */

#include "../include/InterfaceGraphique.h"

InterfaceGraphique::InterfaceGraphique(Microprocesseur* m){
	microP = m;
}
	

void InterfaceGraphique::afficherEtatMicroP(Microprocesseur* m){
	printf("\n----------------------------------------------------------------------------\n"
			"NOUVELLE DEMANDE"
			"\n----------------------------------------------------------------------------\n"

			" \n état du système \n"
	"|   composants   |     valeurs    | signal associé |  valeur signal | \n"
	"|----------------+----------------+----------------+----------------|\n");
	for (unsigned int i=0; i<m->getComposant().size()-1; i++) {
		printf("|%16.16s|%16d|%16.16s|%16d|\n"
				"|----------------+----------------+----------------+----------------|\n",
				m->getComposant()[i]->getNomComposant().c_str(),
				m->getComposant()[i]->getValeur(),
				m->getComposant()[i]->getNomSignal().c_str(),
				m->getComposant()[i]->getSignal()
				);

	}

	}


void InterfaceGraphique::execute(Microprocesseur * m){
	printf("BIENVENUE \n Blablablabla\n\n");

	while (1){
		afficherEtatMicroP(m);
			m->decodeExecute();

			afficherEtatMicroP(m);
	}

}
