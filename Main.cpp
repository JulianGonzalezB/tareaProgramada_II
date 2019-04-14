#include "ListaTuits.h"
#include "Tuit.h"
#include <string>

int main(){

	Tuit * listaUsuarios = new Tuit();

	ListaTuits * listaTuits= new ListaTuits();

	//Leer el tuit
	
	//Sacar los usuarios sin repetidos
	
	//Meter al tuit en la lista de tuits
	
	//Meter a los usuarios en su tuit
	
	//Mete a los usuarios de cada tuit en la lista de usuarios
	
	//Construir la matriz
		//Las dimensiones de la matriz se le pueden pedir a la lista de usuarios sin repetir que deberia ser un tuit pero es porque los tuits ya son una lista de usuarios
	
	int usuariosTotales = listaTuits->getNumeroDeUsuarios();

	int * * matrizRelaciones[usuariosTotales];

	for(int fila = 0; fila < usuariosTotales; ++fila){
	
		matrizRelaciones[fila]= new int * [usuariosTotales];
	}

	
	//Buscar cada usuario en de la lista de usuarios en cada tuit
		//Si el usuario esta en el tuit entonces revisa todos los demas usuarios en ese tuit y aumenta en la matriz de relacion  +1
	

	//Calcular la matriz de dice
	
	//Borrar las dos listas
	
	delete listaUsuarios;

	delete listaTuits;

	//Borrar las dos matrices
	
	return 0;
}
