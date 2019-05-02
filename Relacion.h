#ifndef RELACION
#define RELACION

/**
 * Esta es la clase que se encarga de guardar una relación de los tuits.
 * @author (Julián, Javier Carmona)
 * @version (01/05/2019)
 */
class Relacion{
	private:
		char * nombre1;
		char * nombre2;
		double cantidadIteraciones;
		/**
		 * Función: Se utiliza para ver si dos vectores de caracteres son iguales.
		 * @param nombreA Es un puntero a un vector de caracteres, guarda uno de los nombres para comparar, y se utiliza para eso,
		 * para compararlo con nombreB y ver si son iguales.
		 * @param nombreB Es un puntero a un vector de caracteres, guarda uno de los nombres para comparar, y se utiliza para eso,
		 * para compararlo con nombreA y ver si son iguales.
		 * @return iguales Es de tipo int, devuelve un 1 si los char[] son iguales y un 0 si no, y se utiliza para saber si la relación 
		 * que se va a agrega ya está, y si no sumarle 1 al número de iteraciones de esa relación.
		 */
		int equals(char*,char*);
	public:
		Relacion(char *, char *);
		~Relacion();
		/**
		 * Función: Se utiliza para ver si la relación que se va a agregar ya existe, y sumarle 1 al número de iteraciones de esa relación.
		 * @param nombre1Param Es un puntero a un vector de caracteres, guarda uno de los nombres que se va a guardar en la relación, y se utiliza para eso,
		 * para compararlo con los nombres de la relación en revisión y ver si son iguales.
		 * @param nombre2Param Es un puntero a un vector de caracteres, guarda uno de los nombres que se va a guardar en la relación, y se utiliza para eso,
		 * para compararlo con los nombres de la relación en revisión y ver si son iguales.
		 * @return devuelve un 1 si los nombres están en la relación en revisión y un 0 si no, y se utiliza para saber si la relación 
		 * que se va a agrega ya está, y si no sumarle 1 al número de iteraciones de esa relación.
		 */
		int yaEsta(char *, char*);
		/**
		 * Función: aumenta el número de veces en que la relación aparece en los tuits.
		 */
		void aumentarNumeroIteraciones();
		/**
		 * Función: Revisa que un solo nombre recibido este en la relación.
		 * @param nombreParam Es un puntero a un vector de char, guarda el nombre del que se va a revisar si está en la relación, y 
		 * se utiliza para eso, para revisar si el usuario se encuentra en esa relación.
		 * @return devuelve un 1 si el nombre está en la relación en revisión y un 0 si no, y se utiliza para 
		 * poder agregar el amigo del usuario de esa relación y su dice.
		 */
		int esta(char *);
		double getCantidadIteraciones();
		char * getNombreAmigo(char *);
};
#endif