#ifndef LISTA_DE_AMIGOS
#define LISTA_DE_AMIGOS
#include <fstream>
#include <iostream>
using namespace std;

/**
 * Esta es la clase que se encarga de guardar a los amigos de un usuario en una lista de amigos.
 * @author (Julián , Javier Carmona,)
 * @version (01/05/2019)
 */
class ListaDeAmigos{
	class Celda;
    private:
		Celda * primera;
	    Celda * ultima;
		int numDeAmigos;

		class Celda{
			public:
				Celda * anterior;
				Celda * siguiente;
				char * nombreDelAmigo;
				double dice;
				Celda(char *, double);
				~Celda();
				/**
		         * Función: Se encarga de mostrar en la salida recibida cada amigo del usuario en esta lista.
		         * @param salida Es una instancia de ofstream, y se utiliza para mostrar los amigos del usuario en esa salida.
		         */
				void imprimir(ofstream &);
	    };
		/**
		 * Función: se encarga de agregar una nuevo amigo a la lista al final por ser el menos relacionado.
		 * @param nombreDelAmigo Es un puntero a un vector de char, guarda el nombre del amigo que se va a agregar, y se utiliza para guardar ese nombre en la 
		 * su lista y poder realizar luego las consultas.
		 * @param dice Es de tipo double, guarda el dice de la relación con el amigo, y se utiliza para guardar ese coeficiente 
		 * y revisar luego las otras relaciones comparar y ordenar los amigos según el dice.
		 */
		void pushBack(char *, double);
		/**
		 * Función: Se encarga de colocar al nuevo amigo en la lista en una posición ya decidida.
		 * @param pos Es de tipo int, guarda la posición donde va a ir el nuevo amigo.
		 * @param nombreDelAmigo Es un puntero a un vector de char, guarda el nombre del amigo que se va a agregar, y se utiliza para guardar ese nombre en la 
		 * su lista y poder realizar luego las consultas.
		 * @param dice Es de tipo double, guarda el dice de la relación con el amigo, y se utiliza para guardar ese coeficiente 
		 * y revisar luego las otras relaciones comparar y ordenar los amigos según el dice.
		 */
		void insertar(int,char *,double);
		/**
		 * Función: se encarga de agregar una nuevo amigo a la lista al inicio por ser el más relacionado.
		 * @param nombreDelAmigo Es un puntero a un vector de char, guarda el nombre del amigo que se va a agregar, y se utiliza para guardar ese nombre en la 
		 * su lista y poder realizar luego las consultas.
		 * @param dice Es de tipo double, guarda el dice de la relación con el amigo, y se utiliza para guardar ese coeficiente 
		 * y revisar luego las otras relaciones comparar y ordenar los amigos según el dice.
		 */
		void pushFront(char * , double);
	public:
		ListaDeAmigos();
		~ListaDeAmigos();
		/**
		 * Función: se encarga de agregar una nuevo amigo a la lista en orden.
		 * @param diceParam Es de tipo double, guarda el dice de la relación con el amigo, y se utiliza para guardar ese coeficiente 
		 * y revisar luego las otras relaciones comparar y ordenar los amigos según el dice.
		 * @param nombreDelAmigoParam Es un puntero a un vector de char, guarda el nombre del amigo que se va a agregar, y se utiliza para guardar ese nombre en la 
		 * su lista y poder realizar luego las consultas.
		 */
		void agregar(double,char*);
		/**
		 * Función: Se encarga de mostrar en la salida recibida todos los amigos del usuario en esta lista.
		 * @param salida Es una instancia de ofstream, y se utiliza para mostrar los amigos de la lista en esa salida.
		 */
		void imprimir(ofstream &);
		int getCantidadDeAmigos();
};
#endif