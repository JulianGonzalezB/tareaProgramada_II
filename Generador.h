#ifndef GENERADOR
#define GENERADOR
#define MAX_BUFFER_SIZE 10000
#include "ListaDeRelaciones.h"
#include "ListaDeUsuarios.h"
#include<fstream>
#include<iostream>
using namespace std;

class Generador{
	private:
		ListaDeRelaciones * listaDeRelaciones;
		ListaDeUsuarios * listaDeUsuarios;
		ifstream * entradaTuits;
		ifstream * entradaRelaciones;
		ofstream * salida;
		void agregarUsuariosYRevisarRelaciones(char *);
		void agregarRelaciones(char *, char *, int);
		void generarListasDeAmigos();
		double calcularDice(double,char*,char*);
		int sonIguales(char*,char*);
	public:
		Generador(char *);
		~Generador();
		void generarRelaciones();
};
#endif