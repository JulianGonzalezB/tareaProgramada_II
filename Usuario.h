#ifndef USUARIO
#define USUARIO
#include "ListaDeAmigos.h"

/**
 * Esta es la clase que se encarga de guardar los datos de cada usuario como el nombre, la cardinalidad y su lista de amigos.
 * @author (Julián , Javier Carmona,)
 * @version (01/05/2019)
 */
class Usuario{
	private:
		char * nombre;
		double cardinalidad;
		ListaDeAmigos * listaDeAmigos;
		
	public:
	    ~Usuario();
		Usuario(char *);
		/**
		 * Función: Se encarga de aumentar el valor de la cardinalidad del Usuario en los tuits en 1.
		 */
		void operator++();
		/**
		 * Función: Se encarga de mostrar en la salida recibida todos los amigos del usuario en su lista de amigos.
		 * @param salida Es una instancia de ofstream, y se utiliza para mostrar los amigos del usuario en esa salida.
		 */
		void mostrarAmigos(ofstream &);
		/**
		 * Función: Revisa que el nombre del usuario sea igual o diferente al recibido.
		 * @param nombreParam Es un puntero a un vector de char, guarda el nombre del que se va a revisar si es igual al usuario, y 
		 * se utiliza para eso, para revisar si el usuario se encuentra ya en la lista.
		 * @return iguales Es de tipo int, devuelve un 1 si el nombre es igual al usuario y un 0 si no, y se utiliza para 
		 * poder agregar al usuario si son diferentes, y si no solo se suma su cardinalidad.
		 */
		int yaEsta(char *);
		char * getNombre();
		int getNumeroDeAmigos();
		double getCardinalidad();
		/**
		 * Función: Se encarga de aumentar el valor de la cardinalidad del Usuario en los tuits en 1.
		 * @param dice Es de tipo double, guarda el coeficiente de Dice de la relación del usuario y el amigo, y se utiliza para
		 * saber en que orden va su amigo en su lista de amigos.
		 * @param nombreDeAmigo Es un puntero a un vector de char, guarda el nombre del amigo, y se utiliza para 
		 * guardarlo en su lista de amigos en orden según el dice de su relación con él.
		 */
		void agregarAmigoAlUsuario(double,char*);
};
#endif