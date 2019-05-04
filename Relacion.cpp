#include "Relacion.h"

Relacion::Relacion(char * nombre1Param, char * nombre2Param){
	int tamanoNombre1 = 0;
	int tamanoNombre2 = 0;
	while(nombre1Param[tamanoNombre1] != '\0'){
		++tamanoNombre1;
	}
	while(nombre2Param[tamanoNombre2] != '\0'){
		++tamanoNombre2;
	}
	//Estos while calculan el tamaño de cada nombre que se va a agregar a la relación.
	nombre1 = new char[++tamanoNombre1];
	nombre2 = new char[++tamanoNombre2];
	for(int j = 0; j < tamanoNombre1; ++j){
	   nombre1[j] = nombre1Param[j];
	}
	for(int j = 0; j < tamanoNombre2; ++j){
	   nombre2[j] = nombre2Param[j];
	}
	//Estos for copian los nombres que se van a agregar a la relación.
	cantidadIteraciones = 1.0;
	//Se inicializa en 1 ya que al crearse la relación ya de fijo aparecen una vez juntos.
}

Relacion::~Relacion(){
	delete [] nombre1;
	delete [] nombre2;
}

int Relacion::yaEsta(char * nombre1Param, char * nombre2Param){
	return (equals(nombre1Param,nombre1) && equals(nombre2Param,nombre2)) || (equals(nombre2Param,nombre1) && equals(nombre1Param,nombre2));
	//Se compraran los nombres con los de la relación.
}

int Relacion::equals(char * nombreA ,char * nombreB){
	int iguales = 0;
	int i = 0;//Guarda la posición del caracter en revsión de cada nombre.
	while(nombreA[i] == nombreB[i]){//Mientras que los caracteres coincidan.
		if(nombreA[i] == '\0' && nombreB[i] == '\0'){//Si son iguales hasta el final.
			iguales = 1;
		}
		++i;
	}
	return iguales;
}

void Relacion::aumentarNumeroIteraciones(){
	++cantidadIteraciones;
}

int Relacion::esta(char * nombreParam){
	return equals(nombre1,nombreParam) ||  equals(nombre2,nombreParam);
	//Si el usuario está en la relación.
}

double Relacion::getCantidadIteraciones(){
	return cantidadIteraciones;
}

char * Relacion::getNombreAmigo(char * nombreParam){
	char * nombreAmigo = nombre1;
	if(equals(nombreParam ,nombre1)){//Se revisa cual de los dos nombres devuelve.
		nombreAmigo = nombre2;
	}
	return nombreAmigo;//Devuelve el nombre del amigo.
}
				
