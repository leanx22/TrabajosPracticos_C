/*
 * arrayJugadores.h
 *
 *  Created on: 18 oct. 2022
 *      Author: leandro
 */
#include "confederaciones.h"
#ifndef ARRAYJUGADORES_H_
#define ARRAYJUGADORES_H_

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numCamiseta;
	int idConfederacion;
	float salario;
	short anioContrato;
	short isEmpty;

}eJugador;

#endif /* ARRAYJUGADORES_H_ */

/// @brief Funcion encargada de inicializar el array de jugadores con su valor isEmpty en 1.
///
/// @param lista Array de Jugadores.
/// @param tam Tamanio del Array.
/// @return Retorna 0 si tod OK o -1 en caso de error por puntero NULL o tam 0.
int inicializarArray(eJugador listaJugadores[], int tam);

int hardcodear(eJugador listaJugadores[],int indice,int*id,char*nombre,
char*posi,short camiseta,int idConfe, float salario, short aniosContrato,int*altas,float*salarios);

/// @brief Funcion que busca un indice libre en el array.
///
/// @param listaJugadores Array de Jugadores.
/// @param tam Tamanio del array de jugadores.
/// @return La funcion retorna el indice libre encontrado, en caso de error o no encontrar un
/// espacio disponible retornara -1.
int buscarLibre(eJugador listaJugadores[], int tam);

/// @brief Funcion encargada de la carga y validacion de los datos del nuevo jugador.
///
/// @param listaJugadores Array de jugadores.
/// @param listaConfe Array de confederaciones.
/// @param tam tamanio del array de jugadores.
/// @param tamConf tamanio del array de confederaciones.
/// @param ids Puntero a variable que controla los ID.
/// @param altas puntero a contador de altas.
/// @param aSueldos puntero a variable acumuladora de sueldos. (para saber el total de todos los sueldos)
/// @return Retorna 0 si el jugador se agrego de manera correcta, -1 en caso de error en
/// las validaciones o NULL en punteros.
int cargaJugador(eJugador listaJugadores[],eConfederacion listaConfe[],int tam,int tamConf,int*ids,int*altas,float* aSueldos);

/// @brief Esta funcion se usa para guardar la posicion del jugador que ingreso el usuario.
///
/// @param respuesta Variable donde se guardara la descripcion de la posicion.
/// @param id ID de la posicion de la cual quiero obtener la descripcion.
/// @return Retorna 0 si salio OK o -1 en caso de error con puntero NULL o id invalida.
int obtenerPosicion(char*respuesta, int id);

/// @brief Funcion encargada de listar a todos los jugadores en formato de tabla.
///
/// @param listaJugadores Array de jugadores.
/// @param listaConfederacion Array de confederaciones.
/// @param tamJugadores Tamanio del array.
/// @param tamConfe Tamanio del array.
/// @param cls Se le pasa 1 si el usuario quiere limpiar la pantalla, caso contrario se le debe pasar 0.
/// @return Retorna 0 si OK o -1 en caso de error.
int listarJugadores(eJugador listaJugadores[],eConfederacion listaConfederacion[], int tamJugadores, int tamConfe,int cls);

/// @brief Esta funcion realiza un ordenamiento de la lista de jugadores por medio de sus ID.
///
/// @param listaJugadores Array de jugadores.
/// @param tamJugadores tamanio del array.
/// @return retorna 0 si OK o -1 en caso de error con punteros o tamanio incorrecto.
int ordenarxID(eJugador listaJugadores[],int tamJugadores);

/// @brief Funcion para obtener el indice en el que esta el ID
///
/// @param listaJugadores
/// @param tamJugadores
/// @param idBusqueda id que se quiere buscar en el array.
/// @return Retorna el indice donde se encuentra el ID deseado, -1 en caso de error o no existencia.
int obtenerIndicexID(eJugador listaJugadores[], int tamJugadores,int idBusqueda);

/// @brief Funcion encargada de la baja logica de jugadores.
///
/// @param listaJugadores
/// @param tamJugadores
/// @param altas puntero a variable contador de altas.
/// @param salarios puntero a variable contador del total de salarios
/// @return retorna 0 si OK O -1 Si hay error.
int bajaJugador(eJugador listaJugadores[],int tamJugadores,int*altas,float*salarios);

/// @brief Funcion encargada de la edicion de los jugadores.
///
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @return retorna 0 si OK o -1 si hay error.
int editarJugador(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe);




