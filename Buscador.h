#ifndef _BUSCADOR_
#define _BUSCADOR_
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Buscador{

	private:
		vector<string> entrada;
		string usuario;
		int numAmigos;
		ifstream * relaciones;
		void buscar();
	
	public:
		Buscador(string);
		~Buscador();
};
#endif
