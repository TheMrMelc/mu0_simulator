/*
 * Instruction.cpp
 *
 *  Created on: 16 avr. 2015
 *      Author: Romain Gobard
 */

#include "../include/Instruction.h"
#include "../include/Memoire.h"
#include <iostream>
//Par contre, pour coder LDA ( et ADD etc...) la mémoire intervient dans les schémas
// du coup je pense qu'il suffit juste de sauvegarder les valeurs dans une variable qui ne sera pas écrasée à la fin


/*IMPORTANT : FAIRE UNE FONCTION QUI RESET LES SIGNAUX A CHAQUE NOUVELLE INSTRUCTION*/

Instruction::Instruction(Microprocesseur* mu0) : mip(mu0) {

}

Instruction::~Instruction() {

}

int Instruction::lda(short int addr, Registre* ACC , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxC, Memoire* mem){	//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxC->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
			break;
		}
	}
	//printf("Envoi du code operande situé dans le registre IR dans la memoire");

	/*Réalisation des transferts de données*/
	mem->setSignal(0);

	//On accède à la mémoire en lecture
	mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(addr));		//On place dans le bus sortant de la memoire la valeur de la case memoire contenue à l'adresse addr
	muxC->fonction();																	//On re aiguille le multiplexeur muxC sur sa 2ème entree
	ACC->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());			//On place dans le bus sortant de ACC la valeur de ACC
	ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());								//On place finalement la valeur du bus sortant de la memoire dans ACC

	return 1;
}

int Instruction::sto(short int addr, Registre* ACC, Registre* IR, Multiplexeur* muxA, Memoire* mem, Porte* p){	//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	p->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);


	/*Envoi du code operande situé dans le registre IR dans la memoire*/

	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
			break;
		}
	}

	/*Réalisation des transferts de données*/
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());
	mem->setValeurEmplacementMemoire(addr,ACC->getBus_sortant()[0]->getValeur());		//On place la valeur contenue dans le bus sortant de ACC dans la memoire à l'adresse addr

	return 1;
}

int Instruction::add(short int addr, Registre* ACC , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual ){//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxB->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){		//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){								//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());				//On le remplit et on sort de la boucle
			break;
		}
	}

	/*Réalisation des transferts de données*/
	mem->setSignal(0);																				//On donne accès à la memoire en lecture
	mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(addr));
	ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());						//On place la valeur contenue dans le bus sortant de la memoire dans le 1er bus de l'ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());											//On place dans le bus sortant de ACC la valeur contenu dans ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());						//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(2);																				//On place le bon code "aluf"
	ual->fonction(ual->getBus_entrant()[0]->getValeur(),ual->getBus_entrant()[1]->getValeur());		//On réalise l'opération "add"
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());											//On place dans le bus sortant de l'ual la valeur de retour de l'opération "add"
	muxC->setSignal(1);
	muxC->fonction();																				//On re aiguille le multiplexeur muxC sur sa 3ème entree
	ACC->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());						//On place la valeur contenu dans le bus sortant de l'ual dans le bus entrant de ACC
	ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());											//On place finalement la valeur du bus entrant de ACC dans ACC


	return 1;
}

int Instruction::sub(short int addr, Registre* ACC , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual ){//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxB->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	//muxA->fonction(3);
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
			break;
		}
	}


	/*Réalisation des transferts de données*/
	muxC->setSignal(1);
	mem->setSignal(0);																//On donne accès à la memoire en lecture
	mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(addr));	//On place la valeur contenue dans la memoire à l'adresse addr dans son bus sortant
	ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());		//On place la valeur contenue dans le bus sortant de la memoire dans le 1er bus de l'ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());							//On place dans le bus sortant de ACC la valeur de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());		//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(1);																//On place le bon code "aluf"
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());	//On réalise l'opération "sub"
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());							//On place dans le bus sortant de l'ual la valeur de retour de l'opération "add"
	muxA->fonction();																//On re aiguille le multiplexeur muxB sur sa 3ème entree
	ACC->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());		//On place dans le bus entrant de ACC
	ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());							//On place finalement la valeur du bus entrant de ACC dans ACC


	return 1;
}


int Instruction::jmp(short int addr,Registre* ACC, Registre* pc , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual ){//Instruction OK ( juste vérifier le contenu de pc)

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux utiles*/
	pc->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxB->setSignal(0);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){		//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){								//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());				//On le remplit et on sort de la boucle
			break;
		}
	}

	/*Réalisation des transferts de données*/
	muxB->fonction();															//On aiguillone correctement le multiplexeur
	IR->getBus_sortant()[0]->setValeur(IR->getValeur());						//On place dans le bus sortant de IR la valeur de IR
	ual->getBus_entrant()[0]->setValeur(IR->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de IR dans le 1er bus de l'ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(0);															//On place le bon code aluf
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());//On fait correspondre la sortie de l'ual avec l'entree B
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération
	pc->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//ON place dans le bus entrant de pc la valeur du bus sortant de ual
	pc->setValeur(pc->getBus_entrant()[0]->getValeur());						//On place dans le pc l'adresse de la prochaine instruction à executer specifie dans la partie operande de IR

	return 1;
}

int Instruction::jne(short int addr, Registre* ACC, Registre* pc , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual ){//Instruction ok (juste vérifier le contenu de pc)

	/*Reset de tous les signaux*/
	resetSignaux();
	if(ACC->getValeur() != 0){

	/*Activation des signaux*/
	pc->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxB->setSignal(0);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){					//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
			break;
		}
	}


	/*Réalisation des transferts de données*/
	muxB->fonction();
	IR->getBus_sortant()[0]->setValeur(IR->getValeur());						//On place dans le bus sortant de IR la valeur de IR
	ual->getBus_entrant()[0]->setValeur(IR->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de IR dans le 1er bus de l'ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(0);															//On place le bon code aluf
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());//On fait correspondre la sortie de l'ual avec l'entree B
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération
	pc->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//ON place dans le bus entrant de pc la valeur du bus sortant de ual
	pc->setValeur(pc->getBus_entrant()[0]->getValeur());						//On place dans le pc l'adresse de la prochaine instruction à executer specifie dans la partie operande de IR

}

	return 1;
}

int Instruction::jge(short int addr, Registre* ACC, Registre* pc , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();

	if(ACC->getValeur() >= 0){

	/*Activation des signaux*/
	pc->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxC->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
			break;
		}
	}


	/*Réalisation des transferts de données*/
	muxC->fonction();
	IR->getBus_sortant()[0]->setValeur(IR->getValeur());						//On place dans le bus sortant de IR la valeur de IR
	mem->setSignal(0);															//On donne ACCès à la memeoire en lecture
	mem->getBus_sortant()[0]->setValeur(mem->getEmplacement_memoire()[addr]);	//On place la valeur contenue dans la memoire à l'adresse addr dans son bus sortant
	ual->getBus_entrant()[0]->setValeur(IR->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de IR dans le 1er bus de l'ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(0);															//On place le bon code aluf
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());//On fait correspondre la sortie de l'ual avec l'entree B
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération
	pc->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//ON place dans le bus entrant de pc la valeur du bus sortant de ual
	pc->setValeur(pc->getBus_entrant()[0]->getValeur());						//On place dans le pc l'adresse de la prochaine instruction à executer specifie dans la partie operande de IR



}


	return 1;
}

void Instruction::stp(void){
	for(unsigned int i=0;i< mip->getComposant().size();i++){					//On parcourt tous les composants et on met leur signal à 0 et leur valeur à 0
		mip->getComposant()[i]->setSignal(0);
		mip->getComposant()[i]->setValeur(0);
	}
}


int Instruction::_and(short int addr, Registre* ACC, Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();

	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxB->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
	muxA->fonction();
	for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){		//Remplissage de la memoire au fur et à mesure
		if((mem->getEmplacement_memoire()[i])==0){								//Si un emplacement est vide
			mem->setValeurEmplacementMemoire(i,IR->getValeur());				//On le remplit et on sort de la boucle
			break;
		}
	}

	/*Réalisation des transferts de données*/
	muxC->setSignal(2);															//On re aiguille le multiplexeur muxC sur sa 2ème sortie
	mem->setSignal(0);															//On donne accès à la memoire en lecture
	mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(addr));//On place la valeur contenue dans la memoire à l'adresse addr dans le bus sortant de la memoire
	ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de la memoire dans le 1er bus de l'ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place la valeur contenue dans ACC dans le bus sortant de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(5);															//On place le bon code "aluf"
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());	//On réalise l'opération "and"
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération "add"
	muxB->fonction();															//On re aiguille le multiplexeur muxB sur sa 3ème entree
	ACC->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur()); //On place dan sle bus entrant de ACC la valeur contenue dans le bus sortant de l'UAL
	ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());						//On place finalement la valeur du bus entrant de ACC dans ACC

	return 1;
}

int Instruction::_or(short int addr, Registre* ACC, Registre* IR,Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Instruction ok

	/*Reset de tous les signaux*/
	resetSignaux();

	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);	//Memoire accessible en ecriture
	muxA->setSignal(3);
	muxB->setSignal(2);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
		muxA->fonction();
		for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
			if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
				mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
				break;
			}
		}


	/*Réalisation des transferts de données*/
		muxC->setSignal(1);															//On re aiguille le multiplexeur muxC sur sa 2ème sortie
		mem->setSignal(0);															//On donne accès à la memoire en lecture
		mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(addr));//On place la valeur contenue dans la memoire à l'adresse addr dans le bus sortant de la memoire
		ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de la memoire dans le 1er bus de l'ual
		ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());
		ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
		ual->setSignal(4);															//On place le bon code "aluf"
		ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());		//On réalise l'opération "or"
		ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération "add"
		muxB->fonction();															//On re aiguille le multiplexeur muxB sur sa 3ème entree
		ACC->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//On pace
		ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());						//On place finalement la valeur du bus entrant de ACC dans ACC



	return 1;
}

int Instruction::_xor(short int addr, Registre* ACC, Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Instruction ok

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);	//Memoire ACCessible en ecriture
	muxA->setSignal(3);
	muxB->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
		muxA->fonction();
		for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
			if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
				mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
				break;
			}
		}


		/*Réalisation des transferts de données*/
		muxC->setSignal(2);															//On re aiguille le multiplexeur muxC sur sa 2ème sortie
		mem->setSignal(0);															//On donne accès à la memoire en lecture
		mem->getBus_sortant()[0]->setValeur(mem->getEmplacement_memoire()[addr]);	//On re aiguille le multiplexeur muxC sur sa 2ème sortie
		ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de la memoire dans le 1er bus de l'ual
		ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
		ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
		ual->setSignal(6);															//On place le bon code "aluf"
		ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[1]->getValeur());		//On réalise l'opération "xor"
		ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération "add"
		muxB->fonction();															//On re aiguille le multiplexeur muxB sur sa 3ème entree
		ACC->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//On place la valeur du bus de sortie de l'ual dans le bus entrant de ACC
		ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());						//On place finalement la valeur du bus entrant de ACC dans ACC



		return 1;

}

int Instruction::rol(short int addr, Registre* ACC, Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Rotation à gauche à revoir

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	ACC->setSignal(1);
	mem->setSignal(1);	//Memoire accessible en ecriture
	muxA->setSignal(3);
	muxB->setSignal(2);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
		muxA->fonction();
		for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
			if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
				mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
				break;
			}
		}


		/*Réalisation des transferts de données*/
		muxC->setSignal(1);															//On re aiguille le multiplexeur muxC sur sa 2ème sortie
		mem->setSignal(0);															//On donne ACCès à la memoire en lecture
		mem->getBus_sortant()[0]->setValeur(mem->getEmplacement_memoire()[addr]);	//On re aiguille le multiplexeur muxC sur sa 2ème sortie
		ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de la memoire dans le 1er bus de l'ual
		ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());
		ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
		ual->setSignal(7);															//On place le bon code "aluf"

		for(int i =0;i<mem->getValeurEmplacementMemoire(addr);i++){
		short int tmp = ual->fonction(ual->getBus_entrant()[0]->getValeur(),ual->getBus_entrant()[1]->getValeur());		//On realise 'addr' fois l'opération "rol"
		ual->fonction(tmp,ual->getBus_entrant()[1]->getValeur());
		}

		ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération "add"
		muxB->fonction();															//On re aiguille le multiplexeur muxB sur sa 3ème entree
		ACC->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//On pace
		ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());						//On place finalement la valeur du bus entrant de ACC dans ACC



		return 1;

}


int Instruction::ldr(short int addr, Registre* ACC, Registre* r , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	r->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxC->setSignal(1);
	/*Envoi du code operande situé dans le registre IR dans la memoire*/
		muxA->fonction();

		for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
			if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
				mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
				break;
			}
		}

	/*Réalisation des transferts de données*/
		muxC->fonction();
		IR->getBus_sortant()[0]->setValeur(IR->getValeur());						//On place dans le bus sortant de IR la valeur de IR
		mem->setSignal(0);															//On donne accès à la memeoire en lecture
		mem->getBus_sortant()[0]->setValeur(mem->getEmplacement_memoire()[addr]);	//On place la valeur contenue dans la memoire à l'adresse addr dans son bus sortant
		ual->getBus_entrant()[0]->setValeur(IR->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de IR dans le 1er bus de l'ual
		ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
		ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
		ual->setSignal(0);															//On place le bon code aluf
		ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());//On fait correspondre la sortie de l'ual avec l'entree B
		ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place dans le bus sortant de l'ual la valeur de retour de l'opération
		r->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());	//ON place dans le bus entrant de pc la valeur du bus sortant de ual
		r->setValeur(r->getBus_entrant()[0]->getValeur());							//On place dans r l'adresse de la prochaine instruction à executer specifie dans la partie operande de IR





	return 1;
}

int Instruction::ldi(short int addr, Registre* ACC, Registre* r , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual){//Instruction ok

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	r->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);
	muxC->setSignal(1);
	ACC->setSignal(1);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
		muxA->fonction();
		for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
			if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
				mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
				break;
			}
		}


	/*Réalisation des transferts de données*/

	//1ère phase
	mem->setSignal(0);																		//On accède à la mémoire en lecture
	mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(r->getValeur()));	//On place dans le bus sortant de la memoire la valeur de la case memoire contenue à l'adresse contenue dans r
	muxC->fonction();																		//On re-aiguille le multiplexeur muxC sur sa 2ème entree
	ACC->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());				//On place dans le bus entrant de ACC la valeur du bus sortant de la mem
	ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());									//On place finalement la valeur du bus sortant de la memoire dans ACC

	//2ème phase
	muxA->setSignal(1);
	muxB->setSignal(0);
	muxA->fonction();
	muxC->fonction();
	r->getBus_sortant()[0]->setValeur(r->getValeur());							//On place la valeur contenue dans r vers le bus sortant de r
	ual->getBus_entrant()[0]->setValeur(r->getBus_sortant()[0]->getValeur());	//On place la valeur du bus sortant de r dans le 1er bus entrant de ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(3);															//On place le bpon code alufs
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());//On réalise l'opération "entreb+1"
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place le résultat dans le bus sortant de l'ual
	r->setValeur(ual->getBus_sortant()[0]->getValeur());						//On place finalement la valeur du bus sortant de l'ual dans r


	return 1;
}
int Instruction::sti(short int addr, Registre* ACC, Registre* r , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual, Porte* p){//Instruction OK

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	r->setSignal(1);
	mem->setSignal(1);
	muxA->setSignal(3);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
			muxA->fonction();
			for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
				if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
					mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
					break;
				}
			}

	/*Réalisation des transferts de données*/

	//1ère phase
	muxA->setSignal(1);
	muxC->setSignal(0);
	muxA->fonction();
	muxC->fonction();
	r->getBus_sortant()[0]->setValeur(r->getValeur() - 1);						//On place l'adresse contenue dans r, décrémenté de 1, vers le bus sortant de r
	ual->getBus_entrant()[0]->setValeur(r->getBus_sortant()[0]->getValeur());	//On place la valeur du bus sortant de r dans le 1er bus entrant de ual
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus sortant de ACC la valeur de ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());	//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(0);															//On place le bon code alufs
	ual->fonction(ual->getBus_entrant()[1]->getValeur(),ual->getBus_entrant()[0]->getValeur());//On réalise l'opération "entreb"
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());						//On place le résultat dans le bus sortant de l'ual
	r->setValeur(ual->getBus_sortant()[0]->getValeur());						//On place finalement la valeur du bus sortant de l'ual dans r

	//2ème phase
	p->setSignal(1);															//On active la porte
	mem->setSignal(1);															//On accede a la memoire en ecriture
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());						//On place dans le bus de sortie de ACC la valeur de ACC
	mem->setValeurEmplacementMemoire(r->getValeur(), ACC->getBus_sortant()[0]->getValeur());//On place la valeur contenue dans le bus sortant de ACC dans la memoire à l'adresse contenue dans r

	return 1;
}


int Instruction::xpc(short int addr, Registre* ACC,Registre* pc, Porte* p , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC ,Memoire* mem, UAL* ual){//Instruction ok

	/*Reset de tous les signaux*/
	resetSignaux();
	/*Activation des signaux*/
	p->setSignal(1);
	pc->setSignal(1);
	ACC->setSignal(1);
	muxA->setSignal(3);

	/*Envoi du code operande situé dans le registre IR dans la memoire*/
			muxA->fonction();
			for(unsigned int i=0;i < (mem->getEmplacement_memoire().size());i++){	//Remplissage de la memoire au fur et à mesure
				if((mem->getEmplacement_memoire()[i])==0){							//Si un emplacement est vide
					mem->setValeurEmplacementMemoire(i,IR->getValeur());			//On le remplit et on sort de la boucle
					break;
				}
			}

	/*Réalisation des transferts de données*/

			//1ère phase
	pc->getBus_sortant()[0]->setValeur(pc->getValeur());							//A faire avant de modifier la valeur du pc pour ne pas perdre les donnees

	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());							//On place dans le bus sortant de ACC la valeur contenue dans ACC
	muxB->setSignal(1);
	muxB->fonction();																//On re aiguille le multiplexeur muxB sur sa 2ème entree
	mem->getBus_sortant()[0]->setValeur(mem->getValeurEmplacementMemoire(addr));	//On place la valeur contenue dans la memoire à l'adresse addr dans son bus sortant
	ual->getBus_entrant()[0]->setValeur(mem->getBus_sortant()[0]->getValeur());		//On place dans le 1er bus entrant de ual la valeur contenue dans le bus sortant de la memoire
	ACC->getBus_sortant()[0]->setValeur(ACC->getValeur());							//On place dans le bus sortant de ACC la valeur contenue dans ACC
	ual->getBus_entrant()[1]->setValeur(ACC->getBus_sortant()[0]->getValeur());		//On place la valeur contenue dans le bus sortant de ACC dans le 2ème bus entrant de l'ual
	ual->setSignal(0);																			//On place le bon code "aluf"
	ual->fonction(ual->getBus_entrant()[0]->getValeur(),ual->getBus_entrant()[1]->getValeur());	//On fait correspondre la sortie avec l'entree B
	ual->getBus_sortant()[0]->setValeur(ual->getValeur());										//On place le résultat dans le bus sortant de l'ual
	pc->getBus_entrant()[0]->setValeur(ual->getBus_sortant()[0]->getValeur());					//On place dans le bus entrant de pc la valeur du bus sortant de ual
	pc->setValeur(pc->getBus_entrant()[0]->getValeur());										//On place dans pc la valeur contenue dans son bus entrant

			//2ème phase
	muxA->setSignal(0);
	muxC->setSignal(0);
	muxA->fonction();															//On aiguille le multiplexeur muxA sur sa 1ere entree
	muxC->fonction();															//On aiguille le multiplexeur muxB sur sa 1ere entree
	ACC->getBus_entrant()[0]->setValeur(pc->getBus_sortant()[0]->getValeur());	//On place dans le bus entrant de ACC la valeur du bus sortant de pc
	ACC->setValeur(ACC->getBus_entrant()[0]->getValeur());						//On place finalement la valeur du bus entrant de ACC dans ACC

	return 1;
}

void Instruction::resetSignaux(void){
		for(unsigned int i=0;i< mip->getComposant().size();i++){					//On parcourt tous les composants et on met leur signal à 0
		mip->getComposant()[i]->setSignal(0);
	}

}
