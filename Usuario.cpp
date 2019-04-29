#include "Usuario.h"

Usuario::Usuario(char * nombreParam){
	int tamanoNombre = 0;
	while(nombreParam[tamanoNombre] != '\0'){
		++tamanoNombre;
	}
	nombre = new char[++tamanoNombre];
	for(int j = 0; j < tamanoNombre; ++j){
	   nombre[j] = nombreParam[j];
	}
	cardinalidad = 1;
	listaDeAmigos = new ListaDeAmigos();
}

Usuario::~Usuario(){
	delete [] nombre;
	delete listaDeAmigos;
}

void Usuario::operator++(){
	++cardinalidad;
}

void Usuario::mostrarAmigos(ofstream & salida){
	listaDeAmigos->imprimir(salida);
}

int Usuario::yaEsta(char * nombreParam){
	int iguales = 0;
	int i = 0;
	while(!iguales && nombre[i] == nombreParam[i]){
		if(nombre[i] == '\0' && nombreParam[i] == '\0'){
			iguales = 1;
		}
		++i;
	}
	return iguales;
}

char * Usuario::getNombre(){
	return nombre;
}

int Usuario::getNumeroDeAmigos(){
	return listaDeAmigos->getCantidadDeAmigos();
}

double Usuario::getCardinalidad(){
	return cardinalidad;
}

void Usuario::agregarAmigoAlUsuario(double dice, char * nombreDeAmigo){
	listaDeAmigos->agregar(dice,nombreDeAmigo);
}