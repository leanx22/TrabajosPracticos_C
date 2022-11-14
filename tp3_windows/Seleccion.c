#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "Jugador.h"
#include "utn.h"


Seleccion* selec_new()
{
	return (Seleccion*)malloc(sizeof(Seleccion));
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* aux = NULL;

	if(idStr!=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{
		aux=selec_new();
		if(aux!=NULL)
		{
			aux->id = atoi(idStr);
			strcpy(aux->pais,paisStr);
			strcpy(aux->confederacion,confederacionStr);
			aux->convocados = atoi(convocadosStr);

			//todo LOS SETTERS!
		}
	}

	return aux;
}
