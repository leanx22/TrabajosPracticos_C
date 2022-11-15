/*
 * confederaciones.h
 *
 *  Created on: 18 oct. 2022
 *      Author: leandro
 */
#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int idConfe;
	char nombre[50];
	char region[50];
	int anioCreacion;

	int isEmpty;
}eConfederacion;

#endif /* CONFEDERACIONES_H_ */

/// @brief Funcion que imprime las confederaciones y sus datos en formato tabla.
///
/// @param lista lista de confederaciones.
/// @param tam tamanio del array.
/// @param limpiar ese le pasa 1 en caso de querer hjacer cls o 0 sino
/// @return retorna 0 si tod OK o -1 en caso de error
int imprimirConfederaciones(eConfederacion lista[], int tam, int limpiar);

/// @brief Funcion que obtiene la descripcion de la confederacion mediante su id
///
/// @param listaConfederaciones
/// @param tamConfe
/// @param id ID de la confederacion la cual se quiere saber el nombre
/// @param respuesta variable donde se guardara la respuesta
/// @return retorna 0 si tod OK o -1 si hay error o el ID no existe
int obtenerConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int id,char*respuesta);

//>>ABM DE CONFEDERACIONES<<
/// @brief Funcion encargada de inicializar el campo isEmpty en el array en 1.
///
/// @param listaConfederaciones Array de confederaciones.
/// @param tamConfe Tamanio del array
/// @return retorna -1 si hay error o 0 si OK.
int inicializarConfederaciones(eConfederacion listaConfederaciones[],int tamConfe);

/// @brief Funcion que busca un lugar(indice) libre en el array de confederaciones.
///
/// @param listaConfederaciones array de confederaciones.
/// @param tamConfe tamanio del array de confederaciones.
/// @param indiceLibre puntero a variable donde se guardara el indice libre encontrado, cabe aclarar que
/// se le pasara como valor -1 en caso de NO encontrar espacio libre!
/// @return retorna 0 si OK o -1 en caso de error.
int buscarConfederacionLibre(eConfederacion listaConfederaciones[],int tamConfe,int*indiceLibre);

/// @brief Funcion para dar de alta nuevas confederaciones.
///
/// @param listaConfederaciones Array de confederaciones.
/// @param tamConfe tamanio del array de confederaciones.
/// @param idConfederaciones puntero a variable que controla el id de las confederaciones
/// (al no usarse estas funciones, esta variable no esta en main).
/// @return La funcion retora 0 si se pudo aniadir OK o -1 en caso de error por
/// reintentos o SIN ESPACIO LIBRE EN ARRAY.
int altaConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int* idConfederaciones);

/// @brief Funcion encargada de la baja logica de las confederaciones, cambiando el campo
/// isEmpty a 1.
///
/// @param listaConfederaciones Array de confederaciones.
/// @param tamConfe Tamanio del array.
/// @return La funcion retorna -1 en caso de error o 0 si OK.
int bajaConfederacion(eConfederacion listaConfederaciones[],int tamConfe);

/// @brief Funcion que informa el iindice en el que se encuentra el ID de una confederacion dada.
/// @param lista Array de confederaciones.
/// @param tamConfe tamanio del array.
/// @param id Id de la confederacion de la cual se desea saber su indice.
/// @param respuesta Puntero a variable donde se guardara el indice(-1 en caso de no existir).
/// @return retorna 0 si OK o -1 en caso de error.
int buscarConfederacionxID(eConfederacion lista[],int tamConfe,int id,int* respuesta);

/// @brief Funcion encargada de la edicion de confederaciones.
///
/// @param lista Array de confederaciones.
/// @param tamConfe Tamanio delm array.
/// @return la funcion retorna 0 si OK o -1 en caso de error.
int editarConfederacion(eConfederacion lista[],int tamConfe);
