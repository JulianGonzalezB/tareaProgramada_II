#include "ListaDeUsuarios.h"

ListaDeUsuarios::Celda::Celda(char * nombre){
	anterior = 0;
	siguiente = 0;
	usuario = new Usuario(nombre);
}

ListaDeUsuarios::Celda::~Celda(){
	if(siguiente){
	   delete siguiente;	
	}
	delete usuario;
}

void ListaDeUsuarios::Celda::imprimir(ofstream & salida){
	salida << "Nombre: " << usuario->getNombre() << endl;
	salida << "Numero de amigos: " << usuario->getNumeroDeAmigos() << endl;
	salida << "Cardinalidad: " << usuario->getCardinalidad() << endl;
	salida << "Amigos: ";
	usuario->mostrarAmigos(salida);
	salida << endl;
	if(siguiente){
		siguiente->imprimir(salida);
	}
}

void ListaDeUsuarios::pushBack(char * nombre){
	Celda * nueva = new Celda(nombre);
	nueva->anterior = ultima;
	if(ultima){
	   ultima->siguiente = nueva;	
	}
	else {
		primera = nueva;
	}
	ultima = nueva;
}

ListaDeUsuarios::ListaDeUsuarios(){
	primera = 0;
    ultima = 0;
}

ListaDeUsuarios::~ListaDeUsuarios(){
	if(primera){
		delete primera;
	}
}

void ListaDeUsuarios::agregar(char * nombre){
	Celda * actual = primera;
	while(actual && !(actual->usuario->yaEsta(nombre))){
		actual = actual->siguiente;
	}
	if(!actual){
		pushBack(nombre);
	}
	else{
		cout<<endl;
		++(*(actual->usuario));
		actual = 0;
	}
}

void ListaDeUsuarios::imprimir(ofstream & salida){
	if(primera){
		primera->imprimir(salida);
	}
}

char * ListaDeUsuarios::getNombreDeUsuario(int pos){
	char * nombre = 0;
	Celda * actual = primera;
    int i = 0;
    while(actual && i < pos){
		++i;
	    actual = actual->siguiente;
    } 	   
	nombre = actual->usuario->getNombre(); 
	actual = 0;
	return nombre;
}

int ListaDeUsuarios::hayUsuario(int pos){
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

double ListaDeUsuarios::getCardinalidadDeUsuario(char * nombre){
	Celda * actual = primera;
    while(!(actual->usuario->yaEsta(nombre))){
	    actual = actual->siguiente;
    } 
	return actual->usuario->getCardinalidad();
}

void ListaDeUsuarios::agregarAmigoAUsuario(double dice, char * nombreDeAmigo,char * nombreActual){
	Celda * actual = primera;
    while(!(actual->usuario->yaEsta(nombreActual))){
	    actual = actual->siguiente;
    } 
	actual->usuario->agregarAmigoAlUsuario(dice,nombreDeAmigo);
}