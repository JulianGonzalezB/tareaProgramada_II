#ifndef LISTA_DE_RELACIONES
#define LISTA_DE_RELACIONES
#include "Relacion.h"
#include<iostream>
using namespace std;

/**
 * Esta es la clase que se encarga de guardar las relaciones de los tuits en lista.
 * Esto mediante diversos métodos y atributos, y con la ayuda de las clases adjuntas en la carpeta, como Relacion.
 * @author (Julián, Javier Carmona)
 * @version (01/05/2019)
 */
class ListaDeRelaciones{
	class Celda;
    private:
		Celda * primera;
	    Celda * ultima;

		class Celda{
			public:
				Celda * anterior;
				Celda * siguiente;
				Relacion * relacion;
				Celda(char *, char *);
				~Celda();
	    };
		/**
		 * Función: se encarga de agregar una nueva relación al final de la lista.
		 * @param nombre1 Es un puntero a un vector de char, guarda uno de los nombres, y se utiliza para guardar ese nombre en la 
		 * relación y poder guardar luego sus amigos de ese usuario.
		 * @param nombre2 Es un puntero a un vector de char, guarda uno de los nombres, y se utiliza para guardar ese nombre en la 
		 * relación y poder guardar luego sus amigos de ese usuario.
		 */
		void pushBack(char *, char *);
		
	public:
		ListaDeRelaciones();
		~ListaDeRelaciones();
		/**
		 * Función: Se utiliza para agregar una nueva relación en la lista o, si ya está, sumarle 1 al número de apariciones de esa relación.
		 * @param nombre1 Es un puntero a un vector de char, guarda uno de los nombres, y se utiliza para guardar ese nombre en la 
		 * relación, o sumarle a la relación si ya existe, y poder guardar luego sus amigos de ese usuario.
		 * @param nombre2 Es un puntero a un vector de char, guarda uno de los nombres, y se utiliza para guardar ese nombre en la 
		 * relación, o sumarle a la relación si ya existe, y poder guardar luego sus amigos de ese usuario.
		 * @return agrego Es de tipo int, devuelve un 0 si la relación ya estaba y un 1 si no, 
		 * y se utiliza para que no hayan relaciones repetidas de un mismo tuit.
		 */
		int agregar(char *,char *);
		/**
		 * Función: Se encarga de revisar si existe una relación en la lista en la posición dada.
		 * @param pos Es de tipo int, guarda el valor de la posición de la relación que se va a revisar, y se utiliza para
		 * revisar si hay alguna relación en esa posición en la lista.
		 * @return hay Es de tipo int, devuelve un 0 si existe una relación en esa posición en la lista y un 1 si no, 
		 * y se utiliza para ir revisando cada relación hasta el final de la lista de acuerdo al usuario en revsión.
		 */
		int hayRelacion(int);
		/**
		 * Función: Se encarga de revisar si un usuario se encuentra la relación de la lista que indica la posición.
		 * @param nombreParam Es un puntero a un vector de char, guarda el nombre del usuario en revisión, y se utiliza para
		 * saber si el usuario se encuentra en esa relación.
		 * @param pos Es de tipo int, guarda el valor de la posición de la relación que se va a revisar, y se utiliza para
		 * revisar si el usuario se encuentra en esa relación y obtener información de esta relación.
		 * @return esta Es de tipo int, devuelve un 0 si el usuario está en esa relación y un 1 si no, 
		 * y se utiliza para poder agregar al amigo a su lista de amigos, y calcular el dice de esa relación de acuerdo al usuario en revisión.
		 */
		int esta(char *,int);
		double getNumeroDeInteraccionesDeRelacion(int);
		char * getNombreDeAmigoDeRelacion(int,char *);
};
#endif