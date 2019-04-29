#ifndef RELACION
#define RELACION

class Relacion{
	private:
		char * nombre1;
		char * nombre2;
		double cantidadIteraciones;
		double dice;
		int equals(char*,char*);
	public:
		Relacion(char *, char *);
		~Relacion();
		int yaEsta(char *, char*);
		void operator++();
};
#endif