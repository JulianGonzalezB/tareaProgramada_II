#include "ListaRelaciones.h"
#include "Relacion.h"
#include<string>
using namespace std;

ListaRelaciones::ListaRelaciones(){

	primera= 0;
	ultima= 0;
}

ListaRelaciones::~ListaRelaciones(){

	if(primera){
	
		delete primera;
	}
}

void ListaRelaciones::pushBack(Relacion * nuevaRelacion){

	++relaciones;//Esto es lo unico que viene de fijo que se me ocurre
}

void ListaRelaciones::comparar(string primerUsuario, string segundoUsuario){

}

void ListaRelaciones::agregar(string primerUsuario, string segundoUsuario){

	//Llama a comparar() y luego a pushBack si es una pareja nueva
}

Relacion * ListaRelaciones::getRelacion(string primerUsuario, string segundoUsuario){

	return primera; //Cambiar esto, es slo para que compile
}
