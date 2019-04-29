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
	nombre1 = new char[++tamanoNombre1];
	nombre2 = new char[++tamanoNombre2];
	for(int j = 0; j < tamanoNombre1; ++j){
	   nombre1[j] = nombre1Param[j];
	}
	for(int j = 0; j < tamanoNombre2; ++j){
	   nombre2[j] = nombre2Param[j];
	}
	cantidadIteraciones = 1.0;
	dice = 0;
}

Relacion::~Relacion(){
	delete [] nombre1;
	delete [] nombre2;
}

int Relacion::yaEsta(char * nombre1Param, char * nombre2Param){
	return (equals(nombre1Param,nombre1) && equals(nombre2Param,nombre2)) || (equals(nombre2Param,nombre1) && equals(nombre1Param,nombre2));
}

int Relacion::equals(char * nombreA ,char * nombreB){
	int iguales = 0;
	int i = 0;
	while(nombreA[i] == nombreB[i]){
		if(nombreA[i] == '\0' && nombreB[i] == '\0'){
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
}

double Relacion::getCantidadIteraciones(){
	return cantidadIteraciones;
}

char * Relacion::getNombreAmigo(char * nombreParam){
	char * nombreAmigo = nombre1;
	if(equals(nombreParam ,nombre1)){
		nombreAmigo = nombre2;
	}
	return nombreAmigo;
}
				