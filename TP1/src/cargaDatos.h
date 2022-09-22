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

/// @brief Funcion encargada de comenzar con la carga de Jugadores y controlar la cantidad de los mismos.
///
/// @param cArqueros Puntero a variable contador.
/// @param cDefensores Puntero a variable contador.
/// @param cMedioc Puntero a variable contador.
/// @param cDelanteros Puntero a variable contador.
/// @param AFC Puntero al contador de dicha confederacion.
/// @param CAF Puntero al contador de dicha confederacion.
/// @param CONCACAF Puntero al contador de dicha confederacion.
/// @param CONMEBOL Puntero al contador de dicha confederacion.
/// @param UEFA Puntero al contador de dicha confederacion.
/// @param OFC Puntero al contador de dicha confederacion.
/// @param camisetas Array de camisetas del equipo.
/// @param tam tamanio del equipo y por ende cantidad de camisetas.
/// @return retorna 0 si el jugador se agrego de manera correcta o -1 en caso de error o NULL
int cargaJugadores(int* cArqueros,int* cDefensores,int* cMedioc,int* cDelanteros,
int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int camisetas[],int tam);

/// @brief Funcion que pide y valida los datos de los jugadores.
///
/// @param confederacion Puntero a Variable donde se guardara la confederacion del jugador.
/// @param camisetas Array del numero de camisetas del equipo.
/// @param tam tamanio de array camisetas y equipo.
/// @return retorno 0 si los datos se validaron correctamente o -1 en caso de error.
int datosJugador(int* confederacion,int camisetas[],int tam);

/// @brief Esta funcion es la encargada de sumar +1 a la confederacion seleccionada a la hora de la carga.
///
/// @param AFC	Punteros a contadores de las confederaciones.
/// @param CAF
/// @param CONCACAF
/// @param CONMEBOL
/// @param UEFA
/// @param OFC
/// @param confederacion Opcion de la confederacion a la que se desea aumentar su contador.
/// @return	0 ok -1 en caso de error.
int sumarConfederacion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int confederacion);

/// @brief Funcion encargada de inicializar el array de camisetas en -1;
///
/// @param camisetas array de camisetas a inicializar.
/// @param tam tamanio del equipo y por ende, la cantidad de camisetas.
/// @return retorna 0 si salio OK o -1 en caso de null o tamanio nulo.
int inicializarCamisetas(int camisetas[],int tam);

/// @brief Esta funcion se encarga de buscar y COMPROBAR LA EXISTENCIA de una camiseta en el array.
///
/// @param camisetas Array de camisetas
/// @param tam tamanio del array
/// @param busqueda numero de camiseta que se desea averiguar.
/// @return la funcion retornara 0 si la camiseta existe o (-1 si no existe o ocurre un error).
int comprobarCamiseta(int camisetas[],int tam, int busqueda);

/// @brief Esta funcion es la encargada de colocar la camiseta en un lugar libre del array.
///
/// @param camisetas array de camisetas
/// @param tam tamanio del equipo y array de camisetas
/// @param agregar numero de camiseta a agregar
/// @return retorna 0 si se agrego correctamente, -1 en caso de que todos los lugares esten ocupados o punteros en NULL
int cargarCamiseta(int camisetas[],int tam,int agregar);
