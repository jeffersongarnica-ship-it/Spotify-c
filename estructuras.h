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
} Cancion;

typedef struct disco{
    char nombre[50];
    fechas lanzamiento;
    Cancion *canciones;
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
    Cancion *cancion;
    fechas fecha;
    struct Reproduccion *sig;
}Reproduccion;

typedef struct Playlist{
    char nombre[50];
    Cancion *canciones;
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
}Nodoamigo;

typedef struct nodousuario{
    char nombre[100];
    char correo[100];
    char pais[50];
    char nickname[50];
    char contrasena[50];
    int plan;
    Plan premiun;
    Reproduccion *historial;
    Playlist *playlists;
    Nodoamigo *amigos;
    struct nodousuario*sig,*der;



}nodousuario;

#endif
