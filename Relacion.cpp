#include "Relacion.h"
#include<string>

Relacion::Relacion(string primero, string segundo){

	primerUsuario= primero;
	segundoUsuario= segundo;
	dice= 0.0;
	interacciones= 0;
}

Relacion::~Relacion(){

	if(siguiente){
	
		delete siguiente;
	}

	delete *this;
}

void Relacion::calcularDice(){

}

double Relacion::getDice(){

	return dice;
}

string Relacion::getNombre(string miNombre){

	string nombre= "";

	//Si miNombre es primerUsuario retorno segundoUsuario
	//Si miNombre es segundoUsuario retorno primerUsuario
	
	return nombre;
}
