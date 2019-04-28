#ifndef _LISTAAMIGOS_
#define _LISTAAMIGOS_
#include<string>
#include<iostream>
using namespace std;

class ListaAmigos{

	class Amigo;

	private:
		Amigo * primero;
		Amigo * ultimo;
		void pushBack(Amigo *);//Agrega al final de la lista
		void comparar(string, double dice);//Compara por nombre

		class Amigo{
		
			public:
				string nombre;
				Amigo * siguiente;
				double dice;
				Amigo(string, double);//Solo se agrega si ya el dice esta calculado
				~Amigo();
				ostream & imprimir(ostream &);
		};
	
	public:
		ListaAmigos();
		~ListaAmigos();
		int numAmigos;
		void agregar(string, double);
		ostream & imprimir(ostream &);
};
#endif
