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
	
	/***Initialisation du microP mu0***/
	std::vector<Composant*> composants;
	Mu0* mu0 = new Mu0(composants);

	/***Zone de déclaration des instructions***/

	short int a = 15;							//Par la suite, a est utilisé comme adresse pour la memoire : on fera des accès sur la 15 eme case de la memoire
	mu0->findComposant("ACC")->setValeur(0x2);	//On initialise le registre ACC avec une valeur quelconque
	mu0->findComposant("IR")->setValeur(0x10);	//On initialise le registre IR avec une adresse quelconque


	/*mu0->getInstruction()->lda(
			a,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			(Multiplexeur*)mu0->findComposant("muxC"),
			mu0->getMemoire()
			);*/

	/*std::cout <<"la 15eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(a) << std::endl;*/
	/*mu0->getInstruction()->sto(a,
			(Registre*)mu0->findComposant("ACC"),
			(Registre*)mu0->findComposant("IR"),
			(Multiplexeur*)mu0->findComposant("muxA"),
			mu0->getMemoire(),
			(Porte*)mu0->findComposant("Porte"));

	std::cout <<"la 15eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(a) << std::endl;*/ //Permet de bien voir le changement de valeur dans la memoire

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


	//mu0->findComposant("R")->setValeur(13);
	/*std::cout <<"la 15eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(a) << std::endl;*/

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
	/*std::cout <<"la 15eme case memoire vaut " << mu0->getMemoire()->getValeurEmplacementMemoire(a) << std::endl;*/ // Permet de bien voir les changements dans la memoire


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


	/*****Initialistation de l'interface graphique*****/
	//InterfaceGraphique* inter = new InterfaceGraphique(mu0);
	/*Lancement*/
	//inter->execute(mu0);


	return 0;
}

