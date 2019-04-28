#include "Controlador.h"
#include "ListaUsuarios.h"
#include "ListaRelaciones.h"
#include<iostream>
#include<string>

Controlador::Controlador(){

	listaUsuarios= 0;
	listaRelaciones= 0;
}

Controlador::~Controlador(){

	if(listaRelaciones){
	
		delete listaUsuarios;//Si existe la lista de relaciones existe la de usuarios
		delete listaRelaciones;
	}
}

ostream & Controlador::imprimir(ostream & salida){

	listaUsuarios->imprimir(salida);

	return salida;
}

void Controlador::analizarRelaciones(){

}

void Controlador::buscar(string usuario, int numBFs){

}
