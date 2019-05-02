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

int ListaDeUsuarios::agregar(char * nombre){
	int agrego = 0;
	Celda * actual = primera;
	while(actual && !(actual->usuario->yaEsta(nombre))){
		//Mientras que haya siguiente y no encuentre el nombre en la lista.
		actual = actual->siguiente;
	}
	if(!actual){//Si no estaba ese usuario.
		agrego = 1;
		pushBack(nombre);
	}
	else{
		++(*(actual->usuario));//Aumente la cardinalidad del usuario.
		actual = 0;
	}
	return agrego;
}

void ListaDeUsuarios::imprimir(ofstream & salida){
	if(primera){
		primera->imprimir(salida);
	}
}

char * ListaDeUsuarios::getNombreDeUsuario(int pos){
	char * nombre = 0;
	Celda * actual = primera;
    int i = 0;//Guarda la posición del usuario en la lista.
	//El 0 es para que empiece desde la primera celda.
    while(actual && i < pos){//Mientras haya siguiente y no llegue a la posición requerida.
		++i;
	    actual = actual->siguiente;
    } 	   
	nombre = actual->usuario->getNombre();//Guarde nombre de usuario solicitado por posición.
	actual = 0;
	return nombre;
}

int ListaDeUsuarios::hayUsuario(int pos){
	int hay = 0;
	Celda * actual = primera;
    int i = 0;//Guarda la posición del usuario en la lista.
	//El 0 es para que empiece desde la primera celda.
    while(actual && i < pos){
		++i;
	    actual = actual->siguiente;
    } 	 
    if(actual){//Si hay Usuario en esa posición en la lista.
		hay = 1;
	}	
	actual = 0;
	return hay;
}

double ListaDeUsuarios::getCardinalidadDeUsuario(char * nombre){
	Celda * actual = primera;
    while(!(actual->usuario->yaEsta(nombre))){//Mientras no haya encontrado al usuario solicitado.
	    actual = actual->siguiente;
    } 
	return actual->usuario->getCardinalidad();
	//Regrese cardinalidad de usuario solicitado.
}

void ListaDeUsuarios::agregarAmigoAUsuario(double dice, char * nombreDeAmigo,char * nombreActual){
	Celda * actual = primera;
    while(!(actual->usuario->yaEsta(nombreActual))){//Mientras no haya encontrado al usuario solicitado.
	    actual = actual->siguiente;
    } 
	actual->usuario->agregarAmigoAlUsuario(dice,nombreDeAmigo);
	//Regrese amigo de usuario solicitado.
}