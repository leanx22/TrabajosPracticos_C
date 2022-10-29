/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: leandro
 */

#include "confederaciones.h"
#include "arrayJugadores.h"
#ifndef INFORMES_H_
#define INFORMES_H_
#endif /* INFORMES_H_ */

/// @brief Funcion que es encargada del submenu de informes.
///
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @param totalsalario Valor de los salarios totales.
/// @param altas Valor de todas las altas realizadas.
/// @return retorna 0 si ok -1 si hay error.
int informes(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe,float totalsalario,int altas);

/// @brief Funcion que informa el total y promedio de todos los jugadores, junto con cuantos sobrepasan el promedio.
///
/// @param listaJugadores
/// @param tamJugadores
/// @param totalSalarios Suma total de los salarios.
/// @param totalJugadores Total de jugadores dados de alta.
/// @return retorna 0 si OK -1 si error
int infoSalarios(eJugador listaJugadores[],int tamJugadores,float totalSalarios,int totalJugadores);

/// @brief Funcion que ordena a los jugadores alfabeticamente por nombre de confederacion
/// y en caso de igualdad por sus nombres.
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @return retorna 0 si OK -1 si error
int ordenarxConfederacionYnombre(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe);

/// @brief Funcion que lista a los jugadores de cada confederacion por separado.
///
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @param cls Se le pasa 1 si se quiere limpiar la pantalla o 0 en caso contrario.
/// @return retorna 0si ok o -1 en caso de error
int listarConfederacionYjugadores(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe,int cls);

/// @brief Funcion que informa el nombre de la confederacion con mas cantidad de anios de contrato.
///
/// @param listaJugadores
/// @param tamJugadores
/// @return retorna 0 si oK o -1 en caso de error.
int confederacionConMasContratos(eJugador listaJugadores[],int tamJugadores);

