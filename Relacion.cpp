#include "Relacion.h"

/**
 *Metodo constructor de la clase
 *@param nombre1Param es un puntero al nombre del primer usuario
 *@param nombre2Param es un puntero al nombre del segundo usuario
 */
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

/**
 *Metodo para saber si una relacion ya existia
 *@param nombre1Param es un puntero al nombre del primer usuario
 *@param nombre2Param es un puntero al nombre del segundo usuario
 *@return devuelve 1 si la relacion ya existia y 0 si no
 */
int Relacion::yaEsta(char * nombre1Param, char * nombre2Param){
	return (equals(nombre1Param,nombre1) && equals(nombre2Param,nombre2)) || (equals(nombre2Param,nombre1) && equals(nombre1Param,nombre2));
	//Se compraran los nombres con los de la relación.
}

/**
 *Metodo para saber si dos nombres de usuario son iguales
 *@param nombreA es un puntero a un nombre
 *@param nombreB es un puntero a un nombre
 *@return iguales es 1 si los dos nombres son iguales y 0 si no
 */
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

/**
 *Aumenta el numero de iteraciones en 1
 */
void Relacion::aumentarNumeroIteraciones(){
	++cantidadIteraciones;
}

/**
 *Metodo para saber si un nombre esta en una tripleta
 *@param nombreParam es el nombre para buscar en la tripleta
 *@return devuelve 1 si el nombre es uno de los de la tripleta
 */
int Relacion::esta(char * nombreParam){
	return equals(nombre1,nombreParam) ||  equals(nombre2,nombreParam);
	//Si el usuario está en la relación.
}

/**
 *Metodo para obtener el numero de iteraciones
 *@return cantidadIteraciones es el numero de iteraciones
 */
double Relacion::getCantidadIteraciones(){
	return cantidadIteraciones;
}

/**
 *Metodo para obtener el otro usuario de una tripleta con el nombre del primero
 *@return nombreAmigo es el nombre del otro usuario en la tripleta
 */
char * Relacion::getNombreAmigo(char * nombreParam){
	char * nombreAmigo = nombre1;
	if(equals(nombreParam ,nombre1)){//Se revisa cual de los dos nombres devuelve.
		nombreAmigo = nombre2;
	}
	return nombreAmigo;//Devuelve el nombre del amigo.
}
				
