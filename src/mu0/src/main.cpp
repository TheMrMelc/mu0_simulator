/*
 * main.cpp
 *
 *  Created on: 2015-05-06
 *      Author: romain et mailis
 */


#include "../include/InterfaceGraphique.h"
#include "../include/Mu0.h"
#include <stdio.h>
#include <iostream>



int main(void){
	
	///////initialisation du microP mu0///////////
	std::vector<Composant*> composants;
	Mu0* mu0 = new Mu0(composants);
	short int a = 15;
	/*mu0->getInstruction()->lda(
			a,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire()
			);*/

	mu0->findComposant("ACC")->setValeur(1);
	mu0->findComposant("IR")->setValeur(10);

	//std::cout <<"La valeur de ACC avant le STO est de " << mu0->findComposant("ACC")->getValeur() << std::endl;

	/*mu0->getInstruction()->sto(10,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			mu0->getMemoire(),
			(Porte*)mu0->findComposant("Porte"));

	/*std::cout <<"La valeur de ACC APRESl le STO est de " << mu0->findComposant("ACC")->getValeur() << std::endl;
	std::cout <<"la 15eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(a) << std::endl;
	std::cout <<"la 10eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(10) << std::endl;*/


	/*mu0->getInstruction()->add(
			a,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxB"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire(),
			(UAL*)mu0->findComposant("UAL")
			);*/

	/*mu0->getInstruction()->sub(
				a,
				(Registre*)mu0->findComposant("ACC"),
				(Registre*)mu0->findComposant("IR"),
				(Multiplexeur*)mu0->findComposant("muxA"),
				(Multiplexeur*)mu0->findComposant("muxB"),
				(Multiplexeur*)mu0->findComposant("muxC"),
				mu0->getMemoire(),
				(UAL*)mu0->findComposant("UAL")
				);*/

	//(short int addr,Registre* ACC, Registre* pc , Registre* IR, Multiplexeur* muxA, Multiplexeur* muxB, Multiplexeur* muxC, Memoire* mem, UAL* ual ){
	/*mu0->getInstruction()->jmp(
					a,
					(Registre*)mu0->findComposant("ACC"),
					(Registre*)mu0->findComposant("PC"),
					(Registre*)mu0->findComposant("IR"),
					(Multiplexeur*)mu0->findComposant("muxA"),
					(Multiplexeur*)mu0->findComposant("muxB"),
					(Multiplexeur*)mu0->findComposant("muxC"),
					mu0->getMemoire(),
					(UAL*)mu0->findComposant("UAL")
					);*/

	/*mu0->getInstruction()->jne(
						a,
						(Registre*)mu0->findComposant("ACC"),
						(Registre*)mu0->findComposant("PC"),
						(Registre*)mu0->findComposant("IR"),
						(Multiplexeur*)mu0->findComposant("muxA"),
						(Multiplexeur*)mu0->findComposant("muxB"),
						(Multiplexeur*)mu0->findComposant("muxC"),
						mu0->getMemoire(),
						(UAL*)mu0->findComposant("UAL")
						);*/

	mu0->getMemoire()->setValeurEmplacementMemoire(a,3);
	std::cout <<"la 15eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(a) << std::endl;
	std::cout <<"La valeur de ACC avant le STO est de " << mu0->findComposant("ACC")->getValeur() << std::endl;

	/*->getInstruction()->jge(
							a,
							(Registre*)mu0->findComposant("ACC"),
							(Registre*)mu0->findComposant("PC"),
							(Registre*)mu0->findComposant("IR"),
							(Multiplexeur*)mu0->findComposant("muxA"),
							(Multiplexeur*)mu0->findComposant("muxB"),
							(Multiplexeur*)mu0->findComposant("muxC"),
							mu0->getMemoire(),
							(UAL*)mu0->findComposant("UAL")
							);*/

	/*mu0->getInstruction()->_and(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/


	/*mu0->getInstruction()->_or(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/

	/*mu0->getInstruction()->_xor(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/

	/*mu0->getInstruction()->rol(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/

	/*mu0->getInstruction()->ldr(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("R"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/
	/*mu0->getInstruction()->ldi(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("R"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/

	mu0->findComposant("R")->setValeur(13);
	/*mu0->getInstruction()->sti(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("R"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL"),
								(Porte*)mu0->findComposant("Porte")
								);*/
	std::cout <<"La valeur de ACC avant xpc est " << mu0->findComposant("ACC")->getValeur() << std::endl;
	std::cout <<"La valeur de PC avant xpc est " << mu0->findComposant("PC")->getValeur() << std::endl;

	/*mu0->getInstruction()->xpc(
								a,
								(Registre*)mu0->findComposant("ACC"),
								(Registre*)mu0->findComposant("PC"),
								(Porte*)mu0->findComposant("Porte"),
								(Registre*)mu0->findComposant("IR"),
								(Multiplexeur*)mu0->findComposant("muxA"),
								(Multiplexeur*)mu0->findComposant("muxB"),
								(Multiplexeur*)mu0->findComposant("muxC"),
								mu0->getMemoire(),
								(UAL*)mu0->findComposant("UAL")
								);*/


	///////initialistation de l'interface graphique////////
	InterfaceGraphique* inter = new InterfaceGraphique(mu0);
	//lancement
	inter->execute(mu0);


	return 0;
}

