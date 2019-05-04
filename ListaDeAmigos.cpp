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
	//Si tiene una celda siguiente
	if(siguiente){
	   delete siguiente;	
	}
	delete [] nombreDelAmigo;
}

/**
 *Metodo para imprimir
 *@param salida es una referencia a un ofstream al que se imprimira
 */
void ListaDeAmigos::Celda::imprimir(ofstream & salida){
	salida << nombreDelAmigo<< " ";
	if(siguiente){
		siguiente->imprimir(salida);
	}
}

/**
 *Metodo para agregar a un nuevo amigo al final de la lista
 *@param nombreDelAmigo es un puntero a un char que apunta al nombre del amigo a agregar
 *@param dice es un double que indica el coeficiente de dice de la relacion
 */
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
	//Inicializacion
	numDeAmigos = 0;
	primera = 0;
	ultima = 0;
}

ListaDeAmigos::~ListaDeAmigos(){
	//Si hay una primera celda
	if(primera){
		delete primera;
	}
}

/**
 *Metodo para solicitar a la lista de amigos que agregue a un amigo nuevo
 *@param diceParam es un double que indica el coeficiente de dice de la relacion con el nuevo amigo
 *@param nombreDelAmigoParam es un puntero a char que apunta al nombre del amigo nuevo
 */
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

/**
 *Metodo para insertar un amigo en orden de relacion
 *@pos es un entero que indica la posicion en la lista
 *@param nombreDelAmigo es un puntero a char que apunta al nombre del amigo nuevo
 *@param dice es un double que indica el coeficiente de dice de la relacion con el nuevo amigo
 */
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

/**
 *Metodo para agregar al frente a un amigo en la lista
 *@param nombreDelAmigo es un puntero a char que apunta al nombre del amigo nuevo
 *@param dice es un double que indica el coeficiente de dice de la relacion con el nuevo amigo
 */
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

/**
 *Metodo para imprimir la lista de amigos
 *@param salida es una referencia a un ofstream
 */
void ListaDeAmigos::imprimir(ofstream & salida){
	if(primera){
		primera->imprimir(salida);
	}
}
/**
 *Metodo para obtener el numero de amigos en la lista
 *@return numDeAmigos es un entero que indica el numero de amigos en la lista
 */
int ListaDeAmigos::getCantidadDeAmigos(){
	return numDeAmigos;
}
