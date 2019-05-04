#include "Usuario.h"

/**
 *Constructor de la clase
 *@param nombreParam es un puntero al nombre del usuario
 */
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

/**
 *Metodo para aumentar la cardinalidad del usuario
 */
void Usuario::operator++(){
	++cardinalidad;
}

/**
 *Metodo para imprimir a los amigos del usuario
 *@param salida es una referencia a un ofstream
 */
void Usuario::mostrarAmigos(ofstream & salida){
	listaDeAmigos->imprimir(salida);//Imprime su lista de amigos.
}

/**
 *Metodo para saber si el nombre del usuario a agregar a la lista es el nombre de este usuario
 *@param nombreParam es un puntero al nombre que se quiere comparar
 *@return iguales es 1 si el nombre coincide con el nombreParamy 0 si no
 */
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

/**
 *Metodo para obtener el nombre del usuario
 *@return nombre es el nombre del usuario
 */
char * Usuario::getNombre(){
	return nombre;
}

/**
 *Metodo para obtener el numero de amigos de este usuario
 *@return devuelve la cantidad de amigos en la lista de este usuario
 */
int Usuario::getNumeroDeAmigos(){
	return listaDeAmigos->getCantidadDeAmigos();
	//Regresa la cantidad de amigos del usuario.
}

/**
 *Metodo para obtener la cardinalidad del usuario
 *@return cardinalidad es la cardinalidad del usuario
 */
double Usuario::getCardinalidad(){
	return cardinalidad;
}

/**
 *Metodo para agregar un amigo
 *@param dice es un double que indica el coeficiente de relacion con ese amigo de este usuario
 *@param nombreDeAmigo es un puntero al nombre del amigo a agregar
 */
void Usuario::agregarAmigoAlUsuario(double dice, char * nombreDeAmigo){
	listaDeAmigos->agregar(dice,nombreDeAmigo);
	//Agrega un nuevo amigo y su dice a su lista de amigos.
}
