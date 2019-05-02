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