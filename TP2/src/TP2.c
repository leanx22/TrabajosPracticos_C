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
#include "informes.h"
#include "utn.h"

#define MAX_JUGADORES 3000
#define CANT_CONFEDERACIONES 6

int main(void) {
	setbuf(stdout, NULL);

	int idJugador = 100;
	int altas = 0;

	float totalSalarios=0;

	int continuar = 1;
	int opcion;


	eJugador listaJugadores[MAX_JUGADORES];
	inicializarArray(listaJugadores,MAX_JUGADORES);

	eConfederacion confederaciones[CANT_CONFEDERACIONES]=
	{{1000,"AFC","Asia",1954}, {1001,"CAF","Africa",1957}, {1002,"CONCACAF","Zona Norte",1961},
	{1003,"CONMEBOL","Sudamerica",1916}, {1004,"UEFA","Europa",1954}, {1005,"OFC","Oceania",1966}};

	//HARDCODE//
	hardcodear(listaJugadores,0,&idJugador,"Esteban","Delantero",9,1004,120345,5,&altas,&totalSalarios);
	hardcodear(listaJugadores,1,&idJugador,"Agustin","Delantero",8,1002,120346,3,&altas,&totalSalarios);
	hardcodear(listaJugadores,2,&idJugador,"zaza","Defensor",4,1001,32000,6,&altas,&totalSalarios);
	hardcodear(listaJugadores,3,&idJugador,"Abigail","Arquero",1,1002,183675,8,&altas,&totalSalarios);
	//HARDCODE//

	do{
		system("CLS");
		printf("\n--|Menu principal|--"
				"\n1)Nuevo jugador."
				"\n2)Baja de jugador."
				"\n3)Modificar jugador."
				"\n4)Informes."
				"\n5)Salir.");
		utn_pedirInt(&opcion,"\n>Ingrese una opcion: ","\n[!]Error, no es una opcion valida.",1,5,99);

		switch(opcion)
		{
		case 1:
			if(cargaJugador(listaJugadores,confederaciones,MAX_JUGADORES,CANT_CONFEDERACIONES,&idJugador,&altas,&totalSalarios)==0)
			{
				printf("\n[>]Jugador agregado correctamente!");
				system("PAUSE");
			}
			else{
				printf("\n[!]No se pudo agregar al jugador!\n");
				system("PAUSE");
			}
			break;
		case 2:
			if(altas>0 && ordenarxID(listaJugadores,MAX_JUGADORES)==0 &&
				listarJugadores(listaJugadores,confederaciones,MAX_JUGADORES,CANT_CONFEDERACIONES,1)==0 &&
				bajaJugador(listaJugadores,MAX_JUGADORES,&altas,&totalSalarios)==0)
			{
				printf("\n[>]Jugador ELIMINADO de manera SATISFACTORIA!\n");
				system("PAUSE");
			}else{
				printf("\n[!]Jugador inexistente, se cancelo la operacion o NO HAY JUGADORES CARGADOS!\n");
				system("PAUSE");
			}
			break;
		case 3:
			if(altas>0 && ordenarxID(listaJugadores,MAX_JUGADORES)==0 &&
				ordenarxID(listaJugadores,MAX_JUGADORES)==0 &&
				listarJugadores(listaJugadores,confederaciones,MAX_JUGADORES,CANT_CONFEDERACIONES,1)==0)
			{
				editarJugador(listaJugadores,confederaciones,MAX_JUGADORES,CANT_CONFEDERACIONES);
			}
			else{
				printf("\n[!]Ocurrio un error o no hay jugadores cargados!\n");
				system("PAUSE");
			}
			break;
		case 4:
			if(altas>0)
			{
				informes(listaJugadores,confederaciones,MAX_JUGADORES,CANT_CONFEDERACIONES,totalSalarios,altas);
			}else{
				printf("\n[!]Aun no hay jugadores cargados!\n");
				system("PAUSE");
			}
			break;
		case 5:
			utn_pedirInt(&continuar,"\nSeguro que desea salir?\n0.SALIR\n1.CANCELAR\n>Ingrese: ","\n[!]Error, no es una opcion valida, Reintente.",0,1,3);
			break;
		default:
			printf("\n[!]No es un comando valido.");
		}

	}while(continuar == 1);

	return 0;
}
