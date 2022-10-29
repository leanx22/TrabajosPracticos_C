/*
 * informes.c
 *
 *  Created on: 29 oct. 2022
 *      Author: leandro
 */
#include "confederaciones.h"
#include "arrayJugadores.h"
#include "informes.h"
#include "utn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int informes(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe,float totalSalario,int altas)
{
	int retorno = -1;

	int opcion;
	int continuar=1;


	do{
		system("CLS");
		printf("<==========INFORMES==========>"
				"\n1.Listar jugadores alfabeticamente por su CONFEDERACION y NOMBRE del jugador."
				"\n2.Listar confederaciones con sus jugadores."
				"\n3.Total y promedio de los salarios + cuantos jugadores superan el promedio."
				"\n4.Confederacion con mayor cantidad de anios de contrato."
				"\n5.Porcentaje de jugadores en cada confederacion."
				"\n6.La region con mas jugadores y el listado de ellos."
				"\n7.VOLVER AL MENU.");
		if(utn_pedirInt(&opcion,"\n>Ingrese la opcion deseada: ","\n[!]Error, reintente.",1,7,3)==0)
		{
			switch(opcion)
			{
			case 1:
				ordenarxConfederacionYnombre(listaJugadores,listaConfe,tamJugadores,tamConfe);
				listarJugadores(listaJugadores,listaConfe,tamJugadores,tamConfe,0);
				printf("\n");
				system("PAUSE");
				break;
			case 2:
				if(listarConfederacionYjugadores(listaJugadores,listaConfe,tamJugadores,tamConfe,1)!=0){
					printf("\n[!]Ocurrio un error inesperado!");
					system("PAUSE");
				}
				break;
			case 3:
				if(infoSalarios(listaJugadores,tamJugadores,totalSalario,altas)!=0){
					printf("\n[!]Ocurrio un error inesperado!");
					system("PAUSE");
				}
				break;
			case 4:
				confederacionConMasContratos(listaJugadores,tamJugadores);
				break;
			case 7:
				retorno = 0;
				continuar = 0;
				break;

			}


		}


	}while(continuar==1);

	return retorno;
}

int listarConfederacionYjugadores(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe,int cls)
{
	int retorno = -1;
	char confederacion[50];

		if(listaJugadores!=NULL && tamJugadores>0)
		{
			if(cls == 1){
				system("CLS");
			}

			for(int i=0;i<tamConfe;i++)
			{
				printf("\n----------------------------------------------------------------------------------------------------");
				printf("\n>JUGADORES DE LA CONFEDERACION %s:",listaConfe[i].nombre);
				for(int j=0;j<tamJugadores;j++)
				{
					if(listaJugadores[j].isEmpty==0 && listaJugadores[j].idConfederacion==listaConfe[i].idConfe)
					{
						obtenerConfederacion(listaConfe,tamConfe,listaJugadores[j].idConfederacion,confederacion);

						printf("\n|%6d|%-20s|%14s|%10d|%11.2f|%15s|%16d|",
						listaJugadores[j].id,listaJugadores[j].nombre,listaJugadores[j].posicion,listaJugadores[j].numCamiseta,
						listaJugadores[j].salario,confederacion,listaJugadores[j].anioContrato);

					}
				}

			}

			printf("\n");
			system("PAUSE");
			retorno =0;
		}

		return retorno;
}

int ordenarxConfederacionYnombre(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe)
{
	int retorno = -1;
	char nombreConfe_i[50];
	char nombreConfe_j[50];
	eJugador aux;

	if(listaJugadores!=NULL && listaConfe!=NULL && tamJugadores>0 && tamConfe>0)
	{
		printf("\nEstoy ordenando! [Alfabetico por confederacion y nombre]\n");
		for(int i=0;i<tamJugadores-1;i++)
		{

			for(int j=i+1;j<tamJugadores;j++)
			{
				obtenerConfederacion(listaConfe,tamConfe,listaJugadores[i].idConfederacion,nombreConfe_i);
				obtenerConfederacion(listaConfe,tamConfe,listaJugadores[j].idConfederacion,nombreConfe_j);
				if(strcmp(nombreConfe_i,nombreConfe_j)>0)
				{
					aux = listaJugadores[i];
					listaJugadores[i] = listaJugadores[j];
					listaJugadores[j] = aux;
				}

				if(strcmp(nombreConfe_i,nombreConfe_j)==0 &&
					strcmp(listaJugadores[i].nombre,listaJugadores[j].nombre)>0)
				{
					aux = listaJugadores[i];
					listaJugadores[i] = listaJugadores[j];
					listaJugadores[j] = aux;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

int infoSalarios(eJugador listaJugadores[],int tamJugadores,float totalSalarios,int totalJugadores)
{
	int retorno=-1;
	float promedio=0;
	int cantidadSuperan=0;

	if(listaJugadores!=NULL && tamJugadores>0 && totalSalarios>0 && totalJugadores>0)
	{
		system("CLS");
		printf("\nTotal de todos los sueldo: %f",totalSalarios);
		promedio = totalSalarios/totalJugadores;
		printf("\nEl promedio de los sueldos es de %.2f",promedio);

		for(int i=0;i<tamJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0 && listaJugadores[i].salario>promedio)
			{
				cantidadSuperan++;
			}
		}
		printf("\nLa cantidad de jugadores que superan el sueldo promedio es de: %d\n",cantidadSuperan);
		system("PAUSE");
		retorno = 0;
	}

	return retorno;
}

int confederacionConMasContratos(eJugador listaJugadores[],int tamJugadores)
{
	int retorno = -1;

	int cAFC=0;
	int cCAF=0;
	int cCONCACAF=0;
	int cCONMEBOL=0;
	int cUEFA=0;
	int cOFC=0;

	char nombre[25];

	if(listaJugadores!=NULL && tamJugadores>0)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0)
			{
				switch(listaJugadores[i].idConfederacion)
				{
				case 1000:
					cAFC+=listaJugadores[i].anioContrato;
					break;
				case 1001:
					cCAF+=listaJugadores[i].anioContrato;
					break;
				case 1002:
					cCONCACAF+=listaJugadores[i].anioContrato;
					break;
				case 1003:
					cCONMEBOL+=listaJugadores[i].anioContrato;
					break;
				case 1004:
					cUEFA+=listaJugadores[i].anioContrato;
					break;
				case 1005:
					cOFC+=listaJugadores[i].anioContrato;
					break;
				}
			}
		}


		if(cAFC>cCAF && cAFC>cCONCACAF && cAFC>cCONMEBOL && cAFC>cUEFA && cAFC>cOFC)
		{
			strcpy(nombre,"AFC");
		}
		else if(cCAF>cCONCACAF && cCAF>cCONMEBOL && cCAF>cUEFA && cCAF>cOFC)
		{
			strcpy(nombre,"CAF");
		}
		else if(cCONCACAF>cCONMEBOL && cCONCACAF>cUEFA && cCONCACAF>cOFC)
		{
			strcpy(nombre,"CONCACAF");
		}
		else if(cCONMEBOL>cUEFA && cCONMEBOL>cOFC)
		{
			strcpy(nombre,"CONMEBOL");
		}
		else if(cUEFA>cOFC)
		{
			strcpy(nombre,"UEFA");
		}
		else
		{
			strcpy(nombre,"OFC");
		}
		system("CLS");
		printf("\nLa confederacion que cuenta con mas anios de contrato es: %s\n",nombre);
		retorno=0;
		system("PAUSE");
	}

	return retorno;
}









