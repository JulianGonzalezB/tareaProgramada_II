#ifndef _LISTATUITS_
#define _LISTATUITS_
#include <string>
#include "Tuit.h"
class ListaTuits{

	private:
		Tuit * primerTuit;
		Tuit * ultimoTuit;
		int numeroDeTuits;
	
	public:
		ListaTuits();
		~ListaTuits();
		ListaTuits & pushFront(Tuit &);
		ListaTuits & pushBack(Tuit &);
		int getNumeroDeTuits();

};
#endif
