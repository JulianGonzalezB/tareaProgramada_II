#include "Generador.h"
#include "Buscador.h"
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char * * argv){
	if(argc > 1 && argc < 3){
		Generador * generador = new Generador(argv[1]);
		generador->generarRelaciones();
		delete generador;
		
		//Pide al usuario si quiere buscar los n mejores amigos de un usuario
		string entrada;
		cout << "> Con este programa puedes consultar los n mejores amigos de un usuario. Para hacerlo sigue las siguientes instrucciones." << endl;
		cout << "> Realizar consulta: nombreDelUsuario n" << endl;
		cout << "> Salir= 0" << endl;
		cout << "> ";
		//Obtiene la respuesta
		getline(cin, entrada);
		cout << endl;
		//Mientras la respuesta no sea Salir
		while(stoi(entrada)){
		
			//Crea al buscador y le pasa la entrada al buscador
			Buscador * buscador= new Buscador(entrada);
			//El buscador imprime su resultado
			//Destruir buscador
			delete buscador;

			//Lee de nuevo la entrada
			cout << "> Realizar consulta: nombreDelUsuario numeroDeAmigos" << endl;
                	cout << "> Salir= 0" << endl;
                	cout << "> ";
			cin >> entrada;
			cout << endl;
		}
		
		//Sale
		cout << "Bye!" << endl;
	}
	else{
		cout << "Error al cargar archivo" << endl;
	}
	return 0;
}
