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

/**
 *Metodo para imprimir la selda
 *@param salida es una referencia a un ofstream
 */
void ListaDeUsuarios::Celda::imprimir(ofstream & salida){
	salida << "Nombre: " << usuario->getNombre() << endl;
	salida << "Numero de amigos: " << usuario->getNumeroDeAmigos() << endl;
	salida << "Cardinalidad: " << usuario->getCardinalidad() << endl;
	salida << "Amigos: ";
	usuario->mostrarAmigos(salida);
	salida << endl;
	//Si tiene un siguiente lo imprime
	if(siguiente){
		siguiente->imprimir(salida);
	}
}

/**
 *Metodo para agregar al final a un usuario nuevo
 *@param nombre es un puntero a un char que apunta al nombre del usuario por agregar
 */
void ListaDeUsuarios::pushBack(char * nombre){
	Celda * nueva = new Celda(nombre);
	nueva->anterior = ultima;
	//Si habia un ultimo ahora el nuevo esta despues
	if(ultima){
	   ultima->siguiente = nueva;	
	}
	else {//Si no habia ultima es el primer usuario en agregarse
		primera = nueva;
	}
	//El nuevo ahora es el ultimo
	ultima = nueva;
}

ListaDeUsuarios::ListaDeUsuarios(){
	primera = 0;
    	ultima = 0;
}

ListaDeUsuarios::~ListaDeUsuarios(){
	//Si tenia una primera
	if(primera){
		delete primera;
	}
}

/**
 *Metodo para agregar a un usuario a la lista si no estaba ya
 *@param nombre es un puntero a un char que apunta al nombre del usuario por agregar
 *@return agrego es un entero que vale 1 si el usuario fue agregado y 0 si no
 */
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

/**
 *Metodo para imprimir usuarios de la lista
 *@param salida es una referencia a un ofstream
 */
void ListaDeUsuarios::imprimir(ofstream & salida){
	//Si hay un primero lo imprime
	if(primera){
		primera->imprimir(salida);
	}
}

/**
 *Metodo para obtener el nombre de un usuario en una posicion de la lista
 *@param pos es un entero que indica la posicion del usuario en la lista
 *@return nombre es un puntero a char que apunta al nombre del usuario en la posicion
 */
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

/**
 *Metodo para saber si hay un usuario en la posicion
 *@param pos es un entero que indica la posicion del usuario en la lista
 *@return hay es un entero que vale 1 si hay un usuario en la posicion de la lista
 */
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

/**
 *Metodo para obtener la cardinalidad de un usuario
 *@param nombre es un puntero al nombre del usuario
 *@return cardinalidad del usuario
 */
double ListaDeUsuarios::getCardinalidadDeUsuario(char * nombre){
	Celda * actual = primera;
    while(!(actual->usuario->yaEsta(nombre))){//Mientras no haya encontrado al usuario solicitado.
	    actual = actual->siguiente;
    } 
	return actual->usuario->getCardinalidad();
	//Regrese cardinalidad de usuario solicitado.
}

/**
 *Metodo para agregar un amigo a un usuario especifico
 *@param dice es un double que indica el coeficiente de dice de la relacion de ambos, el usuario y el amigo
 *@param nombreDeAmigo es un puntero al nombre del amigo del usuario
 *@param nombreActual es un puntero que apunta al nombre del usuario
 */
void ListaDeUsuarios::agregarAmigoAUsuario(double dice, char * nombreDeAmigo,char * nombreActual){
	Celda * actual = primera;
    while(!(actual->usuario->yaEsta(nombreActual))){//Mientras no haya encontrado al usuario solicitado.
	    actual = actual->siguiente;
    } 
	actual->usuario->agregarAmigoAlUsuario(dice,nombreDeAmigo);
	//Regrese amigo de usuario solicitado.
}
