/*
 * Instruction.h
 *
 *  Created on: 16 avr. 2015
 *      Author: Romain Gobard
 */

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "Registre.h"
#include "Multiplexeur.h"
#include "UAL.h"
#include "Porte.h"
#include "Memoire.h"
#include "Microprocesseur.h"

class Microprocesseur;		//Déclaration avancée à la place de 'include "Microprocesseur.h"' pour éviter l'erreur "was not declared in this scope"


class Instruction {

private :
	Microprocesseur* mip;	//Association avec Microprocesseur

public :
	Instruction(Microprocesseur* mu0);
	//virtual
	~Instruction();


	/*M�thodes*/		//Liste des instructions du Mu0 utilis�es par le microprocesseur

	int lda(short int addr, Registre* acc , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Memoire* mem);

	int sto(short int addr, Registre* acc, Registre* IR, Multiplexeur* muxA, Memoire* mem, Porte* p);

	int add(short int addr, Registre* acc , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual );

	int sub(short int addr, Registre* acc , Registre* IR, Multiplexeur* m1, Multiplexeur* m2, Multiplexeur* m3, Memoire* mem, UAL* ual);

	int jmp(short int addr,Registre* acc, Registre* pc , Registre* IR, Multiplexeur* m1, Multiplexeur* m2, Multiplexeur* m3, Memoire* mem, UAL* ual );

	int jne(short int addr, Registre* acc, Registre* pc , Registre* IR, Multiplexeur* m1, Multiplexeur* m2, Multiplexeur* m3, Memoire* mem, UAL* ual);

	int jge(short int addr, Registre* acc, Registre* pc , Registre* IR, Multiplexeur* m1, Multiplexeur* m2, Multiplexeur* m3, Memoire* mem, UAL* ual);

	void stp(void);

	int _and(short int addr, Registre* acc, Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual);

	int _or(short int addr, Registre* acc, Registre* IR,Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual);

	int _xor(short int addr, Registre* acc, Registre* IR, Multiplexeur* m1, Multiplexeur* m2, Multiplexeur* m3, Memoire* mem, UAL* ual);

	int rol(short int addr, Registre* acc, Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual);

	int ldr(short int addr, Registre* acc, Registre* r , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual);

	int ldi(short int addr, Registre* acc, Registre* r , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual);

	int sti(short int addr, Registre* acc, Registre* r , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual, Porte* p);

	int xpc(short int addr, Registre* ACC,Registre* pc, Porte* p , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC ,Memoire* mem, UAL* ual);


};


#endif /* INSTRUCTION_H_ */
