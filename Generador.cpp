#include "Generador.h"

Generador::Generador(char * nombreArchivoTuits){
	listaDeRelaciones = 0;
	listaDeUsuarios = 0;
	entradaTuits = new ifstream(nombreArchivoTuits);
	salida = 0; 
	if(*entradaTuits){//Revisa que el archivo exista.
		listaDeRelaciones = new ListaDeRelaciones();
		listaDeUsuarios = new ListaDeUsuarios();
		salida = new ofstream((char*)"Relaciones.txt");//Crea el archivo de salida.
	}
	else{
		cout << "Error al cargar archivo inexistente" << endl;
	}
}

Generador::~Generador(){
	if(salida){
		delete salida;
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
	if(*entradaTuits){//Revisa que el archivo exista.
		entradaTuits->get();
		if(!entradaTuits->eof()){	
			entradaTuits->seekg(0);
			//El 0 es para regresar a la posición inicial de la entrada del archivo.
			//Revisa que el archivo no venga vacío.
			while(!entradaTuits->eof()){//Mientras que hayan tuits.
				char buffer[MAX_BUFFER_SIZE];//Este guarda el tuit en un vector de char.
				entradaTuits->getline(buffer, MAX_BUFFER_SIZE);//Guarda tuit en un vector de char.
				agregarUsuariosYRevisarRelaciones(buffer);
			}
			generarListasDeAmigos();
			listaDeUsuarios->imprimir(*salida);//Genera archivo de relaciones.
		}
		else{
			cout << "Error al cargar archivo vacio" << endl;
		}
	}
}

void Generador::generarListasDeAmigos(){
	int pos = 0;//Se usa para revisar cada usuario de la lista.
	//El 0 es para revisar desde el inicio.
	while(listaDeUsuarios->hayUsuario(pos)){//Mientras haya un usuario en la lista.
		char * nombreActual = listaDeUsuarios->getNombreDeUsuario(pos);//Guarda nombre de usuario en revisión.
		int posRel = 0;//Se usa para revisar cada relación de la lista con el usuario.
		//El 0 es para revisar desde el inicio.
		while(listaDeRelaciones->hayRelacion(posRel)){//Mientras haya relación.
			if(listaDeRelaciones->esta(nombreActual,posRel)){
				//Si el usuario en revisión está en esa relación en revisión.
				double numeroDeIteraciones = listaDeRelaciones->getNumeroDeInteraccionesDeRelacion(posRel);
				//Guarde número de iteraciones de esa relación.
				char * nombreDeAmigo = listaDeRelaciones->getNombreDeAmigoDeRelacion(posRel,listaDeUsuarios->getNombreDeUsuario(pos));
				//Guarde el nombre del amigo de esa relación.
				double dice = calcularDice(numeroDeIteraciones,nombreDeAmigo,nombreActual);
				listaDeUsuarios->agregarAmigoAUsuario(dice,nombreDeAmigo,nombreActual);
				//Agregue el amigo y su dice a la lista de amigos del usuario en revisión.
				nombreDeAmigo = 0;
			}
			posRel++;
		}
		nombreActual = 0;
		++pos;
	}
}

double Generador::calcularDice(double numeroDeIteraciones,char * nombreDeAmigo,char * nombreActual){
	return (2.0 * numeroDeIteraciones) / (listaDeUsuarios->getCardinalidadDeUsuario(nombreDeAmigo) + listaDeUsuarios->getCardinalidadDeUsuario(nombreActual));
	//Calcular el dice de la relación en revisión.
}

void Generador::agregarUsuariosYRevisarRelaciones(char * tuit){
	ListaDeUsuarios * listaDeRevision = new ListaDeUsuarios();
	//Se utiliza para que se revise que no se repiten usuarios en revisión.
	ListaDeRelaciones * listaDeRevisionRel = new ListaDeRelaciones();
	//Se utiliza para que no hayan relaciones repetidas en un mismo tuit y afecte el dice.
	int i = 0;//i es la posición donde está revisando en tuit.
	while(tuit[i] != '\0'){//Mientras no haya llegado al final del tuit.
		if((i == 0 && tuit[i] == '@' && tuit[i + 1] != ' ' && tuit[i + 1] != '\0') || (tuit[i] == '@' && tuit[i - 1] == ' ' && tuit[i + 1] != ' ' && tuit[i + 1] != '\0')){
			//Revisa que haya un usuario.
			int tamano = 0;//Guarda el tamaño del usuario encontrado.
			int inicial = i;//Guarda donde inicia el usuario en el vector de char.
			while(tuit[i] != ' ' && tuit[i] != '\0'){//Mientras no haya llegado al final de la palabra.
				++tamano;
				++i;
			}
			char * actual = new char[tamano + 1];
			//Crea un nuevo vector donde va el nombre del usuario en revisión.
			for(int j = 0; j < tamano; ++j){//Copia el nombre en actual desde tuit.
			   actual[j] = tuit[inicial];
			   ++inicial;
			}
			actual[tamano] = '\0';
			if(listaDeRevision->agregar(actual)){//Si el usuario no se ha revisado.
				listaDeUsuarios->agregar(actual);
			    agregarRelaciones(actual,tuit,i,listaDeRevisionRel);
			}
			delete actual;
		}
		else{
			++i;
		}
	}
	delete listaDeRevision;
	delete listaDeRevisionRel;
}

void Generador::agregarRelaciones(char * actual, char * tuit, int pos,ListaDeRelaciones * listaDeRevisionRel){
	while(tuit[pos] != '\0'){//Mientras no haya llegado al final del tuit.
		if(tuit[pos] == '@' && tuit[pos - 1] == ' ' && tuit[pos + 1] != ' ' && tuit[pos + 1] != '\0'){//Si encuentra un amigo.
			int tamano = 0;//Guarda el tamaño del amigo encontrado.
			int inicial = pos;//Guarda donde inicia el amigo en el vector de char.
			while(tuit[pos] != ' ' && tuit[pos] != '\0'){//Mientras no haya llegado al final de la palabra.
				++tamano;
				++pos;
			}
			char amigo[tamano + 1];//Crea un nuevo vector donde va el nombre del amigo en revisión.
			for(int j = 0; j < tamano; ++j){//Copia el nombre en actual desde tuit.
			   amigo[j] = tuit[inicial];
			   ++inicial;
			}
			amigo[tamano] = '\0';
			if(!sonIguales(actual,amigo)){//Si el amigo y el usuario no son iguales.
				if(listaDeRevisionRel->agregar(actual,amigo)){//Si esa relación no estaba.
					listaDeRelaciones->agregar(actual,amigo);
				}
			}
		}
		else{
			++pos;
		}
	}
}

int Generador::sonIguales(char * nombreA,char * nombreB){
	int iguales = 0;
	int i = 0;//Guarda la posición del caracter en revsión de cada nombre.
	while(nombreA[i] == nombreB[i]){//Mientras que los caracteres coincidan.
		if(nombreA[i] == '\0' && nombreB[i] == '\0'){//Si son iguales hasta el final.
			iguales = 1;
		}
		++i;
	}
	return iguales;
}