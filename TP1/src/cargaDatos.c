/*
 * cargaDatos.c
 *
 *  Created on: 12 sep. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "cargaDatos.h"
#include "utn.h"

int costosMantenimiento(float* hospedaje,float* comida,float* transporte)
{

	int retorno = -1;
	//Variables del subMenu de los costos de mantenimiento.
	int opcion;
	int continuar=1;

	if(hospedaje != NULL && comida != NULL && transporte != NULL)
	{
		do{
			system("CLS");
			printf("\n\n*** COSTOS DE MANTENIMIENTO ***");
			printf("\n1)Costo de hospedaje: %.2f \n2)Costo de comida: %.2f \n3)Costo de transporte: %.2f \n4)Volver al menu.",
					*hospedaje,*comida,*transporte);

			if(utn_pedirInt(&opcion,"\nIngrese una opcion: ","\nERROR!, reintente.",1,4,3)==0)
			{
				switch(opcion)
				{
					case 1:
						if(utn_pedirFloat(hospedaje,"\nNuevo costo de hospedaje: ","\nError, reintente.",1,9999999,3)!=0){
							printf("\nHubo un error durante la actualizacion del precio. (Muchos reintentos?)\n");
							system("PAUSE");
						}else{
							printf("\nActualizado correctamente!\n");
							system("PAUSE");
						}
						break;

					case 2:
						if(utn_pedirFloat(comida,"\nNuevo costo de comida: ","\nError, reintente.",1,9999999,3)!=0){
							printf("\nHubo un error durante la actualizacion del precio. (Muchos reintentos?)\n");
							system("PAUSE");
						}else{
							printf("\nActualizado correctamente!");
							system("PAUSE");
						}
						break;

					case 3:
						if(utn_pedirFloat(transporte,"\nNuevo costo de transporte: ","\nError, reintente.",1,9999999,3)!=0){
							printf("\nHubo un error durante la actualizacion del precio. (Muchos reintentos?)\n");
							system("PAUSE");
						}else{
							printf("\nActualizado correctamente!\n");
							system("PAUSE");
						}
						break;

					case 4:
						if(*hospedaje!=0 && *transporte!=0 && *comida!=0)
						{
							continuar = 0;
						}else
						{
							printf("\nES OBLIGATORIO COMPLETAR TODOS LOS COSTOS\n");
							system("PAUSE");
						}
						break;
				}

			}else{
				printf("\nError al seleccionar la opcion. (demasiados reintentos?).\n");
				system("PAUSE");
			}

			}while(continuar==1);
		retorno = 0;
	}

	return retorno;
}

int cargaJugadores(int* cArqueros,int* cDefensores,int* cMedioc,int* cDelanteros,
		int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int camisetas[],int tam)
{

	int retorno = -1;

	//Vars del submenu.
	int continuar = 1;
	int opcion;
	int totalJugadores;

	int confederacion;

	if(cArqueros != NULL && cDefensores != NULL && cMedioc != NULL && cDelanteros != NULL &&
		AFC != NULL && CAF != NULL && CONCACAF != NULL && CONMEBOL != NULL && UEFA != NULL && OFC != NULL)
	{
		do{

			totalJugadores = *cArqueros+*cDefensores+*cMedioc+*cDelanteros;

			system("CLS");
			printf("*** CARGA DE JUGADORES || JUGADORES ACTUALES: %d ***"
					"\n1.Agregar Arquero. -> %d"
					"\n2.Agregar Defensor. -> %d"
					"\n3.Agregar Mediocampista. -> %d"
					"\n4.Agregar Delantero. -> %d"
					"\n5.Volver al menu.",
					totalJugadores,*cArqueros,*cDefensores,*cMedioc,*cDelanteros);

			if(totalJugadores<22 && utn_pedirInt(&opcion,"\nIngrese su opcion: ","\nerror, reintente!",1,5,3)==0)
			{

				switch(opcion)
				{
					case 1:
						if(*cArqueros<2)
						{
							if(datosJugador(&confederacion,camisetas,tam)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0)
							{

								*cArqueros+=1;
								printf("\nJugador agregado correctamente!\n");
								system("PAUSE");
							}else
							{
								printf("\nOcurrio un problema al aniadir el jugador!\n");
								system("PAUSE");
							}
						}else
						{
							printf("\nMaxima cantidad de arqueros alcanzada!\n");
							system("PAUSE");
						}
						break;
					case 2:
						if(*cDefensores<8)
						{
							if(datosJugador(&confederacion,camisetas,tam)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0)
							{

								*cDefensores+=1;
								printf("\nJugador agregado correctamente!\n");
								system("PAUSE");
							}
							else
							{
								printf("\nOcurrio un problema al aniadir el jugador!\n");
								system("PAUSE");
							}
						}
						else
						{
							printf("\nMaxima cantidad de defensores alcanzada!\n");
							system("PAUSE");
						}
						break;

					case 3:
						if(*cMedioc<8)
						{
							if(datosJugador(&confederacion,camisetas,tam)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0)
							{

								*cMedioc+=1;
								printf("\nJugador agregado correctamente\n");
								system("PAUSE");
							}
							else
							{
								printf("\nOcurrio un problema al aniadir el jugador!\n");
								system("PAUSE");
							}
						}
						else
						{
							printf("\nMaxima cantidad de mediocampistas alcanzada!\n");
							system("PAUSE");
						}
						break;

					case 4:
						if(*cDelanteros<4)
						{
							if(datosJugador(&confederacion,camisetas,tam)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0)
							{

								*cDelanteros+=1;
								printf("\nJugador agregado correctamente!\n");
								system("PAUSE");
							}
							else
							{
								printf("\nOcurrio un problema al aniadir el jugador!\n");
								system("PAUSE");
							}
						}else{
							printf("\nYa se alcanzo la cantidad maxima de delanteros!\n");
							system("PAUSE");
						}
						break;

					case 5:
						if(*cDelanteros!=0 || *cMedioc!=0 || *cDefensores!=0 || *cArqueros!=0)
						{
							continuar = 0;
						}
						else
						{
							printf("\nSe debe agregar por lo menos un jugador antes de salir!\n");
							system("PAUSE");
						}
						break;
				}

			}
			else
			{
				printf("\nDemasiados intentos o ya se alcanzo la maxima cantidad de jugadores (22)!\n");
				system("PAUSE");
			}

		}while(continuar == 1);

		retorno = 0;
	}


	return retorno;
}


int datosJugador(int* confederacion,int camisetas[],int tam){

	int retorno =-1;
	int camiseta;

	if(camisetas != NULL && confederacion!=NULL && tam>0)
	{

		if(utn_pedirInt(&camiseta,"\nIngrese el numero de la camiseta: ","\nError, fuera de rango(1-99).",1,99,3)==0 &&
			comprobarCamiseta(camisetas,tam, camiseta)!=0)
		{

			utn_pedirInt(confederacion,"\nCONFEDERACION?\n1.AFC\n2.CAF\n3.CONCACAF\n4.CONMEBOL\n5.UEFA"
			"\n6.OFC\nIngrese una opcion: ","\nError, reintente.",1,6,99);

			retorno=cargarCamiseta(camisetas,tam,camiseta);

		}else{
			printf("\nParece que esa camiseta ya esta en uso o se ingreso un valor invalido mas de 3 veces!");
		}

	}

	return retorno;
}

int sumarConfederacion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int confederacion){

	int retorno = -1;

	if(AFC != NULL && CAF != NULL && CONCACAF != NULL && CONMEBOL != NULL && UEFA != NULL && OFC != NULL &&
		confederacion>0 && confederacion<7)
	{

		switch(confederacion)
		{
			case 1:
				*AFC+=1;
				break;
			case 2:
				*CAF+=1;
				break;
			case 3:
				*CONCACAF+=1;
				break;
			case 4:
				*CONMEBOL+=1;
				break;
			case 5:
				*UEFA+=1;
				break;
			case 6:
				*OFC+=1;
		}
		retorno =0;
	}

	return retorno;
}

int inicializarCamisetas(int camisetas[],int tam)
{
	int retorno = -1;
	if(camisetas != NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			camisetas[i] = -1;
		}
		retorno = 0;
	}


	return retorno;
}

int comprobarCamiseta(int camisetas[],int tam, int busqueda)
{
	int retorno = -1;

		if(camisetas!=NULL && tam>0 && busqueda>0 && busqueda<100)
		{
			for(int i=0;i<tam;i++)
			{
				if(camisetas[i]==busqueda)
				{
					retorno = 0;
					break;
				}
			}
		}
	return retorno;
}

int cargarCamiseta(int camisetas[],int tam,int agregar)
{
	int retorno = -1;

	if(camisetas!=NULL && tam>0 && agregar>0 && agregar < 100)
	{
		for(int i=0;i<tam;i++)
		{
			if(camisetas[i]==-1)
			{
				camisetas[i]=agregar;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
