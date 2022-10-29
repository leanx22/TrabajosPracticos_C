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

/// @brief
///
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @param totalsalario
/// @param altas
/// @return
int informes(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe,float totalsalario,int altas);

/// @brief
///
/// @param listaJugadores
/// @param tamJugadores
/// @param totalSalarios
/// @param totalJugadores
/// @return
int infoSalarios(eJugador listaJugadores[],int tamJugadores,float totalSalarios,int totalJugadores);

/// @brief
///
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @return
int ordenarxConfederacionYnombre(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe);

/// @brief
///
/// @param listaJugadores
/// @param listaConfe
/// @param tamJugadores
/// @param tamConfe
/// @param cls
/// @return
int listarConfederacionYjugadores(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe,int cls);




