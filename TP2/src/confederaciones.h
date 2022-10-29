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
/// @param id ID de la confederacion la cujal se quiere saber el nombre
/// @param respuesta variable donde se guardara la respuesta
/// @return retorna 0 si tod OK o -1 si hay error o el ID no existe
int obtenerConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int id,char*respuesta);

//ABM
int inicializarConfederaciones(eConfederacion listaConfederaciones[],int tamConfe);

int buscarConfederacionLibre(eConfederacion listaConfederaciones[],int tamConfe,int*indiceLibre);

int altaConfederacion(eConfederacion listaConfederaciones,int tamConfe);


