#include "Usuario.h"
#include "ListaAmigos.h"
#include<string>
#include<iostream>
using namespace std;

Usuario::Usuario(){

	nombre = "";
	siguiente= 0;
	cardinalidad= 0.0;
	listaAmigos = new ListaAmigos();
}

Usuario::~Usuario(){

	if(siguiente){
	
		delete siguiente;
	}

	delete listaAmigos;

	delete *this;
}

void Usuario::agregarAmigo(string nombre){

}

ostream & Usuario::imprimir(ostream & salida){

	salida << this->nombre << endl;
	salida << "Numero de amigos: " << listaAmigos->numeroAmigos << endl;
	listaAmigos->imprimir(salida);

	if(siguiente){
	
		siguiente->imprimir(salida);
	}

	return salida;
}

string Usuario::getNombre(){

	return nombre;
}

double Usuario::getCardinalidad(){

	return cardinalidad;
}
