#include "Generador.h"
#include "Buscador.h"
#include<string>
#include<iostream>
using namespace std;

/**
 * Función: Este es el método main que se encarga de empezar la ejecución del programa para generar las relaciones de los tuits, y poder realizar consultas. 
 * @param argc Es de tipo int, guarda la cantidad de parámetros recibidos al ejecutar el programa, y se utiliza para revisar que el usuario haya metido el número
 * correcto de parámetros, que solo sería el nombre del archivo que contiene los tuits.
 * @param argv Es un puntero que apunta a un vector de punteros de arreglos de tipo char, guarda el nombre del archivo de texto, y se utiliza para poder crear la entrada 
 * con el nombre del archivo, y poder generar las relaciones.
 * @return Retorna un 0 para que el sistema operativo termine la ejecución del programa.
 */
int main(int argc, char * * argv){
	if(argc > 1 && argc < 3){
		//Revisa que el usuario haya colocado el número correcto de parámetros.
		Generador * generador = new Generador(argv[1]);
		//El 1 es la posición donde va el nombre del archivo.
		generador->generarRelaciones();
		delete generador;
		//Pide al usuario si quiere buscar los n mejores amigos de un usuario
		char entrada[LARGO_ENTRADA];
		string contenedor;
		cout << "> Con este programa puedes consultar los n mejores amigos de un usuario" << endl;
		cout << "> Para consultar los n mejores amigos escriba:" << endl;
                cout << "> nombreDelUsuario n" << endl;
		cout << "> Para salir escriba 0" << endl;
		cout << "> ";
		//Obtiene la respuesta
		getline(cin, contenedor);
		strcpy(entrada, contenedor.c_str());
		cout << endl;
		//Mientras la respuesta no sea Salir
		while(!(strlen(entrada) == 1 && entrada[0] == '0')){
		
			//Crea al buscador y le pasa la entrada al buscador
			Buscador * buscador= new Buscador(entrada);
			//El buscador imprime su resultado
			//Destruir buscador
			delete buscador;

			//Lee de nuevo la entrada
			cout << "> Para consultar n mejores amigos:" << endl;
			cout << "> nombreDelUsuario n" << endl;
               		cout << "> Para salir: 0" << endl;
			cout << "> ";
			//Espera la entrada
			//Obtiene la respuesta
                	getline(cin, contenedor);
                	strcpy(entrada, contenedor.c_str());
		}
		//Sale
		cout << "Bye!" << endl;
	}
	else{
		cout << "Error al cargar archivo o metio mas parametros" << endl;
	}
	return 0;
}
