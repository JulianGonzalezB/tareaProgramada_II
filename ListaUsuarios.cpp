#include "ListaUsuarios.h"
#include "Usuario.h"
#include<string>
#include<iostream>
using namespace std;

ListaUsuarios::ListaUsuarios(){

	primero= 0;
	ultimo= 0;
	usuarios= 0;
}

ListaUsuarios::~ListaUsuarios(){

	if(primero){
	
		delete primero;
	}
}

Usuario * ListaUsuarios::getUsuario(string nombre){

	return primero;//Cambiar esto
}

string ListaUsuarios::getNombre(int posicion){

	return primero->getNombre();//Cambiar esto
}

void ListaUsuarios::agregarUsuario(string nombre){

	//Llama al comparar
}

void ListaUsuarios::pushBack(Usuario * nuevo){

	++usuarios;
}

void ListaUsuarios::comparar(string nuevoUsuario){

	//Llama a pushBack si no estaba el usuario
}

ostream & ListaUsuarios::imprimir(ostream & salida){

	if(primero){
	
		primero->imprimir(salida);
	}

	return salida;
}
