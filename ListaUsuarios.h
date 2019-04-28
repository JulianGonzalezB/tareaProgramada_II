#ifndef _LISTAU_
#define _LISTAU_
#include "Usuario.h"
#include<string>
using namespace std;

class ListaUsuarios{

	private:
		Usuario * primero;
		Usuario * ultimo;
		void pushBack(Usuario *);//Agrega al usuario nuevo al final de la lista
		void comparar(string);//Busca si el nuevo usuario ya estaba o no o si es el primero
		int usuarios;//Numero de usuarios en la lista
	
	public:
		ListaUsuarios();
		~ListaUsuarios();
		Usuario * getUsuario(string);//Para pedirle un usuario
		string getNombre(int);//Para pedirle el nombre de un usuario
		void agregarUsuario(string);//Para agregar un usuario. La lista utiliza comparar y pushBack si el usuario es nuevo
		ostream & imprimir(ostream &);

};
#endif
