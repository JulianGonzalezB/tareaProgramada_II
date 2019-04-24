#ifndef _LISTAUSUARIOS_
#define _LISTAUSUARIOS_
#include "Usuario.h"
class ListaUsuarios{

        private:
                Usuario * primerUsuario;
                Usuario * ultimoUsuario;
                int numeroDeUsuarios;

        public:
                ListaUsuarios();
                ~ListaUsuarios();
                Listausuarios & pushFront(Usuario &);
                ListaUsuarios & pushBack(Usuario &);
                int getNumUsuarios();

};
#endif
