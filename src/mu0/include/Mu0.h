/*
 * Mu0.h
 *
 *  Created on: 2015-05-15
 *      Author: romain
 */

#ifndef MU0_H_
#define MU0_H_

#include "Microprocesseur.h"

class Mu0 : public Microprocesseur {

public:

	Mu0(std::vector<Composant*> composant);
	virtual ~Mu0();
	void decodeExecute(void);
};

#endif
