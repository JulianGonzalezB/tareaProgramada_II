#include "ListaDeAmigos.h"

ListaDeAmigos::Celda::Celda(char * nombreDelAmigoParam, double diceParam){
	anterior = 0;
	siguiente = 0;
	dice = diceParam;
	int tamanoNombre = 0;
	while(nombreDelAmigoParam[tamanoNombre] != '\0'){
		++tamanoNombre;
	}
	//Este while calcula el tamaño del nombre del amigo que se va a agregar a la lista.
	nombreDelAmigo = new char[++tamanoNombre];
	for(int j = 0; j < tamanoNombre; ++j){
	   nombreDelAmigo[j] = nombreDelAmigoParam[j];
	}
	//Este for copia el nombre del amigo que se va a agregar al la lista.
}

ListaDeAmigos::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
	delete [] nombreDelAmigo;
}

void ListaDeAmigos::Celda::imprimir(ofstream & salida){
	salida << nombreDelAmigo<< " ";
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
	int pos = 0;//Este guarda la posición de la relación que se está revisando en la lista.
	//El 0 es para que empiece desde la primera celda.
	while(actual && diceParam <= actual->dice){
		//Mientras haya siguiente y el dice sea menor o igual.
		actual = actual->siguiente;
		++pos;
	}
	if(!actual){//Si es la relación con el menor coeficiente de Dice.
		pushBack(nombreDelAmigoParam,diceParam);
	}
	else{
		insertar(pos,nombreDelAmigoParam,diceParam);
	}
	actual= 0;
}

void  ListaDeAmigos::insertar(int pos, char * nombreDelAmigo, double dice){
	++numDeAmigos;
	if(pos==0){//Si es la relación con el mayor coeficiente de Dice.
		pushFront(nombreDelAmigo,dice);
	}
	else { 
		Celda * actual = primera;
	    int i = 0;//Guarda la posición del amigo en la lista.
	    //El 0 es para que empiece desde la primera celda.
	    while(actual && i < pos){
			++i;
		    actual = actual->siguiente;
	    }
		Celda * nueva = new Celda(nombreDelAmigo,dice);
		nueva->siguiente = actual;
		nueva->anterior = actual->anterior;
		actual->anterior = nueva;
		nueva->anterior->siguiente = nueva;
		//En estas instrucciones se coloca el nuevo amigo en la posicón ya dicha según su dice.
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