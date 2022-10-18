/*
 * confederaciones.h
 *
 *  Created on: 18 oct. 2022
 *      Author: leank
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

int imprimirConfederaciones(eConfederacion lista[], int tam, int limpiar);


