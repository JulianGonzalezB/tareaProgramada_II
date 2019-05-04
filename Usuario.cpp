#include "Usuario.h"

Usuario::Usuario(char * nombreParam){
	int tamanoNombre = 0;
	while(nombreParam[tamanoNombre] != '\0'){
		++tamanoNombre;
	}
	//Este while calcula el tamaño del nombre que se va a agregar al usuario.
	nombre = new char[++tamanoNombre];
	for(int j = 0; j < tamanoNombre; ++j){
	   nombre[j] = nombreParam[j];
	}
	//Este for copia el nombre que se va a agregar al usuario.
	cardinalidad = 1;
	//Se inicializa en 1 ya que cuando se crea un usuario ya aparece en los tuits por lo menos 1 vez.
	listaDeAmigos = new ListaDeAmigos();
}

Usuario::~Usuario(){
	delete [] nombre;
	delete listaDeAmigos;
}

void Usuario::operator++(){
	++cardinalidad;
}

void Usuario::mostrarAmigos(ofstream & salida){
	listaDeAmigos->imprimir(salida);//Imprime su lista de amigos.
}

int Usuario::yaEsta(char * nombreParam){
	int iguales = 0;
	int i = 0;//Guarda la posición del caracter en revsión de cada nombre.
	while(!iguales && nombre[i] == nombreParam[i]){//Mientras que los caracteres coincidan.
		if(nombre[i] == '\0' && nombreParam[i] == '\0'){//Si son iguales hasta el final.
			iguales = 1;
		}
		++i;
	}
	return iguales;
}

char * Usuario::getNombre(){
	return nombre;
}

int Usuario::getNumeroDeAmigos(){
	return listaDeAmigos->getCantidadDeAmigos();
	//Regresa la cantidad de amigos del usuario.
}

double Usuario::getCardinalidad(){
	return cardinalidad;
}

void Usuario::agregarAmigoAlUsuario(double dice, char * nombreDeAmigo){
	listaDeAmigos->agregar(dice,nombreDeAmigo);
	//Agrega un nuevo amigo y su dice a su lista de amigos.
}
