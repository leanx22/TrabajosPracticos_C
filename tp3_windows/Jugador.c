#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "utn.h"

Jugador* jug_new()
{
	return (Jugador*)malloc(sizeof(Jugador));
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* aux = NULL;
	aux = jug_new();
	if(aux!=NULL)
	{
		aux->id = atoi(idStr);
		strncpy(aux->nombreCompleto,nombreCompletoStr,100);
		aux->edad = atoi(edadStr);
		strncpy(aux->posicion,posicionStr,30);
		strncpy(aux->nacionalidad,nacionalidadStr,30);
		aux->idSeleccion = atoi(idSeleccionStr);

		//todo Programar setters!

	}
	return aux;
}

int hardcodearNacionalidades(eNacionalidades lista[],int tam)
{
	int retorno = -1;

	if(lista!=NULL && tam>0)
	{
		lista[0].id = 1;
		strcpy(lista[0].descripcion,"saudita");

		lista[1].id = 2;
		strcpy(lista[1].descripcion,"australiano");

		lista[2].id = 3;
		strcpy(lista[2].descripcion,"coreano");

		lista[3].id = 4;
		strcpy(lista[3].descripcion,"irani");

		lista[4].id = 5;
		strcpy(lista[4].descripcion,"japones");

		lista[5].id = 6;
		strcpy(lista[5].descripcion,"qatari");

		lista[6].id = 7;
		strcpy(lista[6].descripcion,"camerunes");

		lista[7].id = 8;
		strcpy(lista[7].descripcion,"ghanes");

		lista[8].id = 9;
		strcpy(lista[8].descripcion,"marroqui");

		lista[9].id = 10;
		strcpy(lista[9].descripcion,"senegales");

		lista[10].id = 11;
		strcpy(lista[10].descripcion,"tunecino");

		lista[11].id = 12;
		strcpy(lista[11].descripcion,"canadiense");

		lista[12].id = 13;
		strcpy(lista[12].descripcion,"costarricense");

		lista[13].id = 14;
		strcpy(lista[13].descripcion,"estadounidense");

		lista[14].id = 15;
		strcpy(lista[14].descripcion,"mexicano");

		lista[15].id = 16;
		strcpy(lista[15].descripcion,"argentino");

		lista[16].id = 17;
		strcpy(lista[16].descripcion,"brasilero");

		lista[17].id = 18;
		strcpy(lista[17].descripcion,"ecuatoriano");

		lista[18].id = 19;
		strcpy(lista[18].descripcion,"uruguayo");

		lista[19].id = 20;
		strcpy(lista[19].descripcion,"aleman");

		lista[20].id = 21;
		strcpy(lista[20].descripcion,"belga");

		lista[21].id = 22;
		strcpy(lista[21].descripcion,"croata");

		lista[22].id = 23;
		strcpy(lista[22].descripcion,"danes");

		lista[23].id = 24;
		strcpy(lista[23].descripcion,"espanol");

		lista[24].id = 25;
		strcpy(lista[24].descripcion,"frances");

		lista[25].id = 26;
		strcpy(lista[25].descripcion,"gales");

		lista[26].id = 27;
		strcpy(lista[26].descripcion,"holandes");

		lista[27].id = 28;
		strcpy(lista[27].descripcion,"ingles");

		lista[28].id = 29;
		strcpy(lista[28].descripcion,"polaco");

		lista[29].id = 30;
		strcpy(lista[29].descripcion,"portugues");

		lista[30].id = 31;
		strcpy(lista[30].descripcion,"serbio");

		lista[31].id = 32;
		strcpy(lista[31].descripcion,"suizo");

		retorno = 0;
	}
	return retorno;
}

int imprimirNacionalidades(eNacionalidades lista[],int tam)
{
	int retorno = -1;

	if(lista!=NULL && tam>0)
	{

		system("CLS");
		printf("\n|ID|   NACIONALIDADES   |");
		for(int i=0;i<tam;i++)
		{
			printf("\n|%2d|%-20s|",lista[i].id,lista[i].descripcion);
			printf("\n-------------------------");
		}
		retorno = 0;
	}

	return retorno;
}




