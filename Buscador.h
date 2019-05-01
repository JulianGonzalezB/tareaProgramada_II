#ifndef _BUSCADOR_
#define _BUSCADOR_
#define LARGO_ENTRADA 40
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

class Buscador{

	private:
		char usuario[LARGO_ENTRADA];
		char numero[LARGO_ENTRADA];
		string mensajeError;
		int numAmigos;
		int revisarEntrada(char []);
		void buscar();
		int buscarUsuario(char []);
		void imprimirResultado(ifstream &);
	
	public:
		Buscador(char []);
		~Buscador();
};
#endif
