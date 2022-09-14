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
int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC);

/// @brief Esta funcion suma +1 al contador de la confederacion correspodiente. /es utilizada dentro de datos jugador.
///
/// @param opcion Se le pasa por este parametro la confederacion a la cual se le quiere sumar +1.
/// @param AFC puntero a la variable contador de dicha confederacion.
/// @param CAF IDEM
/// @param CONCACAF IDEM
/// @param CONMEBOL IDEM
/// @param UEFA IDEM
/// @param OFC IDEM
/// @return retorna 0 si OK o -1 en caso de algun NULL.
int sumaConfederacion(int opcion, int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC);

/// @brief Esta funcion pide los del jugador al usuario para realizar un alta.
///
/// @param AFC puntero a contador
/// @param CAF puntero a contador
/// @param CONCACAF puntero a contador
/// @param CONMEBOL puntero a contador
/// @param UEFA puntero a contador
/// @param OFC puntero a contador
/// @return 0 si toda la entrada de datos OK, -1 si null o algun error.
int datosJugador(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC);
