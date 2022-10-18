/*
 ============================================================================
 Name        : TP2.c
 Author      : Guia Leandro
 Version     :
 Copyright   :
 Description : TP n°2 para Laboratorio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayJugadores.h"
#include "confederaciones.h"
#include "utn.h"

#define MAX_JUGADORES 3000
#define CANT_CONFEDERACIONES 6

int main(void) {
	setbuf(stdout, NULL);

	int idJugador = 100;

	int continuar = 1;
	int opcion;


	eJugador listaJugadores[MAX_JUGADORES];
	eConfederacion confederaciones[CANT_CONFEDERACIONES]=
	{{1000,"AFC","Asia",1954},
	{1001,"CAF","Africa",1957},
	{1002,"CONCACAF","Zona Norte",1961},
	{1003,"CONMEBOL","Sudamerica",1916},
	{1004,"UEFA","Europa",1954},
	{1005,"OFC","Oceania",1966}};

	inicializarArray(listaJugadores,MAX_JUGADORES);

	do{
		printf(">>Menu principal"
				"\n1)Nuevo jugador."
				"\n2)Baja de jugador."
				"\n3)Modificar jugador."
				"\n4)Informes."
				"\n5)Salir.");
		utn_pedirInt(&opcion,"\n->Ingrese una opcion: ","\n[!]Error, no es una opcion valida.",1,5,99);

		switch(opcion)
		{
		case 1:
			break;

		case 5:
			continuar = 0;
			break;
		default:
			printf("\n[!]No es un comando valido.");
		}

	}while(continuar == 1);

	return 0;
}
