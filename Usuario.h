#ifndef USUARIO
#define USUARIO
#include "ListaDeAmigos.h"

class Usuario{
	private:
		char * nombre;
		double cardinalidad;
		ListaDeAmigos * listaDeAmigos;
		
	public:
		Usuario(char *);
		~Usuario();
		void operator++();
		void mostrarAmigos(ofstream &);
		int yaEsta(char *);
		char * getNombre();
		int getNumeroDeAmigos();
		double getCardinalidad();
};
#endif