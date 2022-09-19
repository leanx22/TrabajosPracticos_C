/*
 * cargaDatos.h
 *
 *  Created on: 12 sep. 2022
 *      Author: Leandro
 */

#ifndef CARGADATOS_H_
#define CARGADATOS_H_
#endif /* CARGADATOS_H_ */

/// @brief Funcion de carga de datos para los costos de mantenimiento. Imprime el submenu, pide los datos
/// y actualiza al momento los precios.
///
/// @param hospedaje Puntero a la variable donde se guarda el costo de hospedaje.
/// @param comida Puntero a la variable donde se guarda el costo de comida.
/// @param transporte Puntero a la variable donde se guarda el costo de transporte.
/// @return La funcion retorna 0(si to.do OK) o -1(si alguno de los punteros es NULL).
int costosMantenimiento(float* hospedaje,float* comida,float* transporte);

/// @brief Funcion que imprime el submenu para la carga de jugadores e informa la cantidad de los mismos.
/// tambien controla los contadores de las confederaciones.
///
/// @param cArqueros Puntero a la variable contador de arqueros.
/// @param cDefensores Puntero a la variable contador de defensores.
/// @param cMedioc Puntero a la variable contador de mediocampistas.
/// @param cDelanteros Puntero a la variable contador de delanteros.
/// @param AFC Puntero a la variable contador de jugadores de la confederacion.
/// @param CAF IDEM
/// @param CONCACAF IDEM
/// @param CONMEBOL IDEM
/// @param UEFA IDEM
/// @param OFC IDEM
/// @return retorno -1 si error o null o (0) si OK.
int cargaJugadores(int* cArqueros,int* cDefensores,int* cMedioc,int* cDelanteros,
int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int camisetas[]);

/// @brief Esta funcion pide los datos de los jugadores.
///
/// @param camisetas puntero donde se guardara la camiseta ingresada.
/// @param confederacion puntero a variable donde se guardara la ultima confederacion ingresada.
/// @return 0 ok -1 en caso de error.
int datosJugador(int* camisetas, int* confederacion);

/// @brief Esta funcion es la encargada de sumar +1 a la confederacion seleccionada a la hora de la carga.
///
/// @param AFC	Punteros a contadores de las confederaciones.
/// @param CAF
/// @param CONCACAF
/// @param CONMEBOL
/// @param UEFA
/// @param OFC
/// @param confederacion
/// @return	0 ok -1 en caso de error.
int sumarConfederacion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int confederacion);
