#include "Tuit.h"
#include <string>
#include <iostream>

Tuit::Tuit(){

	primerUsuario = 0;

	ultimoUsuario= 0;
}

Tuit::~Tuit(){
	//Si tiene usuarios
	if(primerUsuario){
		//Mata al primer usuario y comienza la cadena de borrado de usuarios
		delete primerUsuario;
	}

	//Si tiene un siguiente Tuit
	if(tuitSiguiente){
	
		delete tuitSiguiente;
	}
	//Se mata a si mismo
	delete *this;
}

Tuit & Tuit::pushFront(string nombre){

	Usuario * nuevoUsuario= new Usuario(nombre);

	if(primerUsuario){
	
		nuevoUsuario->siguiente= primerUsuario;
		primerUsuario->anterior= nuevoUsuario;
	}

	primerUsuario= nuevoUsuario;
}

Tuit & Tuit::pushBack(string nombre){

	Usuario * nuevoUsuario= new usuario(nombre);

	if(ultimoUsuario){
	
		nuevousuario->anterior= ultimoUsuario;
		ultimoUsuario->siguiente= nuevoUsuario;
	}

	ultimoUsuario= nuevoUsuario;
}

int Tuit::buscar(string nombre){

	int posicion= -1;

	int encontrado= 0;

	Usuario * usuarioActual= primerUsuario;

	for(int usuario= 0; usuario < this->numeroDeUsuarios && !encontrado; ++usuario){
	
		if(!usuarioActual->nombre.compare(nombre)){
		
			encontrado= 1;
		}
		else{
		
			++posicion;
			if(usuario != this->numeroDeUsuarios - 1){
			
				usuarioActual= usuarioActual->siguiente;
			}
		}
	}

	return posicion;
}

Tuit::Usuario::Usuario(string nombre){

	this->nombre= nombre;
	this->anterior= 0;
	this->siguiente= 0;
}

Tuit::Usuario::~Usuario(){
	
	//Si hay un siguiente
	if(siguiente){
		//Mata al siguiente
		delete siguiente;
	}
	//Se mata a si mismo
	delete *this;
}

string Tuit::getNombre(int posicion){
	
	//Comienza en el primer usuario en el tuit
	Usuario * usuarioActual= primerUsuario;
	
	//Busca al usuario en la posicion dada
	for(int usuario= 0; usuario < posicion; ++usuario){
		
		if(usuarioActual->siguiente){
		
			usuarioActual= usuarioActual->siguiente;
		}
	}
	
	//Devuelve el nombre del usuario que este en esa posicion en el tuit
	return usuarioActual->nombre;
}

int Tuit::getNumeroDeUsuarios(){

	return this->numeroDeUsuarios;
}
