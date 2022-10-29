/*
 * confederaciones.c
 *
 *  Created on: 18 oct. 2022
 *      Author: leandro
 */
#include "confederaciones.h"
#include "arrayJugadores.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int imprimirConfederaciones(eConfederacion lista[], int tam, int limpiar)
{
	int retorno = -1;

	if(lista != NULL && tam >0)
	{
		if(limpiar == 1)
		{
			system("CLS");
		}
		printf("\n<++CONFEDERACIONES++>");
		printf("\n-----------------------------------------------");
		printf("\n|   ID   |   NOMBRE   |    REGION    |  ANIO  |");
		printf("\n-----------------------------------------------");

		for(int i=0;i<tam;i++)
		{
			//printf("\n-------------------------------");
			printf("\n| %6d | %-10s | %-12s | %6d |",lista[i].idConfe,lista[i].nombre,lista[i].region,lista[i].anioCreacion);
			printf("\n-----------------------------------------------");
		}
		retorno = 0;
	}

	return retorno;
}

int obtenerConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int id, char*respuesta)
{
	int retorno = -1;

	if(listaConfederaciones!=NULL && respuesta!=NULL && tamConfe>0)
	{
		for(int i=0;i<tamConfe;i++)
		{
			if(listaConfederaciones[i].idConfe == id)
			{
				strcpy(respuesta,listaConfederaciones[i].nombre);
				retorno = 0;
				break;
			}

		}

	}

	return retorno;
}




