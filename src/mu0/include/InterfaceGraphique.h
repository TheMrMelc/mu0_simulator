#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include "Microprocesseur.h"

class InterfaceGraphique {

	public :
		Microprocesseur * microP;
		
		InterfaceGraphique(Microprocesseur *);
		
		void afficherEtatMicroP(Microprocesseur *);
		void execute(Microprocesseur *);

};

#endif
