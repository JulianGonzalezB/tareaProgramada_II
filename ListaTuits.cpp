#include "ListaTuits.h"
#include "Tuit.h"

ListaTuits::ListaTuits(){
	
	primerTuit= 0;
	ultimoTuit= 0;
}

ListaTuits::~ListaTuits(){

	//Si tiene tuits
	if(primerTuit){
	
		delete primerTuit;
	}

	delete *this;
}

ListaTuits & ListaTuits::pushFront(Tuit & tuit){

	Tuit * nuevoTuit = tuit;
	//Si tiene un primer tuit
	if(primerTuit){
	
		primerTuit->tuitAnterior= nuevoTuit;
		nuevoTuit->tuitSiguiente= primerTuit;
	}

	primerTuit= nuevoTuit;

	return *this;
}

ListaTuits & ListaTuits::pushBack(Tuit & tuit){

	Tuit * nuevoTuit = tuit;
	//Si ya hay un ultimo
	if(ultimoTuit){
	
		ultimoTuit->tuitSiguiente= nuevoTuit;
		nuevoTuit->tuitAnterior= ultimoTuit;
	}

	ultimoTuit= nuevoTuit;

	return *this;
}

int ListaTuits::getNumeroDeTuits(){

	return this->numeroDeTuits;
}
