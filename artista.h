#ifndef ARTISTA_H
#define ARTISTA_H

#include "estructuras.h"

nodoartistas* insertarartista(nodoartistas*raiz, char nombre[]);

nodoartistas* buscarartistas(nodoartistas*raiz,char nombre[]);

void mostrarartistas(nodoartistas*raiz);

nodoartistas *eliminarartistas(nodoartistas*raiz, char nombre[]);

void agregardisco(nodoartistas*artistas, char *nombre, fechas fecha); 
void mostrardiscos(nodoartistas*artistas);

void agregarcanciones(disco*disco, char *nombre, char *artista, int duracion,char *archivo);
void mostrarcanciones(disco*disco);



#endif