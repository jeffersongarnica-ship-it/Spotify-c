#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"estructuras.h"
#include"artista.h"


nodoartistas* insertarartista(nodoartistas*raiz, char nombre[]){
    if(raiz==NULL){
        nodoartistas*nuevo=(nodoartistas*)malloc(sizeof(nodoartistas));
        strcpy(nuevo->nombre, nombre);
        nuevo->discos = NULL;
        nuevo->izq=NULL;
        nuevo->der=NULL;
        return nuevo;
    }
    //vamos a poner en orden ABB




}
