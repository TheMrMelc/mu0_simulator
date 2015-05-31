/** author : Ma�lis
//Date : 16/12/2015

//fichier Composant.h

//r�sum� de la classe :

// attributs :
* 		nomComposant
//		nbEntree
//		nbSortie
//		signal
* 		nomSignal
//		valeur
//		actif
//		bus entrants
//		bus sortants

//m�thodes :
//		activer
//		desactiver
//		fonction
*/
#ifndef COMPOSANT_H
#define COMPOSANT_H


#include "Bus.h"
#include <vector>
#include <stdio.h>
#include <string>

class Bus;

class Composant {

  protected :
///////////////////////////////////// attributs /////////////////////////////////////
	
	std::string nomComposant;

	//nombre d'entree du composant
	int nbEntree;

	//nombre de sortie du composant
	int nbSortie;
	
	//signal du composant
	std::string nomSignal;
	short int signal;
	

	//valeur du composant
	short int valeur;

	// est ce que le composant est actif ? (n�cessaire pour l IHM)
    bool actif;

    // liste des bus entrant du composant
    std::vector<Bus*> busEntrant;

    //liste des bus sortant du composant
    std::vector<Bus*> busSortant;

  public :
///////////////////////////////////// constructeurs /////////////////////////////////////

    // constructeur sans les bus
    Composant(std::string,int , int,std::string, short int, short int, bool);

    // avec un seul bus
    Composant(std::string,int , int,std::string, short int, short int, bool, Bus*, Bus*);
    // avec une liste de bus

    Composant(std::string,int , int,std::string, short int, short int, bool, std::vector<Bus*>,std::vector<Bus*> );

    //Composant(void);

///////////////////////////////////// destructeurs /////////////////////////////////////
    virtual ~Composant(void);

///////////////////////////////////// methodes /////////////////////////////////////////

    //activation du composant
    void activer(void){actif = true;}

    //desactivation du composant
    void desactiver(void){actif = false;}

    // fonction effecti� par le composant (d�finie dans les classes filles)
    virtual void fonction(void);

/////////////////////////////////////// Bus //////////////////////////////////////////

    //ajout et suppressio des bus entrants
    void addBusEntrant(Bus*);
    void supprBusEntrant(Bus*);

    //ajout et suppression des bus sortants
    void addBusSortant(Bus*);
    void supprBusSortant(Bus*);

///////////////////////////////////// get ////////////////////////////////////////
    int getNbSortie(void){return nbSortie;}
    int getNbEntree(void){return nbEntree;}
    short int getSignal(void){return signal;}
    short int getValeur(void){return valeur;}
    bool getActif(void){return actif;}
    std::vector<Bus*> getBus_entrant(void){ return busEntrant;}
    std::vector<Bus*> getBus_sortant(void){ return busSortant;}
    std::string getNomComposant(void){ return nomComposant;}
    std::string getNomSignal(void){ return nomSignal;}
	void resetSignal(void){signal=0;}

///////////////////////////////////// set ////////////////////////////////////////

    void setNbSortie(int newNb){nbSortie = newNb;}
    void setNbEntree(int newNb){nbEntree = newNb;}
    void setSignal(short int newSig){signal = newSig;}
    void setValeur(short int newVal){valeur = newVal;}

};

#endif
