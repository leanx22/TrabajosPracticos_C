#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	//int isEmpty;
}Jugador;

typedef struct{
	int id;
	char descripcion[20];

}eNacionalidades;

typedef struct{
	int id;
	char descripcion[50];

}ePosicion;

Jugador* jug_new();
Jugador* jug_newParametros(int id,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);


#endif // jug_H_INCLUDED
int hardcodearNacionalidades(eNacionalidades lista[],int tam);
int imprimirNacionalidades(eNacionalidades lista[],int tam,int cls);
int imprimirPosiciones(ePosicion listaPos[],int tamPos,int cls);

int obtenerPosicionxID(ePosicion lista[],int tam,int id, char* respuesta);
int obtenerNacionalidad(eNacionalidades listaN[],int tam,int id, char* respuesta);

int editarJugador(Jugador* jugador,ePosicion listaPos[],eNacionalidades listaNacionalidades[],
	int tamPos,int tamNacionalidades);

int listarJugadores(LinkedList* lista,LinkedList* listaSelecciones,int cls);

int listarJugadoresConvocados(LinkedList* lista,LinkedList* listaSelecciones,int cls);

int bajaJugador(LinkedList* lista,int idAeliminar);

Jugador* convocarJugador(LinkedList*listaJugadores);
