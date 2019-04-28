#include "ListaUsuarios.h"
#include "Usuario.h"
#include<string>
#include<iostream>
using namespace std;

ListaUsuarios::ListaUsuarios(){
	//Inicializacion
	primero= 0;
	ultimo= 0;
	usuarios= 0;
}

ListaUsuarios::~ListaUsuarios(){
	//Si tiene un primero lo borra
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
			
				//Fue encontrado
				encontrado= 1;
			}
			else{
				//Sino continua
				actual= actual->siguiente;
			}
		}
		//Si no fue encontrado y ya no hay usuarios
		if(!encontrado){
			//Prepara el retorno de un cero
			actual=0;
		}
	}

	return actual;
}

/**
 *@param posicion es un entero que representa la posicion de 0 a n del usuario
 *en la lista
 *@return nombre que es un string con el nombre del usuario en esa posicion
 */
string ListaUsuarios::getNombre(int posicion){

	Usuario * actual= primero;

	string nombre= "";

	//Busca en toda la lista
	for(int usuario= 0; usuario < usuarios && posicion >= 0; ++usuario){
		//Si llega a la posicion
		if(usuario == posicion){
			//Es el nombre de ese usuario
			nombre= actual->getNombre();
		}
		//Cambia de usuario. Cuando es el ultimo actual es 0 porque siguiente es 0
		actual= actual->siguiente;
	}
	//Si la posicion es invalida retorna un string vacio
	return nombre;
}

/**
 *
 *@param nombre es el string con el nombre del usuario que se quiere agregar
 */
void ListaUsuarios::agregarUsuario(string nombre){
	//Si no es vacio
	if(nombre.compare("")){
	
		//Llama al comparar
		comparar(nombre);
	}
}

/**
 *
 *@param nuevo es un puntero a un usuario nuevo que debe agregarse
 *al final de la lista
 */
void ListaUsuarios::pushBack(Usuario * nuevo){

	//El ultimo ahora tiene un siguiente
	ultimo->siguiente= nuevo;
	//El nuevo es ahora el ultimo
	ultimo= nuevo;
	//Aumenta el numero de usuarios en la lista
	++usuarios;
}

/**
 *
 *@param nuevoUsuario es el string con el nombre del usuario
 *que debe buscarse si ya esta en la lista
 */
void ListaUsuarios::comparar(string nuevoUsuario){

	//Si hay un primero
	if(primero){
		Usuario * actual= primero;

		int encontrado= 0;
		//Revisa entre todos los usuarios si ya alguno tiene ese nombre
		for(int usuario= 0; usuario < usuarios && !encontrado; ++usuario){
			//Si no son diferentes
			if(!actual->getNombre().compare(nuevoUsuario)){
				//El usuario ya estaba en la lista
				encontrado= 1;
				//Aumenta la cardinalidad del usuario
				actual->aumentarCardinalidad();
			}
			else if(!actual->siguiente){
				//Si ya esta en el final de la lista
				//Crea al usuario
				Usuario * usuarioNuevo= new Usuario(nuevoUsuario);
				//Lo agrega al final
				pushBack(usuarioNuevo);
			}
		}
	}
	else{
		//Crea al usuario
		Usuario * usuarioNuevo= new Usuario(nuevoUsuario);
		//Lo agrega como primero y ultimo
		primero= usuarioNuevo;
		ultimo= usuarioNuevo;
		//Aumenta el numero de usuarios en la lista
		++usuarios;
	}
}

/**
 *
 *@param salida es una referencia al ostream de salida
 * @return salida es la referencia al ostream de salida
 */
ostream & ListaUsuarios::imprimir(ostream & salida){
	//Si tiene un primero, lo imprimero
	if(primero){
	
		primero->imprimir(salida);
	}

	return salida;
}
