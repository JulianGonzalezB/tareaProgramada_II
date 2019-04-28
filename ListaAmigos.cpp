#include "ListaAmigos.h"
#include<string>
#include<iostream>
using namespace std;

ListaAmigos::ListaAmigos(){

	primero= 0;
	ultimo= 0;
	numAmigos= 0;
}

ListaAmigos::~ListaAmigos(){

	if(primero){
	
		delete primero;
	}
}

void ListaAmigos::pushBack(Amigo * nuevoAmigo){

	++numAmigos;
}

void ListaAmigos::comparar(string nuevoAmigo){

}

void ListaAmigos::agregar(string nombre, double dice){

}

ostream & ListaAmigos::imprimir(ostream & salida){

	if(primero){
	
		primero->imprimir(salida);
	}

	return salida;
}

ListaAmigos::Amigo::Amigo(string nombre, double dice){

	this->nombre= nombre;
	this->dice= dice;
	siguiente= 0;
}

ListaAmigos::Amigo::~Amigo(){

	if(siguiente){
	
		delete siguiente;
	}
}

ostream & ListaAmigos::Amigo::imprimir(ostream & salida){

	salida << "(" << nombre << ", " << dice << "), " << endl;

	if(siguiente){
	
		siguiente->imprimir(salida);
	}

	return salida;
}
