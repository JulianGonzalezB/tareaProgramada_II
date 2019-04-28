#ifndef _USUARIO_
#define _USUARIO_
#include "ListaAmigos.h"
#include<string>
#include<iostream>
using namespace std;

class Usuario{

	private:
		string nombre;
		double cardinalidad;
		ListaAmigos * listaAmigos;
	
	public:
		Usuario(string);
		~Usuario();
		void agregarAmigo(string, double);//Recibe el nombre y el coeficiente de Dice
		ostream & imprimir(ostream &);//Se imprime el usuario, su lista y el siguiente usuario si existe
		string getNombre();//Devuelve el nombre del usuario
		double getCardinalidad();//Devuelve la cardinalidad del usuario que es un double para facilitar el calculo
		void aumentarCardinalidad();
		Usuario * siguiente;//Siguiente usuario

};
#endif
