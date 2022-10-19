/*
 * arrayJugadores.h
 *
 *  Created on: 18 oct. 2022
 *      Author: leank
 */
#include "confederaciones.h"
#ifndef ARRAYJUGADORES_H_
#define ARRAYJUGADORES_H_

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numCamiseta;
	int idConfederacion;
	float salario;
	short anioContrato;
	short isEmpty;

}eJugador;

#endif /* ARRAYJUGADORES_H_ */

int inicializarArray(eJugador lista[], int tam);


int buscarLibre(eJugador lista[], int tam);


int cargaJugador(eJugador lista[],eConfederacion listaConfe[],int tam,int tamConf,int*ids);


