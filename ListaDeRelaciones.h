#ifndef LISTA_DE_RELACIONES
#define LISTA_DE_RELACIONES
#include "Relacion.h"
#include<iostream>
using namespace std;

class ListaDeRelaciones{
	class Celda;
    private:
		Celda * primera;
	    Celda * ultima;

		class Celda{
			public:
				Celda * anterior;
				Celda * siguiente;
				Relacion * relacion;
				Celda(char *, char *);
				~Celda();
	    };
		void pushBack(char *, char *);
		
	public:
		ListaDeRelaciones();
		~ListaDeRelaciones();
		void agregar(char *,char *);
		int hayRelacion(int);
		int esta(char *,int);
		double getNumeroDeInteraccionesDeRelacion(int);
		char * getNombreDeAmigoDeRelacion(int,char *);
};
#endif