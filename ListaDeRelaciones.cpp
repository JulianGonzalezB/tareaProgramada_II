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

void ListaDeRelaciones::agregar(char * nombre1 ,char * nombre2){
	Celda * actual = primera;
	while(actual && !(actual->relacion->yaEsta(nombre1,nombre2))){
		actual = actual->siguiente;
	}
	if(!actual){
		pushBack(nombre1,nombre2);
	}
	else{
		actual->relacion->aumentarNumeroIteraciones();
		actual = 0;
	}
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
    int i = 0;
    while(actual && i < pos){
		++i;
	    actual = actual->siguiente;
    } 	 
    if(actual){
		hay = 1;
	}	
	actual = 0;
	return hay;
}

int ListaDeRelaciones::esta(char * nombreParam,int pos){
	int esta = 0;
	Celda * actual = primera;
    int i = 0;
    while(actual && i < pos){
		++i;
	    actual = actual->siguiente;
    } 	 
	if(actual->relacion->esta(nombreParam)){
		esta = 1;
	}
	actual = 0;
	return esta;
}

double ListaDeRelaciones::getNumeroDeInteraccionesDeRelacion(int pos){
	Celda * actual = primera;
    int i = 0;
    while(actual && i < pos){
		++i;
	    actual = actual->siguiente;
    } 	 
	double numDeIteraciones = actual->relacion->getCantidadIteraciones();
	actual = 0;
	return numDeIteraciones;
}

char * ListaDeRelaciones::getNombreDeAmigoDeRelacion(int pos,char * nombreParam){
	Celda * actual = primera;
    int i = 0;
    while(actual && i < pos){
		++i;
	    actual = actual->siguiente;
    } 	
	return actual->relacion->getNombreAmigo(nombreParam);
}