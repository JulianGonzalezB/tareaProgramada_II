#ifndef _TUIT_
#define _TUIT_
#include "Usuario.h"
#include <string>
class Tuit{

	class usuario;

	private:
		Usuario * primerUsuario;
		Usuario * ultimoUsuario;
		int numeroDeUsuarios;
	
	public:
		//Para construir la lista de tuits
		Tuit * tuitSiguiente;
		Tuit * tuitAnterior;
		//Metodos del tuit
		Tuit();
		~Tuit();
		Tuit & pushFront(string);
		Tuit & pushBack(String);
		int buscar(string); //Recibe el nombre del usuario y devuelve la posicion del usuario en ese tuit
		string getNombre(int);
		int getNumeroDeUsuarios();
};
#endif
