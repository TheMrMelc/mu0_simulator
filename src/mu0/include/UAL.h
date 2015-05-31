//author : Ma�lis
//Date : 8/04/2015



#ifndef UAL_H
#define UAL_H

#include "Composant.h"


class UAL : public Composant{
private:
public:

	/*Constructeurs*/
	UAL(std::string,int,int,std::string, short int, short int, bool);
	UAL(std::string,int,int,std::string, short int, short int, bool, Bus*, Bus*);
	UAL(std::string,int,int,std::string, short int, short int, bool, std::vector<Bus*>, std::vector<Bus*>);
	/*Destructeur*/
	virtual ~UAL(void){};
	/*Methode*/
	short int fonction(short int, short int);

};

#endif
