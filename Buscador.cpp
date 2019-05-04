#include "Buscador.h"
#include<iostream>
#include<string>
#define NUM_MAX_CHAR_POR_LINEA 300
#define NUMERO_ETIQUETAS 4
using namespace std;

Buscador::Buscador(char entradaOriginal []){

	mensajeError= "Error: Formato invalido. Debe ingresar un numero de mejores amigos";

	//Revisa la entrada con la copia
	if(revisarEntrada(entradaOriginal)){
	
		buscar();
	}
}

Buscador::~Buscador(){
}

/**
 *Metodo para verificar si la entrada introducida tiene el formato correcto
 *@param entrada es un arreglo de chars que contiene la entrada
 *@return entradaValida es 1 si la consulta tiene el formato correcto y 0 si no
 */
int Buscador::revisarEntrada(char entrada []){
	int entradaValida= 0;
	int espacioEncontrado= 0;
	int errorNumeroParams= 0;
	int contadorDigits= 0;

        //Copia como nombre de usuario hasta encontrar un espacio en blanco y luego guarda el numero
        for(int letra= 0; letra < strlen(entrada) && !errorNumeroParams; ++letra){
		//Si el caracter no es un espacio y el espacio no ha sido encontrado
                if(entrada[letra] != ' ' && !espacioEncontrado){
			//Entonces es parte del nombre del usuario
                        usuario[letra]= entrada[letra];
                }
                else if(!espacioEncontrado){
			//Si el caracter es el espacio que no habia sido encontrado
                        espacioEncontrado= 1;
                }
		else {
			if(entrada[letra] != ' '){
				//El caracter le pertenece al numero
                        	numero[contadorDigits]= entrada[letra];
				++contadorDigits;
			}
			else{
				//Hay mas parametros de lo debido
				errorNumeroParams= 1;
			}
                }
        }

        if(espacioEncontrado && !errorNumeroParams){
                //Si el espacio fue encontrado
                //Determinar si ingreso un numero
                int errorNoNumero= 0;

                for(int letra= 0; letra < contadorDigits && !errorNoNumero; ++letra){
                        //Si no es un digito
                        if(!isdigit(numero[letra])){
                                //No se ingreso un numero sino algo mas
                                errorNoNumero= 1;
                        }
                }

		if(!errorNoNumero && !errorNumeroParams){
			//Si no hay errores en la entrada
			entradaValida= 1;

			numAmigos= atoi(numero);
		}
		else{
			cout << mensajeError << endl;
                	cout << endl;
		}
        }
        else{
                cout << endl;
        }

	return entradaValida;
}

/**
 *Metodo para buscar al usuario consultado dentro del documento generado
 */
void Buscador::buscar(){
	//Abre el archivo de relaciones
	ifstream relaciones((char*)"Relaciones.txt");
	
	//Buffer para contener todas las lineas
	char linea[NUM_MAX_CHAR_POR_LINEA];

	//Lee la linea
	relaciones.getline(linea, NUM_MAX_CHAR_POR_LINEA);
	
	//Mientras no se haya acabado el archivo o el usuario haya sido encontrado
	int usuarioEncontrado= 0;
	while(!relaciones.eof() && !usuarioEncontrado){
		//Busca al usuario
		if(buscarUsuario(linea)){
			
			usuarioEncontrado= 1;
			cout << "Usuario encontrado..." << endl;

			//Imprime al usuario
			//Imprime sus n amigos si n es valido
			imprimirResultado(relaciones);
		}
		else{
			//Reinicia el buffer de la linea
			//char linea[NUM_MAX_CHAR_POR_LINEA];
			
			relaciones.getline(linea, NUM_MAX_CHAR_POR_LINEA);
		}
	}
	//Si el usuario no es encontrado
	if(!usuarioEncontrado){
	
		cout << "Usuario no encontrado" << endl;
	}
}

/**
 *Metodo para buscar al usuario consultado en el documento
 *@param linea es un arreglo de chars que contiene una linea de texto del documento de relaciones generado
 *@return encontrado es 1 si el usuario fue encontrado y 0 de otra forma
 */
int Buscador::buscarUsuario(char linea[]){

	int encontrado= 0;
	
	//Buscar la etiqueta nombre
	//Solo la etiqueta Nombre tiene una O en la segunda posicion
	if(linea[1] == 'o'){
	
		//Es una linea de nombre de usuario
		int finDeEtiqueta= 9; //Numero de espacios estandar antes del nombre
		int coinciden= 1;
		//Debe compararse el usuario buscado y el usuario en la linea
		for(int letra= finDeEtiqueta; letra < strlen(linea) && letra - finDeEtiqueta < strlen(usuario) && coinciden; ++letra){
			//Si no coinciden las letras
			if(linea[letra] != usuario[letra - finDeEtiqueta]){

				coinciden= 0;
			}
		}
		//Si todas las letras coinciden
		if(coinciden){
			//Es el usuario correcto
			encontrado= 1;
		}
	}

	return encontrado;
}

/**
 *Metodo para imprimir lo solicitado por el usuario
 *@param relaciones es una referencia a un objeto ifstream del cual se lee
 */
void Buscador::imprimirResultado(ifstream & relaciones){
	//Largo de las etiquetas para no leerlas
	int largoEtiquetaNumAmigos= 18;
	int largoEtiquetaCardinalidad= 14;
	int largoEtiquetaAmigos= 9;

	//Variables para controlar la validez de la solicitud
	int numeroAmigos= 0;
	char amigosNum[NUM_MAX_CHAR_POR_LINEA];

	char linea[NUM_MAX_CHAR_POR_LINEA];

	relaciones.getline(linea, NUM_MAX_CHAR_POR_LINEA);

	for(int etiqueta= 0; etiqueta < NUMERO_ETIQUETAS - 2; ++etiqueta){
		//Si la etiqueta es el numero de amigos
		if(etiqueta == 0){
			//Obtiene el numero de amigos para hacer la comparacion de numeros
			for(int letra= largoEtiquetaNumAmigos; letra < strlen(linea); ++letra){
			
				amigosNum[letra - largoEtiquetaNumAmigos]= linea[letra];
			}

			numeroAmigos= atoi(amigosNum);		
		}
		//Se ignora la cardinalidad
		//Pide la linea nueva
		relaciones.getline(linea, NUM_MAX_CHAR_POR_LINEA);
	}

	if(numAmigos <= numeroAmigos){
		
		cout << "Los " << numAmigos << " mejores amigos de " << usuario << " son: " << endl;;

		int ultimaPosicion= 0;
		int arrobaEncontrado= 0;
		//Imprimir los n amigos separando por arrobas
		for(int amigo= 0; amigo < numAmigos; ++amigo){
			
			arrobaEncontrado= 0;
			//Imprime todas las letras de un amigo
			for(int letra= largoEtiquetaAmigos + ultimaPosicion; !arrobaEncontrado; ++letra){
			
				if(linea[letra] != '@'){
				
					cout << linea[letra];
				}
				else{
					//Se detiene cuando encuentra un arroba
					arrobaEncontrado= 1;
					ultimaPosicion= letra - largoEtiquetaAmigos + 1;
				}
			}
		}

		cout << endl;
	}
	else if(numAmigos <= 0){
	
		//Pide un numero invalido de amigos
		cout << "El numero de amigos debe ser mayor a 0" << endl;
	}
	else{
	
		//Si el numero solicitado de amigos es mayor al que tiene el usuario
		//Se advierte al usuario del programa
		cout << "El usuario " << usuario << " Tiene menos de " << numAmigos << " amigos. Se presentan a continuacion todos los amigos:"<< endl;
		//Imprime todos los amigos. No imprime los arrobas
		for(int letra= largoEtiquetaAmigos; letra < strlen(linea); ++letra){
		
			if(linea[letra] != '@'){
			
				cout << linea[letra];
			}
		}

		cout << endl;
	}
}
