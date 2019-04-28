#ifndef _LISTAAMIGOS_
#define _LISTAAMIGOS_
#include<string>
#include<iostream>

class ListaAmigos{

	class Amigo;

	private:
		Amigo * primero;
		Amigo * ultimo;
		void pushBach(Amigo *);
		void comparar(string);//Compara por nombre

		class Amigo{
		
			public:
				string nombre;
				Amigo * siguiente;
				double dice;
				Amigo(string, double);
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
