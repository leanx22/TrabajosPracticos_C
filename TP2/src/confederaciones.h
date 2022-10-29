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

}eConfederacion;

#endif /* CONFEDERACIONES_H_ */

/// @brief
///
/// @param lista
/// @param tam
/// @param limpiar
/// @return
int imprimirConfederaciones(eConfederacion lista[], int tam, int limpiar);

/// @brief
///
/// @param listaConfederaciones
/// @param tamConfe
/// @param id
/// @param respuesta
/// @return
int obtenerConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int id,char*respuesta);






