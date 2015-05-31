//author : Ma�lis
//Date : 8/04/2015

//fichier UAL.cpp

#define SHORT_INT_BITS 16

#include "../include/UAL.h"

UAL::UAL(std::string nc,int _nbEntree, int _nbSortie,std::string ns, short int _signal, short int _valeur, bool _actif):
Composant(nc,_nbEntree, _nbSortie, ns,_signal, _valeur, _actif){}

UAL::UAL(std::string nc,int _nbEntree, int _nbSortie,std::string ns, short int _signal, short int _valeur, bool _actif,Bus* _busEntrant, Bus*_busSortant):
Composant(nc,_nbEntree, _nbSortie, ns,_signal, _valeur, _actif,  _busEntrant, _busSortant){}

UAL::UAL(std::string nc,int _nbEntree, int _nbSortie,std::string ns, short int _signal, short int _valeur, bool _actif, std::vector<Bus*> _busEntrant, std::vector<Bus*>_busSortant):
Composant(nc,_nbEntree, _nbSortie,ns,  _signal, _valeur, _actif,  _busEntrant, _busSortant){}



short int UAL::fonction(short int entreA, short int entreB){

	short int sig = getSignal();

	// sortie = B
	if (sig == 0){
			setValeur(entreB);
	}
	// sortie = A-B
	if (sig == 1){
			setValeur(entreA-entreB);
	}
	// sortie = A+B
	if (sig == 2){
			setValeur(entreA+entreB);
	}
	// sortie = B + 1 
	if (sig == 3){
			setValeur(entreB+1);
	}
	// sortie = A ou B
	if (sig == 4){
			setValeur(entreA | entreB);
	}
	// sortie = A et B
	if (sig == 5){
			setValeur(entreA & entreB);
	}
	// sortie = A XOR B
	if (sig == 6){
		setValeur(entreA^entreB);
	}
	// sortie = rotation gauche de A nB fois
	if (sig == 7){
			setValeur( (entreA << 1) | (entreA >> (SHORT_INT_BITS- 1)) );  /*Ne marche pas encore*/
	}
	return getValeur();

}
