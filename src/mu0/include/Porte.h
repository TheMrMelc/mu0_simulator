/*
 * Porte.h
 *
 *  Created on: 16 avr. 2015
 *      Author: Romain Gobard
 */

#ifndef PORTE_H_
#define PORTE_H_


#include "Bus.h"
#include "Composant.h"


class Porte : public Composant{
public:
	Porte(std::string nc, int nombreEntree, int nombreSortie,std::string ns, short int sig, short int val, bool activite, Bus* busEntrant, Bus* busSortant);
	Porte(std::string nc, int nombreEntree, int nombreSortie,std::string ns, short int sig, short int val, bool activite);
	virtual ~Porte();
};

#endif /* PORTE_H_ */
