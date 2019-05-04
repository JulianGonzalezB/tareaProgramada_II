#include "ListaDeRelaciones.h"

ListaDeRelaciones::Celda::Celda(char * nombre1, char * nombre2){
	anterior = 0;
	siguiente = 0;
	relacion = new Relacion(nombre1,nombre2);	
}

ListaDeRelaciones::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
	delete relacion;
}

ListaDeRelaciones::ListaDeRelaciones(){
   primera = 0;
   ultima = 0;
}
		
ListaDeRelaciones::~ListaDeRelaciones(){
	if(primera){
		delete primera;
	}
}

/**
 *Metodo para determinar si una relacion ya esta en la lista
 *@param nombre1 es un puntero a un char que apunta al nombre de un usuario
 *@param nombre2 es un puntero a un char que apunta al nombre de un usuario
 *@return agrego es un entero que vale 1 si fue agregada la relacion y 0 si no
 */
int ListaDeRelaciones::agregar(char * nombre1,char * nombre2){
	int agrego = 0;
	Celda * actual = primera;
	while(actual && !(actual->relacion->yaEsta(nombre1,nombre2))){
		//Mientras que haya siguiente celda y no este la relación.
		actual = actual->siguiente;
	}
	if(!actual){//Si no existía esa relación.
		agrego = 1;
		pushBack(nombre1,nombre2);
	}
	else{
		actual->relacion->aumentarNumeroIteraciones();
		actual = 0;
	}
	return agrego;
}

/**
 *Metodo para agregar al final de la lista una nueva relacion
 *@param nombre1 es un puntero a un char que apunta al nombre de un usuario
 *@param nombre2 es un puntero a un char que apunta al nombre de un usuario
 */
void ListaDeRelaciones::pushBack(char * nombre1, char * nombre2){
	Celda * nueva = new Celda(nombre1,nombre2);
	nueva->anterior = ultima;
	if(ultima){
	   ultima->siguiente = nueva;	
	}
	else {
		primera = nueva;
	}
	ultima = nueva;
}

/**
 *Metodo para identificar si una relacion esta en la lista en una posicion
 *@param pos es la posicion de la relacion en la lista
 *@return hay es un entero que indica si la relacion existe en la posicion
 */
int ListaDeRelaciones::hayRelacion(int pos){
	int hay = 0;
	Celda * actual = primera;
    int i = 0;//Guarda la posición de la relación en la lista.
	//El 0 es para que empiece desde la primera celda.
    while(actual && i < pos){//Mientras que haya siguiente celda y no llegue a la posición dada.
		++i;
	    actual = actual->siguiente;
    } 	 
    if(actual){//Si existe la relación en la posición dada en la lista.
		hay = 1;
	}	
	actual = 0;
	return hay;
}

/**
 *Metodo para determinar si un usuario esta en una relacion en una posicion en la lista
 *@param nombreParam es un puntero a char que apunta al nombre del amigo
 *@param por es la posicion
 *@return esta es un entero que vale 1 si el usuario esta en la relacion indicada y 0 si no
 */
int ListaDeRelaciones::esta(char * nombreParam,int pos){
	int esta = 0;
	Celda * actual = primera;
    int i = 0;//Guarda la posición de la relación en la lista.
	//El 0 es para que empiece desde la primera celda.
    while(actual && i < pos){//Mientras que haya siguiente celda y no llegue a la posición dada.
		++i;
	    actual = actual->siguiente;
    } 	 
	if(actual->relacion->esta(nombreParam)){
		//Si el usuario está en la relación de esa posición en la lista.
		esta = 1;
	}
	actual = 0;
	return esta;
}

/**
 *Metodo para obtener el numero de interacciones entre dos usuarios
 *@param pos es la posicion de la relacion en la lista
 *@return numDeInteracciones es un double que indica la cantidad de interacciones del usuario con el amigo en la relacion de la posicion en la lista
 */
double ListaDeRelaciones::getNumeroDeInteraccionesDeRelacion(int pos){
	Celda * actual = primera;
    int i = 0;//Guarda la posición de la relación en la lista.
	//El 0 es para que empiece desde la primera celda.
    while(actual && i < pos){//Mientras que haya siguiente celda y no llegue a la posición dada.
		++i;
	    actual = actual->siguiente;
    } 	 
	double numDeIteraciones = actual->relacion->getCantidadIteraciones();
	//Guardar iteraciones de relación.
	actual = 0;
	return numDeIteraciones;
}

/**
 *Metodo para obtener el nombre de un amigo de una relacion en una posicion de la lista
 *@param pos es un entero que indica la posicion de la relacion que se busca
 *@param nombreParam es un puntero a char que apunta al nombre del amigo a buscar
 *@return el nombre del amigo que se busca
 */
char * ListaDeRelaciones::getNombreDeAmigoDeRelacion(int pos,char * nombreParam){
	Celda * actual = primera;
    int i = 0;//Guarda la posición de la relación en la lista.
	//El 0 es para que empiece desde la primera celda.
    while(actual && i < pos){//Mientras que haya siguiente celda y no llegue a la posición dada.
		++i;
	    actual = actual->siguiente;
    } 	
	return actual->relacion->getNombreAmigo(nombreParam);
	//Regrese nombre del amigo de esa relación, según nombre recibido.
}
