/*
 * Memoire.h
 *
 *  Created on: 2015-05-02
 *      Author: romain
 */

#ifndef MEMOIRE_H_
#define MEMOIRE_H_

#include <vector>
#include "Bus.h"



class Memoire {

protected :

	std::vector<short int> emplacement_memoire;	//Gestion des cases mémoires nécessaires pour le simulateur

	std::vector<Bus*> busEntrant;				//Gestion des bus entrants et sortants
	std::vector<Bus*> busSortant;
	short int signal;


public:
	Memoire(short int e_m);
	Memoire(std::vector<short int> e_m, Bus* bus_e,Bus* bus_s);
	Memoire(std::vector<short int> e_m, std::vector<Bus*> bus_e,std::vector<Bus*>bus_s);
	virtual ~Memoire(void);

	//ajout et suppressio des bus entrants
	void addBusEntrant(Bus*);
    void supprBusEntrant(Bus*);

    //ajout et suppression des bus sortants
    void addBusSortant(Bus*);
    void supprBusSortant(Bus*);

    //Accès aux attributs
    std::vector<short int> getEmplacement_memoire(void){ return emplacement_memoire;}
    short int getValeurEmplacementMemoire(short int addr){ return emplacement_memoire[addr];}
    void setValeurEmplacementMemoire(short int addr, short int val){emplacement_memoire[addr]=val;}
    std::vector<Bus*> getBus_entrant(void){ return busEntrant;}
    std::vector<Bus*> getBus_sortant(void){ return busSortant;}

    void setSignal(short int a){signal=a;}
};

#endif /* MEMOIRE_H_ */
