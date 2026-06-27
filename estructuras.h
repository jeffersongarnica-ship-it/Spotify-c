#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct fechas
{
    int dia;
    int mes;
    int anio;
} fechas;

typedef struct cancion{
    char nombre[50];
    char artista[50];
    int duracion;
    int reproducciones;
    char archivo[100];
    struct cancion *sig;
} cancion;

typedef struct disco{
    char nombre[50];
    fechas lanzamiento;
    cancion *canciones;
    struct disco *sig;
} disco;

typedef struct nodoartistas{

    char nombre[50];
    disco*discos;
    struct nodoartistas*izq ,*der;
} nodoartistas;

typedef struct plan{
    fechas inicio;
    fechas fin;
    float valor;
    int activo;

}Plan;

typedef struct Reproduccion {
    cancion *cancion;
    fechas fecha;
    struct Reproduccion *sig;
}Reproduccion;

typedef struct Playlist{
    char nombre[50];
    cancion *canciones;
    struct Playlist *sig;
} Playlist;

typedef struct Anuncio{
    char contenido[200];
    char anunciante[100];
    struct Anuncion *sig;
}Anuncio;

typedef struct nodoamigo{
    struct nodousuario *usuario;
    struct nodoamigo *sig;
}nodoamigo;

typedef struct nodousuario{
    char nombre[100];
    char correo[100];
    char pais[50];
    char nickname[50];
    char contraseña[50];
    int plan;
    Plan premiun;
    Reproduccion *historial;
    Playlist *playlists;
    nodoamigo *amigos;
    struct nodousuario*izq,*der;



}nodousuario;

#endif
