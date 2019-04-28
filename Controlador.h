#ifndef _CONTROLLER_
#define _CONTROLLER_
#include "ListaUsuarios.h"
#include "ListaRelaciones.h"
#include<iostream>
#include<string>
using namespace std;

class Controlador{

	private:
		ListaUsuarios * listaUsuarios;
		ListaRelaciones * listaRelaciones;

	public:
		Controlador();
		~Controlador();
		ostream & imprimir(ostream &);
		void analizarRelaciones();
		void buscar(string, int);//Recibe el nombre de un usuario y el numero de mejores amigos a imprimir en salida estandar
};
#endif
