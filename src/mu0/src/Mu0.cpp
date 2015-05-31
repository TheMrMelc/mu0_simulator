/*
 * Mu0.cpp
 *
 *  Created on: 2015-05-15
 *      Author: mailis et  romain
 */

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

#include "Mu0.h"
//#include "Instruction.h"

static int __lda(short int addr, Mu0 *mu0){
	int retour = mu0->getInstruction()->lda(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			mu0->getMemoire()
			);
	return retour;

}

static int __sto(short int addr, Mu0* mu0 ){
	Instruction* i = mu0->getInstruction();
	return i->sto(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			mu0->getMemoire(),
			(Porte*)mu0->findComposant("Porte")
			);
}

static int __add(short int addr,  Mu0 *mu0){
	Instruction* i = mu0->getInstruction();
	return i->add(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}

static int __sub(short int addr,   Mu0 *mu0){
	return mu0->getInstruction()->sub(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}

static int __jmp(short int addr,   Mu0 *mu0){
	return mu0->getInstruction()->jmp(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("PC") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}

static int __jne(short int addr,   Mu0* mu0){
	return mu0->getInstruction()->jne(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("PC") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}

static int __jge(short int addr,  Mu0 *mu0){
	return mu0->getInstruction()->jge(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("PC") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}

static int __stp(short int addr,  Mu0* mu0){
	mu0->getInstruction()->stp();
	return 1;
}


static int __and(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->_and(
			addr,
			(Registre*)mu0->findComposant("ACC") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}


static int __or(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->_or(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}


static int __xor(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->_xor(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}


static int __rol(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->rol(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}


static int __ldr(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->ldr(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("R") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}


static int __ldi(short int addr,  Mu0 *mu0){
	return mu0->getInstruction()->ldi(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("R") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}


static int __sti(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->sti(
			addr,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("R") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual"),
			(Porte*)mu0->findComposant("Porte")
			);
}


static int __xpc(short int addr,  Mu0* mu0){
	return mu0->getInstruction()->xpc(
			addr,
			(Registre*)mu0->findComposant(	"ACC"),
			(Registre*)mu0->findComposant("PC"),
			(Porte*)mu0->findComposant("Porte") ,
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("ual")
			);
}



// def structure d'un mnemo (lettre + insctriction)
typedef struct mneno {
	char *mnemo;
	int(*exec)(short int addr, Mu0* mu0);
} Mnemo;


//liste des mnémoniques et des fonctions associées
static Mnemo ListMnemo[]=
{
		{
				"LDA",
				__lda,
		},
		{
				"STO",
				__sto,
		},
		{
				"ADD",
				__add,
		},
		{
				"SUB",
				__sub,
		},
		{
				"JMP",
				__jmp,
		},
		{
				"JGE",
				__jge,
		},
		{
				"JNE",
				__jne,
		},
		{
				"STP",
				__stp,
		},
		{
				"AND",
				__and,
		},
		{
				"OR",
				__or,
		},
		{
				"XOR",
				__xor,
		},
		{
				"ROL",
				__rol,
		},
		{
				"LDR",
				__ldr,
		},
		{
				"LDI",
				__ldi,
		},
		{
				"STI",
				__sti,
		},
		{
				"XPC",
				__xpc,
		},


		{
				NULL,
				NULL,
		},
};


static Mnemo *findMnemo(char *lib)
{
	printf("mon mnemo recherché est :'/%s'", lib);
	Mnemo *item = ListMnemo;
	while(item->mnemo != NULL) {
		if (strcmp(item->mnemo, lib)==0) {
			return item;
		}
		item++;
	}
	return NULL;
}

Mu0::Mu0(std::vector<Composant*> cMu0) : Microprocesseur(cMu0) {
	        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////// les registres//////////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			/*Selon le modèle Registre(Nom du registre, nombre d'entree, nombre de sortie, nom du signal, le signal, la valeur, l'activité);*/

			Registre* PC= new Registre("PC", 1, 1,"pc_id", 0, 0, 0);
			Registre* R = new Registre("R",1, 1,"r_id", 0, 0, 0);
			Registre* IR = new Registre("IR",1, 1,"ir_id", 0, 0, 0);
			Registre* ACC = new Registre("ACC",1, 1,"acc_id", 0, 0, 0);

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////les Multiplexeurs///////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Selon le modèle Multiplexeur(Nom du multiplexeur, nombre d'entree, nombre de sortie, nom du signal, le signal, la valeur, l'activité)
			Multiplexeur* muxA = new Multiplexeur("muxA", 4, 1,"sel_A", 0, 0, false);
			Multiplexeur* muxB = new Multiplexeur("muxB", 2, 1,"sel_B", 0, 0, false);
			Multiplexeur* muxC = new Multiplexeur("muxC", 3, 1,"sel_C", 0, 0, false);

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////la porte///////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//Selon le modèle Porte(Nom de la porte, nombre d'entree, nombre de sortie, nom du signal, le signal, la valeur, l'activité)
			Porte* porte = new Porte("Porte",1, 1,"acc_oe", 0, 0, false);


			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////l'ual///////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//Selon le modèle UAL (Nom de l'UAL, nombre d'entree, nombre de sortie, nom du signal, le signal, la valeur, l'activité)
			UAL* ual = new UAL("UAL", 2, 1,"alufs", 0, 0, false);


			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////L'emplacement memoire////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//short int e_m;


			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////la mémoire///////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			Memoire* mem = new Memoire(16);
			this->setMemoire(mem);


			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////les instructions///////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			Instruction* instruction = new Instruction(this);
			this->setInstruction(instruction);


			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////les bus///////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			// nom des bus : bus_DEPART_ARRIVE


			Bus* bus_PC_muxA = new Bus(12,0, false);

			Bus* bus_IR_muxA = new Bus(12,0, false);

			Bus* bus_R_muxA = new Bus(12,0, false);
			Bus* bus_R1_muxA = new Bus(12,0, false);

			Bus* bus_muxB_ual = new Bus(6, 0, false); 	 //1er bus de UAL
			Bus* bus_ACC_porte = new Bus(16, 0, false);

			Bus* bus_ual_R = new Bus(16, 0, false);
			Bus* bus_ual_PC = new Bus(16, 0, false);
			Bus* bus_ual_muxC = new Bus(16, 0, false);


			Bus* bus_muxA_mem = new Bus(12, 0, false) ;
			Bus* bus_muxA_muxB = new Bus(12, 0, false);
			Bus* bus_muxA_muxC= new Bus(12, 0, false);

			Bus* bus_ACC_ual = new Bus(16, 0, false);	//2eme bus de ual

			Bus* bus_muxC_ACC = new Bus(16, 0, false) ;

			Bus* bus_porte_muxB = new Bus(16, 0, false);
			Bus* bus_porte_muxC = new Bus(16, 0, false);
			Bus* bus_porte_IR = new Bus(16, 0, false);
			Bus* bus_porte_mem = new Bus(16, 0, false);

			Bus* bus_mem_muxB = new Bus(16, 0, false);
			Bus* bus_mem_muxC = new Bus(16, 0, false);
			Bus* bus_mem_IR  = new Bus(16, 0, false);
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////ajout des bus sortant/////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			PC->addBusSortant(bus_PC_muxA);

			IR->addBusSortant(bus_IR_muxA);

			R->addBusSortant(bus_R_muxA);
			R->addBusSortant(bus_R1_muxA);

			ACC->addBusSortant(bus_ACC_ual);
			ACC->addBusSortant(bus_ACC_porte);

			ual->addBusSortant(bus_ual_PC);
			ual->addBusSortant(bus_ual_R);
			ual->addBusSortant(bus_ual_muxC);

			muxA->addBusSortant(bus_muxA_mem);
			muxA->addBusSortant(bus_muxA_muxB);
			muxA->addBusSortant(bus_muxA_muxC);

			muxB->addBusSortant(bus_muxB_ual);

			muxC->addBusSortant(bus_muxC_ACC);

			porte->addBusSortant(bus_porte_muxB);
			porte->addBusSortant(bus_porte_muxC);
			porte->addBusSortant(bus_porte_IR);
			porte->addBusSortant(bus_porte_mem);

			mem->addBusSortant(bus_mem_muxB);
			mem->addBusSortant(bus_mem_muxC);
			mem->addBusSortant(bus_mem_IR);

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////ajout des bus entrants/////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			muxA->addBusEntrant(bus_PC_muxA);

			muxA->addBusEntrant(bus_IR_muxA);

			muxA->addBusEntrant(bus_R_muxA);
			muxA->addBusEntrant(bus_R1_muxA);

			ual->addBusEntrant(bus_muxB_ual);		//1er bus de ual
			ual->addBusEntrant(bus_ACC_ual);		//2ème bus de ual

			porte->addBusEntrant(bus_ACC_porte);

			PC->addBusEntrant(bus_ual_PC);
			R->addBusEntrant(bus_ual_R);
			muxC->addBusEntrant(bus_ual_muxC);

			mem->addBusEntrant(bus_muxA_mem);
			muxB->addBusEntrant(bus_muxA_muxB);
			muxC->addBusEntrant(bus_muxA_muxC);



			ACC->addBusEntrant(bus_muxC_ACC);

			muxB->addBusEntrant(bus_porte_muxB);
			muxC->addBusEntrant(bus_porte_muxC);
			IR->addBusEntrant(bus_porte_IR);
			mem->addBusEntrant(bus_porte_mem);

			muxB->addBusEntrant(bus_mem_muxB);
			muxC->addBusEntrant(bus_mem_muxC);
			IR->addBusEntrant(bus_mem_IR);


			ajouterComposant(PC);
			ajouterComposant(IR);
			ajouterComposant(R);
			ajouterComposant(ACC);
			ajouterComposant(muxA);
			ajouterComposant(muxB);
			ajouterComposant(muxC);
			ajouterComposant(porte);
			ajouterComposant(ual);

}

Mu0::~Mu0() {

}
void Mu0::decodeExecute(void){

	char instruction[8];
	char* morceau;
	char* tok;
	char *s;
	Mnemo *m;
	std::vector <char*> coupeInstruction;

	//demander une instruction via terminal OK
	printf("Donner une instruction (exemple : LDA addr)\n");
	fgets (instruction, sizeof(instruction), stdin);
	if ((s = strchr(instruction,'\n')) != NULL) {
		*s='\0';
	}


	/*cout << "Donner une instruction (exemple : LDA addr)" << endl;
	string instruction;
	cin >> instruction;*/



	//////////////////////////////////////////////////////////////////////////////////////////////////////////////// coupe de mon instruction


	morceau = strtok_r (instruction," ", &tok);

	while (morceau != NULL){
		coupeInstruction.push_back(morceau);
		//printf("taille de mon instruction coupée : %d ,  '%s' \n", coupeInstruction.size(), morceau);
		morceau = strtok_r (NULL, " ", &tok);
		printf("%p\n", morceau);
		}


	//bon et maintenant c'est quoi cette instruction ?

	printf ("instruction demandée : '%s'\n",coupeInstruction[0]);


	m = findMnemo(coupeInstruction[0]);
	printf(" \n mon mnemo demandé est : '%s'", m);
	if (m != NULL) {
		printf("\n mnemo reconnnu : '%s' ", m->mnemo);
		if (m->exec != NULL) {
			m->exec(coupeInstruction.size()>1?atoi(coupeInstruction[1]):0, this);
		}
	}
}
