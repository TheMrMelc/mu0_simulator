/*
 * Registre.h
 *
 *  Created on: 10 avr. 2015
 *      Author: mailis
 *resume de la classe mere composant :

 attributs :
		nbEntree
		nbSortie
		signal
		valeur
		actif
		bus entrants
		bus sortants

methodes :
		activer
		desactiver
		fonction
 */

#ifndef REGISTRE_H_
#define REGISTRE_H_

#include "Composant.h"


class Registre : public Composant{


public:
	///////////////////////////////////// attributs /////////////////////////////////////
	///////////////////////////////////// constructeurs /////////////////////////////////////
	Registre(std::string,int,int,std::string, short int, short int, bool);
	Registre(std::string,int, int,std::string, short int, short int, bool, Bus*, Bus*);
	Registre(std::string,int, int, std::string,short int, short int, bool, std::vector<Bus*>, std::vector<Bus*>);
	///////////////////////////////////// destructeurs /////////////////////////////////////
	virtual ~Registre(void);
	///////////////////////////////////// methodes /////////////////////////////////////////
	void fonction(short int);

};


#endif /* REGISTRE_H_ */
