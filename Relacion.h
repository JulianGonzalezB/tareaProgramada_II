#ifndef _RELACION_
#define _RELACION_
#include<string>
using namespace std;

class Relacion{

	private:
		Relacion * siguiente;
		string primerUsuario;
		string segundoUsuario;
		double dice;

	public:
		Relacion(string, string);
		~Relacion();
		void calcularDice();
		double getDice();
		string getNombre(string);
		int interacciones;//Para poder hacerle ++ facilmente
};
#endif
