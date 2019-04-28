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

/**
 *@param nombre es un string con el nombre del usuario a buscar
 *@return 0 si el usuario no se encuentra en la lista.
 */
Usuario * ListaUsuarios::getUsuario(string nombre){

	Usuario * actual = primero;

	int encontrado =0;

	if(primero){
	
		//Mientras no haya sido encontrado y haya un siguiente
		while(!encontrado && actual->siguiente){
			//Si no son diferentes
			if(!actual->getNombre().compare(nombre)){
			
				encontrado= 1;
			}
			else{
			
				actual= actual->siguiente
			}
		}

		if(!encontrado){
		
			actual=0;
		}
	}

	return actual;
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
