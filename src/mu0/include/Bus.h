/*
 * Bus.h
 *
 *  Created on: 2 avr. 2015
 *      Author: mailis
 */

#ifndef BUS_H_
#define BUS_H_

#include "Composant.h"
#include <vector>

class Composant;

class Bus {
private:
	///////////////////////////////////// attributs /////////////////////////////////////

    short int taille;
    short int valeur;
    bool actif;

public:
	///////////////////////////////////// constructeurs /////////////////////////////////////

    Bus(short int, short int, bool);

	///////////////////////////////////// destructeurs /////////////////////////////////////
	virtual ~Bus();
	///////////////////////////////////// methodes ///////////////////////////////////////
	void activer(void){actif = true;}
	void desactiver(void){actif = false;}
	///////////////////////////////////// get ////////////////////////////////////////
	short int getTaille(void){return taille;}
	short int getValeur(void){return valeur;}
	bool getActif(void){return actif;}
	///////////////////////////////////// set ////////////////////////////////////////
	void setTaille(short int t){taille= t;}
	void setValeur(short int v){valeur= v;}

};

#endif /* BUS_H_ */
