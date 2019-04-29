#include "Generador.h"

Generador::Generador(char * nombreArchivoTuits){
	listaDeRelaciones = 0;
	listaDeUsuarios = 0;
	entradaTuits = new ifstream(nombreArchivoTuits);
	entradaRelaciones = 0;
	salida = 0; 
	if(entradaTuits){
		listaDeRelaciones = new ListaDeRelaciones();
		listaDeUsuarios = new ListaDeUsuarios();
		salida = new ofstream((char*)"Relaciones.txt");
	}
	else{
		cout << "Error al cargar archivo inexistente" << endl;
	}
}

Generador::~Generador(){
	if(salida){
		delete salida;
	}
	if(entradaRelaciones){
		delete entradaRelaciones;
	}
	if(listaDeUsuarios){
		delete listaDeUsuarios;
	}
	if(listaDeRelaciones){
		delete listaDeRelaciones;
	}
	if(entradaTuits){
		delete entradaTuits;
	}
}

void Generador::generarRelaciones(){
	if(entradaTuits){
		entradaTuits->get();
		if(!entradaTuits->eof()){	
			entradaTuits->seekg(0);
			while(!entradaTuits->eof()){
				char buffer[MAX_BUFFER_SIZE]; 
				entradaTuits->getline(buffer, MAX_BUFFER_SIZE);
				agregarUsuariosYRevisarRelaciones(buffer);
			}
			generarListasDeAmigos();
		}
		else{
			cout << "Error al cargar archivo vacio" << endl;
		}
	}
}

void Generador::generarListasDeAmigos(){
	
}

void Generador::agregarUsuariosYRevisarRelaciones(char * tuit){
	int i = 0;
	while(tuit[i] != '\0'){
		if((i == 0 && tuit[i] == '@') || (tuit[i] == '@' && tuit[i - 1] == ' ' && tuit[i + 1] != ' ' && tuit[i + 1] != '\0')){
			int tamano = 0;
			int inicial = i;
			while(tuit[i] != ' ' && tuit[i] != '\0'){
				++tamano;
				++i;
			}
			char * actual = new char[tamano + 1];
			for(int j = 0; j < tamano; ++j){
			   actual[j] = tuit[inicial];
			   ++inicial;
			}
			actual[tamano] = '\0';
			listaDeUsuarios->agregar(actual);
			agregarRelaciones(actual,tuit,i);
			delete actual;
		}
		++i;
	}
}

void Generador::agregarRelaciones(char * actual, char * tuit, int pos){
	while(tuit[pos] != '\0'){
		if(tuit[pos] == '@' && tuit[pos - 1] == ' ' && tuit[pos + 1] != ' ' && tuit[pos + 1] != '\0'){
			int tamano = 0;
			int inicial = pos;
			while(tuit[pos] != ' ' && tuit[pos] != '\0'){
				++tamano;
				++pos;
			}
			char amigo[tamano + 1];
			for(int j = 0; j < tamano; ++j){
			   amigo[j] = tuit[inicial];
			   ++inicial;
			}
			amigo[tamano] = '\0';
			listaDeRelaciones->agregar(actual,amigo);
		}
		++pos;
	}
}