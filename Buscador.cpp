#include "Buscador.h"
#include<string>
#include<iostream>
#include <boost/algorithm/string.hpp>
#include<bits/stdc++.h>
using namespace std;

Buscador::Buscador(string entrada){

	boost::split(this->entrada, entrada, boost::is_any_of(" "));

	//Si no son dos parametros
	if(entrada.size() == 2){
		//Extrae el usuario
		usuario= this->entrada[0];

		//Extrae el numero de amigos a imprimir
		numAmigos= stoi(this->entrada[1]);

		//Busca al usuario y a sus amigos
		buscar();
	}
	else{
	
		cout << "> Consulta invalida. La consulta debe seguir el formato especificado" << endl;
	}
}

Buscador::~Buscador(){
	//Si tiene el archivo
	if(relaciones){
		//Lo mata
		delete relaciones;
	}
}

void Buscador::buscar(){
	//Abre el archivo de relaciones
	relaciones= new ifstream((char*)"Relaciones.txt");

	//Busca al usuario
	//Imprime al usuario
	//Imprime sus n amigos si n es valido
}
