#include "Usuario.h"
#include "ListaAmigos.h"
#include<string>
#include<iostream>
using namespace std;

Usuario::Usuario(string nombre){
	//Inicializacion
	this->nombre = nombre;
	siguiente= 0;
	cardinalidad= 0.0;
	listaAmigos = new ListaAmigos();
}

Usuario::~Usuario(){
	//Si tiene un siguiente
	if(siguiente){
		//Lo destruye
		delete siguiente;
	}
	//Borra su lista de amigos
	delete listaAmigos;
}

/**
 *
 *@param nombre es el string con el nombre del amigo
 *@param dice es un double que indica el coeficiente de dice de relacion
 *con el amigo
 */
void Usuario::agregarAmigo(string nombre, double dice){
	//Lo pasa a la lista de amigos
	listaAmigos->agregar(nombre, dice);
}

/**
 *
 *@param salida es la referencia al ostream de salida
 *@return salida es la referencia al ostream de salida
 */
ostream & Usuario::imprimir(ostream & salida){
	//Formato de impresion en el archivo
	salida << this->nombre << endl;
	//Imprime su cardinalidad
	salida << "Cardinalidad: " << cardinalidad << endl;
	//Imprime el numero de amigos
	salida << "Numero de amigos: " << listaAmigos->numAmigos << endl;
	//Imprime su lista de amigos
	listaAmigos->imprimir(salida);

	//Si tiene un siguiente le dice que se imprima
	if(siguiente){
	
		siguiente->imprimir(salida);
	}

	return salida;
}

/**
 *
 *@return nombre es el nombre de este usuario
 */
string Usuario::getNombre(){
	//Retorna el nombre del usuario
	return nombre;
}

void Usuario::aumentarCardinalidad(){
	//Cuando lo intentaron agregar pero ya estaba
	++cardinalidad;
}

/**
 *
 *@return cardinalidad es un double que indica la cardinalidad del usuario
 *Es un double para facilitar las operaciones del calculo del indice de Dice
 */
double Usuario::getCardinalidad(){
	//Retorna la cardinalidad
	return cardinalidad;
}
