#include "ListaDeAmigos.h"

ListaDeAmigos::Celda::Celda(char * nombreDelAmigoParam, double diceParam){
	anterior = 0;
	siguiente = 0;
	dice = diceParam;
	int tamanoNombre = 0;
	while(nombreDelAmigoParam[tamanoNombre] != '\0'){
		++tamanoNombre;
	}
	nombreDelAmigo = new char[++tamanoNombre];
	for(int j = 0; j < tamanoNombre; ++j){
	   nombreDelAmigo[j] = nombreDelAmigoParam[j];
	}
}

ListaDeAmigos::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
	delete [] nombreDelAmigo;
}

void ListaDeAmigos::Celda::imprimir(ofstream & salida){
	salida << nombreDelAmigo<< " "<< dice<< " ";
	if(siguiente){
		siguiente->imprimir(salida);
	}
}

void ListaDeAmigos::pushBack(char * nombreDelAmigo, double dice){
	++numDeAmigos;
	Celda * nueva = new Celda(nombreDelAmigo,dice);
	nueva->anterior = ultima;
	if(ultima){
	   ultima->siguiente = nueva;	
	}
	else {
		primera = nueva;
	}
	ultima = nueva;
}

ListaDeAmigos::ListaDeAmigos(){
	numDeAmigos = 0;
	primera = 0;
    ultima = 0;
}

ListaDeAmigos::~ListaDeAmigos(){
	if(primera){
		delete primera;
	}
}

void ListaDeAmigos::agregar(double diceParam, char * nombreDelAmigoParam){
	Celda * actual = primera;
	int pos = 0;
	while(actual && diceParam <= actual->dice){
		actual = actual->siguiente;
		++pos;
	}
	if(!actual){
		pushBack(nombreDelAmigoParam,diceParam);
	}
	else{
		insertar(pos,nombreDelAmigoParam,diceParam);
	}
	actual= 0;
}

void  ListaDeAmigos::insertar(int pos, char * nombreDelAmigo, double dice){
	++numDeAmigos;
	if(pos==0){
		pushFront(nombreDelAmigo,dice);
	}
	else { 
		Celda * actual = primera;
	    int i = 0;
	    while(actual && i < pos){
			++i;
		    actual = actual->siguiente;
	    }
		Celda * nueva = new Celda(nombreDelAmigo,dice);
		nueva->siguiente = actual;
		nueva->anterior = actual->anterior;
		actual->anterior = nueva;
		nueva->anterior->siguiente = nueva;
		actual = 0;
	}	
}

void ListaDeAmigos::pushFront(char * nombreDelAmigo, double dice){
    Celda * nueva = new Celda(nombreDelAmigo,dice);
    nueva->siguiente = primera;
    if(primera){ 
		primera->anterior = nueva;
	}	
	else { 
		ultima = nueva;
	}
	primera = nueva;
}

void ListaDeAmigos::imprimir(ofstream & salida){
	if(primera){
		primera->imprimir(salida);
	}
}

int ListaDeAmigos::getCantidadDeAmigos(){
	return numDeAmigos;
}