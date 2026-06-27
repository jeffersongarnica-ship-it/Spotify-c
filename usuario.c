#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"usuario.h"

void insertarusuario(nodousuario**arbol, char *nombre, char *correo,char *pais,char *nickname,char *contraseña){

    if(!(*arbol)){
            nodousuario*nuevo= malloc(sizeof(nodousuario));
            strcpy(nuevo->nombre,nombre);
            strcpy(nuevo->correo, correo);
            strcpy(nuevo->pais,pais);
            strcpy(nuevo->nickname, nickname);
            strcpy(nuevo->contraseña,contraseña);
            nuevo->plan=0;
            nuevo->historial=NULL;
            nuevo->amigos=NULL;
            nuevo->playlists=NULL;
            nuevo->izq= NULL;
            nuevo->der=NULL;
            *arbol=nuevo;
            return;
            
    }
//orden por correo
    int comp = strcmp(correo,(*arbol)->correo);

    if(comp<0){
         insertarusuario(&(*arbol)->izq,nombre,correo,pais,nickname,contraseña);
    }else if(comp>0){
         insertarusuario(&(*arbol)->der,nombre,correo,pais,nickname,contraseña);
    }else{
        printf("El correo ya esta registrado\n");

    }
}

nodousuario* buscarusuario(nodousuario *arbol, char *correo){

    if(arbol==NULL){
        return NULL;
    }

    int comp=strcmp(correo,arbol->correo );

    if(comp==0){
        return arbol;
    }else if(comp<0){
        return buscarusuario(arbol->izq,correo);
    }else{

        return buscarusuario(arbol->der, correo);
    }

}

void mostrarusuarios(nodousuario*arbol){

    if(arbol==NULL){
        printf("No existen datos guardados\n");
        return;
    }

    mostrarusuarios(arbol->izq);
    printf("- %s | %s | %s| %s\n", arbol->correo, arbol->nombre,arbol->nickname,arbol->plan == 0 ? "Free" : "Premium");

    mostrarusuarios(arbol->der);
}

//utilizamos el correo por mas facilidad
nodousuario* ingresar(nodousuario *arbol){
    char correo[100],contraseña[50];
    int intentos=0;

    while(intentos<3){
        printf("Correo: ");
        scanf("%s", correo);
        printf("Contrasena: ");
        scanf("%s", contraseña);
        nodousuario* verificar = buscarusuario(arbol,correo);
        if(verificar!=NULL && strcmp(verificar->contraseña,contraseña)==0){
            printf("Bienvenido %s \n",verificar->nombre);
            return verificar;
        }
        intentos++;
        printf("Datos incorrectos. Intentos restantes: %d\n", 3 - intentos);

    }
    printf("Demasiados intentos fallidos\n");
    return NULL;

}

void agregaramigo(nodousuario *usuario, nodousuario *amigo){
    
    nodoamigo*actual = usuario->amigos;
    while(actual != NULL){
        if(actual->usuario == amigo){
            printf("Ya son amigos\n");
            return;
        }
        actual=actual->sig;

    }

    nodoamigo*nuevo = malloc(sizeof(nodoamigo));
    nuevo->usuario=amigo;
    nuevo->sig= usuario->amigos;
    usuario->amigos= nuevo;
    printf("amigo agregado\n");

}
void mostraramigos(nodousuario*usuarios){
    nodoamigo*actual = usuarios->amigos;
    if(actual==NULL){
        printf("No tienes amigos agregados\n");
        return;

    }

    printf("\n-----LISTA DE AMIGOS--------\n");
    while(actual!=NULL){
        printf("- %s (%s)\n",actual->usuario->nombre,actual->usuario->correo);
        actual= actual->sig;
    }
    
}