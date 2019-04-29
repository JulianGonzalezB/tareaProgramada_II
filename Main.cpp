#include "Generador.h"
#include<iostream>
using namespace std;

int main(int argc, char * * argv){
	if(argc > 1 && argc < 3){
		Generador * generador = new Generador(argv[1]);
		generador->generarRelaciones();
		delete generador;
	}
	else{
		cout << "Error al cargar archivo" << endl;
	}
	return 0;
}