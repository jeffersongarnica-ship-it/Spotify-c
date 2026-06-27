#ifndef USUARIO_H
#define USUARIO_H

#include"estructuras.h"

void insertarusuario(nodousuario**arbol, char *nombre, char *correo,char *pais,char *nickname,char *contraseña);
nodousuario* buscarusuario(nodousuario *arbol, char *correo);
void mostrarusuarios(nodousuario*arbol);
void eliminarusuario(nodousuario**arbol,char *correo);

nodousuario* ingresar(nodousuario *arbol);

void agregaramigo(nodousuario *usuario, nodousuario *amigo);
void mostraramigos(nodousuario*usuarios);

#endif
