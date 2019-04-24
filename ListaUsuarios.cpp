#include "ListaUsuarios.h"
using namespace std;

ListaUsuarios::ListaUsuarios(){

	primerUsuario= 0;
	ultimoUsuario= 0;
	numeroDeUsuarios= 0;
}

ListaUsuarios::~ListaUsuarios(){

	if(primerusuario){
	
		delete primerUsuario;
	}

	delete *this;
}

ListaUsuarios & ListaUsuarios::pushFront(Usuario & nuevo){

	if(primerusuario){
	
		primerusuario->anterior = nuevo;
		nuevo->siguiente= primerusuario;
	}

	primerUsuario= nuevo;

	++numeroDeUsuarios;

	return *this;
}

ListaUsuarios & ListaUsuarios::pushBack(Usuario & nuevo){

	if(ultimoUsuario){
	
		ultimoUsuario->siguiente= nuevo;
		nuevo->anterior= ultimoUsuario;
	}

	ultimoUsuario= nuevo;

	++numeroDeUsuarios;

	return *this;
}

int ListaUsuarios:: getNumUsuarios(){

	return numeroDeUsuarios;
}
