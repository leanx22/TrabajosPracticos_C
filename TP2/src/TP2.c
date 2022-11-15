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

	int idJugador = 0;

	int altas = 0;

	float totalSalarios=0;

	int continuar = 1;
	int opcion;


	eJugador listaJugadores[MAX_JUGADORES];
	inicializarArray(listaJugadores,MAX_JUGADORES);

	eConfederacion confederaciones[CANT_CONFEDERACIONES]=
	{{100,"CONMEBOL","Sudamerica",1916},{101,"UEFA","Europa",1954},{102,"AFC","Asia",1954},
	 {103,"CAF","Africa",1957},{104,"CONCACAF","Norte y centro america",1961},{105,"OFC","Oceania",1966}};

	//HARDCODE//
	//hardcodear(listaJugadores,2,&idJugador,"Esteban","Delantero",9,104,120345,5,&altas,&totalSalarios);
	//hardcodear(listaJugadores,1,&idJugador,"Agustin","Delantero",8,102,120346,3,&altas,&totalSalarios);
	//hardcodear(listaJugadores,0,&idJugador,"zaza","Defensor",4,101,32000,6,&altas,&totalSalarios);
	//hardcodear(listaJugadores,3,&idJugador,"Abigail","Arquero",1,102,183675,8,&altas,&totalSalarios);
	hardcodear(listaJugadores,0,&idJugador,"Emiliano Martinez","ARQUERO",1,100,100000,4,&altas,&totalSalarios);
	hardcodear(listaJugadores,1,&idJugador,"Juan Musso","ARQUERO",12,100,80000,2,&altas,&totalSalarios);
	hardcodear(listaJugadores,2,&idJugador,"Leo Messi","DELANTERO",10,100,80000,4,&altas,&totalSalarios);
	hardcodear(listaJugadores,3,&idJugador,"Almirez Ali","ARQUERO",1,100,55000,1,&altas,&totalSalarios);
	hardcodear(listaJugadores,4,&idJugador,"Harry Maguire","DEFENSOR",2,101,70000,4,&altas,&totalSalarios);
	hardcodear(listaJugadores,5,&idJugador,"Eric Dier","DEFENSOR",2,101,60000,2,&altas,&totalSalarios);
	hardcodear(listaJugadores,6,&idJugador,"Harry Kane","DELANTERO",10,101,3000,2,&altas,&totalSalarios);
	hardcodear(listaJugadores,7,&idJugador,"Alfred Gomis","ARQUERO",1,101,9000,1,&altas,&totalSalarios);
	hardcodear(listaJugadores,8,&idJugador,"Abdel Hassan","MEDIOCAMPISTA",7,101,48000,1,&altas,&totalSalarios);
	hardcodear(listaJugadores,9,&idJugador,"Guillermo Ochoa","ARQUERO",1,104,90000,4,&altas,&totalSalarios);
	hardcodear(listaJugadores,10,&idJugador,"Tecatito","DELANTERO",11,104,100000,3,&altas,&totalSalarios);
	hardcodear(listaJugadores,11,&idJugador,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,&altas,&totalSalarios);
	hardcodear(listaJugadores,12,&idJugador,"Bamba Dieng","DELANTERO",9,103,100000,2,&altas,&totalSalarios);
	hardcodear(listaJugadores,13,&idJugador,"Demba Seck","DELANTERO",11,103,6000,2,&altas,&totalSalarios);
	hardcodear(listaJugadores,14,&idJugador,"Tarek Salman","DEFENSOR",6,102,78000,5,&altas,&totalSalarios);

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
				//ordenarxID(listaJugadores,MAX_JUGADORES)==0 &&
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
