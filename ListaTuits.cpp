#include "ListaTuits.h"
#include "Tuit.h"

ListaTuits::ListaTuits(){

}

ListaTuits::~ListaTuits(){

	//Si tiene tuits
	if(primerTuit){
	
		delete primerTuit;
	}

	delete *this;
}

ListaTuits & ListaTuits::pushFront(Tuit & tuit){

}

ListaTuits & ListaTuits::pushBack(Tuit &){

}

int ListaTuits::getNumeroDeTuits(){

	return this->numeroDeTuits;
}
