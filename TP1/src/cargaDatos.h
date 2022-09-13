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

/// @brief Funcion que imprime el submenu para la carga de jugadores e informa la cantidad de los mismos. Es la encargada
/// de realizar las altas de jugadores nuevos.
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

/// @brief esta funcion es llamada dentro de cargaJugadores para pedir la confederacion a la que pertenece el jugador
/// una vez validado aumenta el contador de dicha confederacion en +1.
///
/// @param AFC puntero a variable contador.
/// @param CAF IDEM
/// @param CONCACAF IDEM
/// @param CONMEBOL IDEM
/// @param UEFA IDEM
/// @param OFC IDEM
/// @return retorna -1 en caso de error (null, muchos reintentos,etc) o (0) si to.do OK.
int cargaConfederacion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC);



