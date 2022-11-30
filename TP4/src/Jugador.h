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

/// @brief Funcion que lista las nacionalidades disponibles en formato lista.
///
/// @param lista lista de nacionalidades.
/// @param tam cantidad de nacionalidades.
/// @param cls (1)si se desea limpiar la pantalla.
/// @return retorna 0 si OK o -1 si hay error.
int imprimirNacionalidades(eNacionalidades lista[],int tam,int cls);

/// @brief Funcion que imprime las posiciones disponibles.
///
/// @param listaPos array de posiciones.
/// @param tamPos cantidad de posiciones.
/// @param cls (1)si se desea limpiar la pantalla.
/// @return retorna 0 si OK o -1 si hay error.
int imprimirPosiciones(ePosicion listaPos[],int tamPos,int cls);

/// @brief Funcion utilizada para obtener la descripcion de una posicion por medio de su ID (utilizada para altas)
///
/// @param lista array de posiciones.
/// @param tam tamanio del array de posiciones.
/// @param id ID de la posicion la cual se desea saber la descripcion.
/// @param respuesta variable donde se guarda la descripcion encontrada.
/// @return 0 si OK o -1 en caso de error(o no encontrar el ID).
int obtenerPosicionxID(ePosicion lista[],int tam,int id, char* respuesta);

/// @brief Funcion utilizada para obtener la descripcion de una nacionalidad por medio de su ID (utilizada para altas)
///
/// @param listaN array de nacionalidades.
/// @param tam tamanio del array de nacionalidades.
/// @param id ID de la nacionalid la cual se desea saber la descripcion.
/// @param respuesta variable donde se guarda la descripcion encontrada.
/// @return 0 si OK o -1 en caso de error(o no encontrar el ID).
int obtenerNacionalidad(eNacionalidades listaN[],int tam,int id, char* respuesta);

/// @brief Funcion encargada de preguntar que se quiere editar y realizar  la edicion de los datos
/// de un jugador.
///
/// @param jugador puntero al jugador que se desea editar.
/// @param listaPos lista de posiciones.
/// @param listaNacionalidades lista de nacionalidades.
/// @param tamPos tamanio de array posiciones.
/// @param tamNacionalidades tamanio de array nacionalidades.
/// @return retorna 0 si OK o -1 en caso de error.
int editarJugador(Jugador* jugador,ePosicion listaPos[],eNacionalidades listaNacionalidades[],
	int tamPos,int tamNacionalidades);

/// @brief Funcion encargada de listar a los jugadores cargados.
///
/// @param lista
/// @param listaSelecciones
/// @param cls (1)si se desea limpiar la pantalla.
/// @return retorna 0 si OK o -1 en caso de error.
int listarJugadores(LinkedList* lista,LinkedList* listaSelecciones,int cls);

/// @brief Funcion encargada de listar solo a los jugadores que pertenezcan a una seleccion.
///
/// @param lista
/// @param listaSelecciones
/// @param cls (1)si se desea limpiar pantalla
/// @return retorna 0 si OK o -1 en caso de error.
int listarJugadoresConvocados(LinkedList* lista,LinkedList* listaSelecciones,int cls);

/// @brief Funcion que da de baja a un jugador, decrementando tambien los convocados a su seleccion (si
/// pertenece a una)
///
/// @param lista
/// @param idAeliminar ID del jugador que se desea eliminar.
/// @param listaSeleccion
/// @return retorna 0 si se elimino al jugador OK o -1 en caso de error.
int bajaJugador(LinkedList* lista, int idAeliminar,LinkedList* listaSeleccion);

/// @brief Esta funcion pide y verifica si un jugador ya esta convocado en otra seleccion.
///
/// @param listaJugadores
/// @return retorna un puntero a jugador si este no esta convocado a ninguna seleccion, caso contrario retorna NULL.
Jugador* convocarJugador(LinkedList*listaJugadores);

/// @brief Esta funcion cancela la convocatoria de un jugador a la seleccion y decrementa los convocados
/// de dicha seleccion.
///
/// @param listaJugadores
/// @param listaSeleccion
/// @return retorna 0 si OK o -1 en caso de error.
int quitarJugadorDeSeleccion(LinkedList*listaJugadores,LinkedList* listaSeleccion);

/// @brief Funcion utilizada para obtener el indice de un jugador por medio de su ID.
///
/// @param listaJugadores
/// @param id ID de la cual se desea saber en que indice se encuentra.
/// @return Retorna el indice encontrado o -1 en caso de inexistencia.
int obtenerIndiceJugador(LinkedList* listaJugadores,int id);


int mapear();

//FUNCIONES PARAMETRO PARA LL_SORT()
int jug_ordenarPorNacionalidad(void* this, void* this2);
int jug_ordenarPorNombre(void* this, void* this2);
int jug_ordenarPorEdad(void* this, void* this2);

