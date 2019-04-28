#include "ListaAmigos.h"
#include<string>
#include<iostream>
using namespace std;

ListaAmigos::ListaAmigos(){
	//Inicializacion
	primero= 0;
	ultimo= 0;
	numAmigos= 0;
}

ListaAmigos::~ListaAmigos(){
	//Si hay un primero
	if(primero){
		//Lo destruye
		delete primero;
	}
}

/**
 *
 *@param nuevoAmigo es un puntero a un Amigo
 */
void ListaAmigos::pushBack(Amigo * nuevoAmigo){
	//Agrega al amigo de ultimo en la lista
	ultimo->siguiente= nuevoAmigo;
	ultimo= nuevoAmigo;

	++numAmigos;
}

/**
 *
 *No deberia ocurrir que el amigo ya exista porque ya se implemento esa seguridad pero por si algo
 *@param nuevoAmigo es un string que contiene el nombre del amigo a agregar
 *@param dice es un double que indica el valor del coeficiente de Dice
 */
void ListaAmigos::comparar(string nuevoAmigo, double dice){

	Amigo * amigoNuevo= 0;
	//Si hay un primero
	if(primero){
	
		Amigo * actual= primero;

		int encontrado= 0;

		//Para cada amigo en la lista de amigos
		for(int amigo= 0; amigo < numAmigos && !encontrado; ++amigo){
			//Si no son diferentes
			if(!actual->nombre.compare(nuevoAmigo)){
			
				encontrado= 1;
			}
		}
		//Si no fue encontrado
		if(!encontrado){
		
			//Crea al usuario
			amigoNuevo= new Amigo(nuevoAmigo, dice);
			//Lo agrega de ultimo en la lista
			pushBack(amigoNuevo);
		}
	}
	else{
		//Si la lista esta vacia
		//Crea al amigo
		amigoNuevo= new Amigo(nuevoAmigo, dice);
		//Lo pone como primero y como ultimo
		primero= amigoNuevo;
		ultimo= amigoNuevo;
		//Aumenta el numero de amigos en la lista
		++numAmigos;
	}
}

/**
 *Este metodo existe para facilitar su uso por otras clases sin evidenciar lo que ocurre de fondo
 *Si el amigo ya existia no se agrega a la lista
 *@param nombre es un string que contiene el nombre del amigo
 *@param dice es un double que indica el coeficiente de Dice con ese amigo
 */
void ListaAmigos::agregar(string nombre, double dice){

	//Llama a comparar
	comparar(nombre, dice);
}

/**
 *
 *@param salida es una referencia al ostream de salida
 *@return salida es una referencia al ostream de salida
 */
ostream & ListaAmigos::imprimir(ostream & salida){
	//Si la lista no esta vacia
	if(primero){
		//Imprime al primero
		primero->imprimir(salida);
	}

	return salida;
}

ListaAmigos::Amigo::Amigo(string nombre, double dice){
	//Inicializacion
	this->nombre= nombre;
	this->dice= dice;
	siguiente= 0;
}

ListaAmigos::Amigo::~Amigo(){
	//Si tiene un amigo siguiente en la lista
	if(siguiente){
		//Lo manda a destruir
		delete siguiente;
	}
}

/**
 *
 *@param salida es una referencia al ostream de salida
 *@return salida es una referencia al ostream de salida
 */
ostream & ListaAmigos::Amigo::imprimir(ostream & salida){
	//Formato de impresion de cada amigo en la salida
	salida << "(" << nombre << ", " << dice;
	//Si tiene un amigo siguiente en la lista
	if(siguiente){
		//Imprime como si hubiera un siguiente
		salida << "), ";
		//Lo manda a imprimir
		siguiente->imprimir(salida);
	}
	else{
	
		//Imprime como si fuera el ultimo
		salida << ")." << endl;
	}

	return salida;
}
