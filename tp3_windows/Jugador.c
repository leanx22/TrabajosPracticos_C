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
