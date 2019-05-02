#ifndef GENERADOR
#define GENERADOR
#define MAX_BUFFER_SIZE 10000
#include "ListaDeRelaciones.h"
#include "ListaDeUsuarios.h"
#include<fstream>
#include<iostream>
using namespace std;

/**
 * Esta es la clase que se encarga de crear las relaciones y las listas de amigos de cada usuario de la lista de usuarios (también creada por esta).
 * Esto mediante diversos métodos y atributos, y con la ayuda de las clases adjuntas en la carpeta.
 * @author (Julián , Javier Carmona,)
 * @version (01/05/2019)
 */
class Generador{
	private:
		ListaDeRelaciones * listaDeRelaciones;
		ListaDeUsuarios * listaDeUsuarios;
		ifstream * entradaTuits;
		ofstream * salida;
		/**
		 * Función: Este se encarga de guardar cada usuario del tuit en revisión, y guardar cada una de sus relaciones sin repeticiones de ningún tipo.
		 * @param tuit Es un puntero a un vector de char, guarda el tuit en revisión como un vector de caracteres, y se utiliza para encontrar cada usuario y sus relaciones
		 * y guardarlas en listas.
		 */
		void agregarUsuariosYRevisarRelaciones(char *);
		/**
		 * Función: Se encarga de guardar las relaciones del usuario en revisión en la lista de relaciones.
		 * @param actual Es un puntero a un vector de char, guarda el nombre del usuario al que se le están revisando sus relaciones, y
		 * y se utiliza para crear la relaciones de este con los nombres que tiene a su derecha en el tuit (sus amigos).
		 * @param tuit Es un puntero a un vector de caracteres, guarda el tuit en revisión, y se utiliza para encontrar las relaciones del usuario en revisión
		 * guardándolas en la lista de relaciones sin repetir.
		 * @param pos Es de tipo int, guarda la posición desde donde se revisan los amigos del usuario en revisión, y se utiliza para eso
		 * para ir revisando los amigos en el tuit y generar su lista de amigos.
		 * @param listaDeRelaciones Es un puntero a una instancia de ListaDeRelaciones, guarda las relaciones que se han hecho en el tuit sin repetir, y se utiliza
		 * para que no se repitan relaciones de un mismo tuit y no afecte el cálculo del dice al final.
		 */
		void agregarRelaciones(char *, char *, int, ListaDeRelaciones *);
		/** 
		 * Función: Este se encarga de que para cada usuario de la lista de usuarios se le agreguen sus amigos en orden utilizando la lista de relaciones.
		 */
		void generarListasDeAmigos();
		/**
		 * Función: Se utiliza para calcular el Coeficiente de Dice a la hora de agregar el amigo del usuario en revisión.
		 * @param numeroDeIteraciones Es de tipo double, guarda el número de iteraciones en que el usuario en revisión y el amigo aparecen juntos, 
		 * y se utiliza para el cálculo del dice de esa relación.
		 * @param nombreDeAmigo Es un puntero a un vector de char, guarda el nombre del amigo del usuario en revisión, y se utiliza para obtener su cardinalidad 
		 * y calcular el dice de esa relación.
		 * @param nombreActual Es un puntero a un vector de char, guarda el nombre del usuario en revisión, y se utiliza para obtener su cardinalidad 
		 * y calcular el dice de esa relación.
		 * @return Regresa un double que va a ser el valor del dice de la relación, y se va a utilizar para guardar el amigo del usuario en revisión en orden.
		 */
		double calcularDice(double,char*,char*);
		/**
		 * Función: Se utiliza para ver si dos vectores de caracteres son iguales.
		 * @param nombreA Es un puntero a un vector de caracteres, guarda uno de los nombres para comparar, y se utiliza para eso,
		 * para compararlo con nombreB y ver si son iguales.
		 * @param nombreB Es un puntero a un vector de caracteres, guarda uno de los nombres para comparar, y se utiliza para eso,
		 * para compararlo con nombreA y ver si son iguales.
		 * @return iguales Es de tipo int, devuelve un 1 si los char[] son iguales y un 0 si no, y se utiliza para que en la lista de relaciones el usuario
		 * y su amigo no sean iguales.
		 */
		int sonIguales(char*,char*);
	public:
		Generador(char *);
		~Generador();
		/**
		 * Función: Es la que se encarga de generar las relaciones de cada tuit y guardar cada usuario.
		 */
		void generarRelaciones();
};
#endif