/*
 * Memoire.cpp
 *
 *  Created on: 2015-05-02
 *      Author: romain
 */

// le bi=ut est de simu

#include "../include/Memoire.h"
#include <iostream>



//emplacement_memoire : taille de la mémoire
//busEntrant : bus qui entre avec les informations
//busSortant : bus contenant les informations recherché sortant de la mémoire

Memoire::Memoire(short int taille) {

	for(unsigned int i=0; i < taille ;i++){
		emplacement_memoire.push_back(5);	//Initialisation de toutes les cases memoires à 0
	}
	if (emplacement_memoire.size()==0){
		std::cout<<"ATTENTION : TAILLE DE LA MÉMOIRE NULLE"<<std::endl;
	}
}

		//Memoire(std::vector<short int> e_m, Bus* bus_e, Bus* bus_s);

Memoire::Memoire(std::vector<short int> e_m, Bus* bus_e, Bus* bus_s): emplacement_memoire(e_m){
	busEntrant.push_back(bus_e);
	busSortant.push_back(bus_s);
	for(unsigned int i=0; i < (getEmplacement_memoire().size());i++){
		getEmplacement_memoire()[i]=0;							//Initialisation de toutes les cases memoires à 0
	}
}


Memoire::Memoire(std::vector<short int> e_m, std::vector<Bus*> bus_e,std::vector<Bus*>bus_s): emplacement_memoire(e_m), busEntrant(bus_e), busSortant(bus_s) {
	for(unsigned int i=0; i < (getEmplacement_memoire().size());i++){
		getEmplacement_memoire()[i]=0;							//Initialisation de toutes les cases memoires à 0
	}
}



Memoire::~Memoire() {
	// TODO Auto-generated destructor stub
}


void Memoire::addBusEntrant(Bus* b){
	busEntrant.push_back(b);
}

void Memoire::supprBusEntrant(Bus* b){
	int verifier = 0;
	int s = busEntrant.size()-1;
	int i = 0;
	while (i != s){
		if (busEntrant[i] == b){
			busEntrant.erase(busEntrant.begin()+i);
			verifier = 1;
		}
		i++;
	}
	if (verifier == 0){
		printf("le bus entrant n'a pas �t� supprim�");
	}

}

void Memoire::addBusSortant(Bus* b){
	busSortant.push_back(b);
}

void Memoire::supprBusSortant(Bus* b){
	int verifier = 0;
	int s = busSortant.size()-1;
	int i = 0;
	while (i != s){
		if (busEntrant[i] == b){
			busSortant.erase(busSortant.begin()+i);
			verifier = 1;
		}
		i++;
	}
	if (verifier == 0){
		printf("le bus sortant n'a pas �t� supprim�");
	}

}
