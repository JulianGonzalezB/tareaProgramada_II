#include "Usuario.h"
#include<iostream>
#include<string>
using namespace std;

Usuario::Usuario(string nombre){

	anterior= 0;
	siguiente= 0;
	primera= 0;
	ultima=0;
	this->nombre=nombre;
	interacciones= 0;
}

Usuario::~Usuario(){

	//Si hay un siguiente
        if(siguiente){
                //Mata al siguiente
                delete siguiente;
        }
	//Mata la primer interaccion si la hay
	if(primera){
	
		delete primera;
	}
        //Se mata a si mismo
        delete *this;
}

void Usuario::agregarInterac(usuario * usuario){
	
	Interaccion nuevaInteraccion = new Interaccion(usuario);

	if(!primera){
		
		primera= nuevaInteraccion;
	}
	else{
		if(!buscarInteraccion(usuario)){
			ultima->siguiente= nuevaInteraccion;
			nuevainteraccion->anterior= ultima;
			ultima= nuevaInteraccion;
		}
		else{
		
			delete nuevaInteraccion;
		}
	}

	++interacciones
}

int Usuario::buscarInteraccion(Usuario * usuario){

	int encontrado= 0;

	Interaccion * actual= primera;

	for(int mencion= 0; mencion < interacciones && !encontrado; ++mencion){
		//Revisar esto
		if(actual->mencionado == usuario){
		//Si ya existe entonces lo encontr[o y le suma +1 a la interaccion entre ambos
			encontrado = 1;
			actual->interacciones++;
		}
		else{
			actual= actual->siguiente;
		}
	}

	return encontrado
}

ostream & Usuario::imprimirBFs(ostream & salida){

	return salida;
}

void Usuario::calcularDice(){
}

Usuario::Interaccion::Interaccion(Usuario * usuario){

	mencionado= usuario;
	anterior= 0;
	siguiente= 0;
	interacciones = 1;
	dice= 0.0;
}

Usuario::Interaccion::~Interaccion(){

	if(siguiente){
	
		delete siguiente;
	}

	delete *this;
}
