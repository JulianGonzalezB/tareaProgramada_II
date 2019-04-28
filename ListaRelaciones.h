#ifndef _LISTAREL_
#define _LISTAREL_
#include "Relacion.h"
#include<string>
using namespace std;

class ListaRelaciones{

	private:
		Relacion * primera;
		Relacion * ultima;
		void pushBack(Relacion *);
		void comparar(string, string);

	public:
		ListaRelaciones();
		~ListaRelaciones();
		void agregar(string, string);
		Relacion * getRelacion(string, string);//Recibe el nombre de los relacionados y devuelve el  puntero de la relacion si existe
		int relaciones;//Lo pongo publico para no tener que hacer un get
};
#endif
