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
		++(*(actual->relacion));
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