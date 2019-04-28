#ifndef _USUARIO_
#define _USUARIO_
#include "ListaAmigos.h"
#include<string>
#include<iostream>

class Usuario{

	private:
		string nombre;
		Usuario * siguiente
		double cardinalidad;
		ListaAmigos * listaAmigos;
	
	public:
		Usuario();
		~Usuario();
		void agregarAmigo(string);
		ostream & imprimir(ostream &);
		string getNombre();
		double getCardinalidad();

};
#endif
