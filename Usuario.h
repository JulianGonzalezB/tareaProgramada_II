#ifndef _USUARIO_
#define _USUARIO_
#include<string>
#include<iostream>
class Usuario{

	class Interaccion;

	private:
		string nombre;
		Usuario * anterior;
		Usuario * siguiente;
		Interaccion * primera;
		Interaccion * ultima;
		int interacciones;
		calcularDice();//Le dice a cada celda de la lista de interacciones cual es su valor de Dice

		class Interaccion{
			
			public:
				Interaccion(Usuario *);
				~Interaccion();
				Usuario * mencionado;
				Interaccion * anterior;
				Interaccion * siguiente;
				int interacciones;
				double dice;
		}

	public:
		Usuario(string nombre);
		~Usuario();
		agregarInterac(Usuario *);
		ostream & imprimirBFs(ostream &);

};
#endif
