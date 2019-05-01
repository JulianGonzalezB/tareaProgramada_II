#include "Generador.h"
#include "Buscador.h"
#define LARGO_ENTRADA 40
#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char * * argv){
	if(argc > 1 && argc < 3){
		Generador * generador = new Generador(argv[1]);
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
		cout << "Error al cargar archivo" << endl;
	}
	return 0;
}
