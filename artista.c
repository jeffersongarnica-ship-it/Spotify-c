#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include"artista.h"


void insertarArtista(nodoartistas **arbol, char *nombre){
    if(*arbol==NULL){
        nodoartistas*nuevo=malloc(sizeof(nodoartistas));
        strcpy(nuevo->nombre, nombre);
        nuevo->discos = NULL;
        nuevo->izq=NULL;
        nuevo->der=NULL;
        *arbol=nuevo;
        return;
    }
    //vamos a poner en orden ABB
    int busco=strcmp(nombre, (*arbol)->nombre);
    if(busco<0){
        insertarArtista(&(*arbol)->izq, nombre);
    }else if(busco>0){
        insertarArtista(&(*arbol)->der, nombre);
    }else{
        printf("El artista ya existe\n");
    }

}

nodoartistas* buscarartistas(nodoartistas*arbol,char *nombre){
    if(arbol==NULL){
        return NULL;
    }
    double busco = strcmp(nombre, arbol->nombre);
    if(busco==0){
        return arbol;
    }else if(busco<0){
        return buscarartistas(arbol->izq, nombre);
        
    }else{
        return buscarartistas(arbol->der, nombre);
    }

}

void mostrarartistas(nodoartistas*arbol){
    if(arbol==NULL){
        return;
    }
    mostrarartistas(arbol->izq);
    printf("Artista: %s\n", arbol->nombre);
    mostrarartistas(arbol->der);
}

nodoartistas*miniarbol(nodoartistas*arbol){
    while(arbol->izq != NULL){
        arbol = arbol->izq;
    }
    return arbol;
}

void eliminarArtista(nodoartistas **arbol, char *nombre){
    if(*arbol==NULL){
        printf("Artista no encontrado\n");
        return;
    }
    int comp=strcmp(nombre,(*arbol)->nombre);
    if(comp<0){
        eliminarArtista(&(*arbol)->izq,nombre);
    }else if(comp>0){
        eliminarArtista(&(*arbol)->der,nombre);
    }else{
        //caso 1
        if((*arbol)->izq == NULL && (*arbol)->der==NULL){
            free(*arbol);
            *arbol=NULL;
            //caso 2, solo tiene un hijo
        }else if((*arbol)->der==NULL){
            nodoartistas *actual = *arbol;
            *arbol =(*arbol)->izq;
            free(actual);

        }else if((*arbol)->izq == NULL){
            nodoartistas *actual =*arbol;
            *arbol =(*arbol)->der;
            free(actual);
        //caso 3 tiene 2 hijos
        }else{
            nodoartistas *sucesor =miniarbol((*arbol)->der);//busco por
            strcpy((*arbol)->nombre, sucesor->nombre);

            eliminarArtista(&(*arbol)->der,sucesor->nombre);
        }
    
    }
}

void agragardisco(nodoartistas*artistas,char* nombre,fechas fecha){
    disco* nuevo=malloc(sizeof(disco));
    strcpy(nuevo->nombre, nombre);
    nuevo->lanzamiento=fecha;
    nuevo->canciones=NULL;
    nuevo->sig=NULL;
    if(artistas->discos==NULL){
        artistas->discos= nuevo;
    }else{

        disco*actual=artistas->discos;
        while(actual->sig !=NULL){
            actual= actual->sig;
        }
        actual->sig= nuevo;
    }
 }
 void mostrardiscos(nodoartistas*artistas){
     
    disco*actual=artistas->discos;
    if(actual==NULL){
        printf("No hay discos para este artista\n");
        return;
    }
    while(actual!=NULL){
        printf("Disco: %s\n", actual->nombre);
        printf("Fecha de lanzamiento: %d/%d/%d\n",actual->lanzamiento.dia, actual->lanzamiento.mes, actual->lanzamiento.anio);
        actual=actual->sig;

    }
}
void eliminardiscos(nodoartistas*artistas,char *nombre){

    if(artistas->discos==NULL ){
        printf("El artista no tiene discos\n");
        return;
    }
    disco*actual= artistas->discos;
    disco*anterior = NULL;

    while(actual != NULL){
        if(strcmp(actual->nombre, nombre) == 0){
            if(anterior == NULL)
            artistas->discos = actual->sig;
             else
                 anterior->sig = actual->sig;

            cancion *c = actual->canciones;
            while(c != NULL){
                cancion *ayuda = c;
                c = c->sig;
                free(ayuda);
            }
            free(actual);
             printf("Disco eliminado\n");
            return;
        }
         anterior = actual;      // ← estos dos van adentro del while
         actual = actual->sig;   // ← pero afuera del if
    }
    printf("Disco no encontrado\n");
}

void agregarcanciones(disco*disco, char *nombre, char *artista, int duracion, char *archivo){

    cancion* nuevo=malloc(sizeof(cancion));
    strcpy(nuevo->nombre,nombre);
    strcpy(nuevo->artista, artista);
    nuevo->duracion=duracion;
    strcpy(nuevo->archivo, archivo);
    nuevo->sig=NULL;


    if(disco->canciones==NULL){
        disco->canciones=nuevo;
    }else{
        cancion*actual=disco->canciones;
        while(actual->sig !=NULL){
            actual=actual->sig;
        }
        actual->sig=nuevo;
    }
}

void mostrarcanciones(disco*disco){

    cancion*actual =disco->canciones;
    if(actual==NULL){
        printf("No tiene canciones.\n");
        return;
    }

    while(actual!= NULL){
        printf("   * %s - %s (%d seg)\n",actual->nombre,actual->artista,actual->duracion);
        actual= actual->sig;
    }
}
void eliminarCancion(disco *disco, char *nombre){
     
    if(disco->canciones == NULL){
        printf("El dsico no tiene canciones\n");
    }
    cancion *actual =disco->canciones;
    cancion *anterior =NULL;

    while(actual !=NULL){
        if(strcmp(actual->nombre , nombre)==0){

            if(anterior==NULL){
                disco->canciones = actual->sig;
            }else{
                anterior->sig = actual->sig;
            }
            free(actual);
            printf("cancion eliminadas\n");
            return;

        }
        anterior = actual;
        actual = actual->sig;
    }
    printf("cancion no encontrada\n");

}
