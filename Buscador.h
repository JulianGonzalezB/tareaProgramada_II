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
		char usuario[LARGO_ENTRADA];//Nombre del usuario consultado
		char numero[LARGO_ENTRADA];//Numero de amigos del usuario consultado a imprimir
		string mensajeError;//Mensaje de error a imprimir si el formato de consulta es incorrecto
		int numAmigos;//Numero de amigos a imprimir pero en entero
		int revisarEntrada(char []);//Metodo para ver si la consulta es valida
		void buscar();
		int buscarUsuario(char []);//Verifica si el usuario esta
		void imprimirResultado(ifstream &);
	
	public:
		Buscador(char []);
		~Buscador();
};
#endif
