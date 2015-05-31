//author : Ma�lis
//Date : 16/12/2015

//fichier Composant.cpp

#include "../include/Composant.h"

/////////////////////////////////////////////////////constructeurs//////////////////////////////////////////////////////////////////////

Composant::Composant(std::string nc, int _nbEntree, int _nbSortie,std::string nv, short int _signal, short int _valeur, bool _actif) :
			
			nomComposant(nc),
		    nbEntree(_nbEntree),
		    nbSortie(_nbSortie),
		    nomSignal(nv),
		    signal(_signal),
		    valeur(_valeur),
		    actif(_actif)
		    {}

Composant::Composant(std::string nc,int _nbEntree, int _nbSortie,std::string nv, short int _signal, short int _valeur, bool _actif, Bus* _busEntrant, Bus*_busSortant) :

		    nomComposant(nc),
		    nbEntree(_nbEntree),
		    nbSortie(_nbSortie),
		    signal(_signal),
		    valeur(_valeur),
		    actif(_actif)
		    {
	addBusEntrant(_busEntrant);
	addBusSortant(_busSortant);
		    }

Composant::Composant(std::string nc,int _nbEntree, int _nbSortie,std::string nv, short int _signal, short int _valeur, bool _actif, std::vector<Bus*> _busEntrant, std::vector<Bus*>_busSortant) :

		    nomComposant(nc),
		    nbEntree(_nbEntree),
		    nbSortie(_nbSortie),
		    signal(_signal),
		    valeur(_valeur),
		    actif(_actif),
			busEntrant(_busEntrant),
			busSortant(_busSortant)
		    {}

void Composant::addBusEntrant(Bus* b){
	busEntrant.push_back(b);
}
void Composant::supprBusEntrant(Bus*b){
	int verifier = 0;
	int s = busEntrant.size()-1;
	int i = 0;
	while (i != s){
		if (busEntrant[i] == b){
			busEntrant.erase(busEntrant.begin()+i);
			verifier = 1;
		}
		i++;
	}
	if (verifier == 0){
		printf("le bus entrant n'a pas �t� supprim�");
	}

}

void Composant::addBusSortant(Bus* b){
	busSortant.push_back(b);
}
void Composant::supprBusSortant(Bus* b){
	int verifier = 0;
	int s = busSortant.size()-1;
	int i = 0;
	while (i != s){
		if (busEntrant[i] == b){
			busSortant.erase(busSortant.begin()+i);
			verifier = 1;
		}
		i++;
	}
	if (verifier == 0){
		printf("le bus sortant n'a pas �t� supprim�");
	}

}

void Composant::fonction(void){}


Composant::~Composant(void){

	int s = busSortant.size()-1;
	int i = 0;
	while (i != s){
		busSortant.erase(busSortant.begin()+i);
		i++;
	}

	s = busEntrant.size()-1;
	i = 0;
	while (i != s){
			busEntrant.erase(busEntrant.begin()+i);
			i++;
		}
}
