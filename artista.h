#ifndef ARTISTA_H
#define ARTISTA_H

#include "estructuras.h"

void insertarArtista(nodoartistas **arbol, char *nombre);
nodoartistas* buscarartistas(nodoartistas*arbol,char *nombre);
void mostrarartistas(nodoartistas*arbol);
void eliminarArtista(nodoartistas **arbol, char *nombre);


void agregardisco(nodoartistas*artistas, char *nombre, fechas fecha); 
void mostrardiscos(nodoartistas*artistas);
void eliminardiscos(nodoartistas*artistas,char *nombre);

void agregarcanciones(disco*disco, char *nombre, char *artista, int duracion,char *archivo);
void mostrarcanciones(disco*disco);
void eliminarCancion(disco *disco, char *nombre);


#endif