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

int cargaJugador(eJugador lista[],eConfederacion listaConfe[],int tam,int tamConf,int*ids)
{
	int retorno = -1;
	int indiceLibre;

	char nombre[50];
	char posi[50];
	int camiseta;
	int idConfe;
	float salario;
	int aniosContrato; //short! casteo

	if(lista != NULL && tam > 0 && ids!=NULL)
	{
		system("CLS");
		printf("\n>Carga de jugador nuevo<");
		indiceLibre = buscarLibre(lista,tam);
		if(indiceLibre != -1 &&
			utn_getStr(nombre,"\n>Ingrese nombre del jugador: ","\n[!]Error, reintente.",50,3)==0 &&
			utn_getStr(posi,"\n>Ingrese la posicion: ","\n[!]Error, reintente.",50,3)==0 &&
			utn_pedirInt(&camiseta,"\n>Ingrese numero de camiseta: ","\n[!]Error, fuera de rango.",1,99,3)==0 &&
			utn_pedirFloat(&salario,"\n>Ingrese el salario: ","\n[!]Error!, reintente.",1,9999999,3)==0 &&
			utn_pedirInt(&aniosContrato,"\n>Ingrese anios de contrato: ","\n[!]Error, fuera de rango.",1,99,3)==0 &&
			imprimirConfederaciones(listaConfe,tamConf,0)==0 &&
			utn_pedirInt(&idConfe,"\n>Ingrese Id de la confederacion:","\n[!]Error, reintente",1000,1005,3)==0)
		{

			strcpy(lista[indiceLibre].nombre,nombre);
			strcpy(lista[indiceLibre].posicion,posi);
			lista[indiceLibre].numCamiseta = (short)camiseta;
			lista[indiceLibre].salario = salario;
			lista[indiceLibre].anioContrato = (short)aniosContrato;
			lista[indiceLibre].idConfederacion=idConfe;
			lista[indiceLibre].id = *ids;
			*ids += 1;
			retorno = 0;
		}
		else
		{
			printf("\n[!]Error, demasiados reintentos o no hay mas espacios libres!");
			system("PAUSE");
		}
	}

	return retorno;
}
