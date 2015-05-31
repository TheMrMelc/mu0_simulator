/*
 * Microprocesseur.h
 *
 *  Created on: 16 avr. 2015
 *      Author: Maïlis Cohen et Romain Gobard
 */

#ifndef MICROPROCESSEUR_H_
#define MICROPROCESSEUR_H_


#include <vector>
#include <string.h>
//#include "Registre.h"
//#include "Multiplexeur.h"

#include "Instruction.h"

class Instruction;
class Microprocesseur {

private :
	std::vector<Composant*> composant;		//Ensemble des composants du microprocesseur
	Instruction* instruction;				//Ensemble des instructions du microprocesseur
	Memoire* memoire;

public:

	/*Constructeur et Destructeur*/
	Microprocesseur(std::vector <Composant*> c);
	virtual ~Microprocesseur(void);

	/*Gestion des composants et des instructions*/
	void ajouterComposant(Composant* c);


	std::vector<Composant*> getComposant(void){ return composant;}
	Instruction* getInstruction(void){return instruction;}
	Memoire* getMemoire(void){return memoire;}

	void setInstruction(Instruction* newI){instruction = newI;}
	void setMemoire(Memoire* newM){memoire = newM;}

	/* récupérer une instruction et l'exécuter*/
	virtual void decodeExecute(void){};

	/*Fonction qui permet de retrouver une instruction dans le vector instruction*/
	Composant* findComposant(char* nomComposant);


};

#endif /* MICROPROCESSEUR_H_ */
