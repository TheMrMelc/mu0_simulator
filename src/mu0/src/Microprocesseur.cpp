/*
 * Microprocesseur.cpp
 *
 *  Created on: 16 avr. 2015
 *      Author: Maïlis Cohen Romain Gobard
 */

#include "../include/Microprocesseur.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>



Microprocesseur::Microprocesseur(std::vector <Composant*> c) : composant(c){
}

Microprocesseur::~Microprocesseur(void){}

void Microprocesseur::ajouterComposant(Composant* c){
	composant.push_back(c);
}

Composant* Microprocesseur::findComposant(char* nomComposant){
	Composant* composantGagnant = NULL;
	std::cout<< "Nom Composant : " << nomComposant<< std::endl;
	std::cout<< "Nb comp : " << composant.size() << std::endl;
	for (unsigned int i = 0; i<composant.size(); i++){
		if(strcmp((getComposant()[i]->getNomComposant()).c_str(),nomComposant)==0){
			composantGagnant = getComposant()[i];
			std::cout<<"composant trouvé : "<< nomComposant <<std::endl<<std::endl;
			break;
		}

	std::cout<< "composant gagnant : "<< composantGagnant <<std::endl;
	}
	return composantGagnant;
}
