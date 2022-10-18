/*
 * arrayJugadores.c
 *
 *  Created on: 18 oct. 2022
 *      Author: leank
 */
#include "arrayJugadores.h"
#include "confederaciones.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>


int inicializarArray(eJugador lista[], int tam)
{
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0;i<tam;i++)
		{
			lista[i].isEmpty = 1;
		}

		retorno = 0;
	}


	return retorno;
}

int buscarLibre(eJugador lista[], int tam)
{
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int cargaJugador(eJugador lista[], int tam)
{
	int retorno = -1;
	int indiceLibre;

	char buffNombre[50];
	char buffPosi[50];
	int buffCamiseta;
	int idConfe;
	float buffSalario;
	short aniosContrato;

	if(lista != NULL && tam > 0)
	{
		indiceLibre = buscarLibre(lista,tam);
		if(indiceLibre != -1)
		{
			if(utn_getStr(buffNombre,"\n>Ingrese nombre del jugador: ","\n[!]Error, reintente.",50,3)==0 &&
				utn_getStr(buffPosi,"\n>Ingrese la posicion: ","\n[!]Error, reintente.",50,3)==0 &&
				utn_pedirInt(&buffCamiseta,"\n>Ingrese numero de camiseta: ","\n[!]Error, fuera de rango.",1,99,3)==0)
			{

			}

		}
		else
		{
			printf("\n[!]Error, no hay mas espacios libres!");
		}
	}

	return retorno;
}
