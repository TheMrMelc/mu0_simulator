/*
 * Multiplexeur.cpp
 *
 *  Created on: 16 avr. 2015
 *      Author: Romain Gobard
 */

#include "../include/Multiplexeur.h"
#include <iostream>

Multiplexeur::Multiplexeur(std::string nc, int nombreEntree, int nombreSortie,std::string nv, short int sig, short int val, bool activite) :
Composant(nc, nombreEntree, nombreSortie, nv, sig, val, activite){
	for(int i=0;i<nombreEntree;i++){		//Ajout des entrées au vector en fonction du nombre d'entrée
		entree.push_back(i);
	}
}

Multiplexeur::Multiplexeur(std::string nc, int nombreEntree, int nombreSortie,std::string nv, short int sig, short int val, bool activite, Bus* busEntrant, Bus* busSortant ) :
Composant(nc, nombreEntree, nombreSortie,nv, sig, val, activite, busEntrant, busSortant){
	for(int i=0;i<nombreEntree;i++){		//Ajout des entrées au vector en fonction du nombre d'entrée
		entree.push_back(i);
	}
}


Multiplexeur::~Multiplexeur() {
	// TODO Auto-generated destructor stub
}

void Multiplexeur::fonction(void){

	short int sig = this->getSignal();


	// si on a deux entrées sur le multipleuxeur
	if(entree.size()==2){
		//si le signal est 0, on active l'entrée 0
		if(sig==0){
			setValeur(entree[0]);
		}
		// si le signal est 1 on sélectionne l'entrée 1
		if(sig==1){
			setValeur(entree[1]);
		}
	}
	if(entree.size()==3){
		if(sig==0){
			setValeur(entree[0]);
				}
		if(sig==1){
			setValeur(entree[1]);
		}
		if(sig==2){
			setValeur(entree[2]);
		}
	}
	if(entree.size()==4){
		if(sig==0){
			setValeur(entree[0]);
					}
		if(sig==1){
			setValeur(entree[1]);
		}
		if(sig==2){
			setValeur(entree[2]);
		}
		if(sig==3){
			setValeur(entree[3]);
		}
	}

}
