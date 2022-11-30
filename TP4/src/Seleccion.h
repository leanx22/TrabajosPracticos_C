#include "LinkedList.h"
#include "Jugador.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	//int isEmpty;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete();

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);
//int selec_getIsEmpty(Seleccion* this,int* isEmpty);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

/// @brief Funcion encargada de listar las selecciones en formato tabla.
///
/// @param this lista de selecciones
/// @param cls (1)si se desea limpiar la pantalla.
/// @return retorna 0 si OK O -1 en caso de error.
int listarSelecciones(LinkedList* this,int cls);

/// @brief Funcion para obtener la "descripcion" (en realidad, el campo pais) de una seleccion
/// por medio de su ID.
///
/// @param this lista de selecciones.
/// @param idBusqueda ID de la cual se desea saber la seleccion.
/// @param respuesta variable donde se guarda la descripcion.
/// @return retorno 0 si OK o -1 en caso de error.
int obtenerSeleccionxID(LinkedList* this,int idBusqueda,char* respuesta);

/// @brief Funcion encargada de convocar jugadores a selecciones.
///
/// @param listaSeleccion
/// @param jugador puntero a Jugador que se desea convocar.
/// @return retorna 0 si se convoca OK o -1 si hay error.
int convocarJugadorAseleccion(LinkedList* listaSeleccion,Jugador* jugador);

/// @brief Funcion utilizada para obtener el idice de una seleccion por medio de su ID.
///
/// @param listaSeleccion
/// @param id ID de la seleccion la cual se desea saber el indice.
/// @return retorna el indice de la seleccion o -1 en caso de que no exista.
int obtenerIndiceSeleccion(LinkedList* listaSeleccion,int id);

/// @brief todo
///
/// @param listaSeleccion
/// @param jugador
/// @return
int sumarJugadorAseleccion(LinkedList* listaSeleccion,Jugador* jugador);

/// @brief Funcion criterio de ordenamiento para usarse con ll_sort();
///
/// @param this
/// @param this2
/// @return
int selec_ordenarPorConfederacion(void* this,void* this2);

#endif // selec_H_INCLUDED
