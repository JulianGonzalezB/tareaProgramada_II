#ifndef LISTA_DE_AMIGOS
#define LISTA_DE_AMIGOS
#include <fstream>
#include <iostream>
using namespace std;

class ListaDeAmigos{
	class Celda;
    private:
		Celda * primera;
	    Celda * ultima;
		int numDeAmigos;

		class Celda{
			public:
				Celda * anterior;
				Celda * siguiente;
				char * nombreDelAmigo;
				double dice;
				Celda(char *, double);
				~Celda();
				void imprimir(ofstream &);
	    };
		void pushBack(char *, double);
		void insertar(int,char *,double);
		void pushFront(char * , double);
	public:
		ListaDeAmigos();
		~ListaDeAmigos();
		void agregar(double,char*);
		void imprimir(ofstream &);
		int getCantidadDeAmigos();
};
#endif