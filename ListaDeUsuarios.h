#ifndef LISTA_DE_USUARIOS
#define LISTA_DE_USUARIOS
#include "Usuario.h"
#include<iostream>
#include<fstream>
using namespace std;

class ListaDeUsuarios{
	class Celda;  
    private:
		Celda * primera;
		Celda * ultima;
        class Celda {
			public:
				Usuario * usuario;
				Celda * anterior;
				Celda * siguiente;
				Celda(char *);
				~Celda();
				void imprimir(ofstream &);
	    };
	    void pushBack(char *);
		
	public:
		ListaDeUsuarios();
		~ListaDeUsuarios();
		void agregar(char *);
		void imprimir(ofstream &);
		char * getNombreDeUsuario(int);
        int hayUsuario(int);
		double getCardinalidadDeUsuario(char*);
		void agregarAmigoAUsuario(double,char *,char *);
};
#endif