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
			printf("*** COSTOS DE MANTENIMIENTO ***");
			printf("\n1)Costo de hospedaje: %.2f \n2)Costo de comida: %.2f \n3)Costo de transporte: %.2f \n4)Volver al menu.",
					*hospedaje,*comida,*transporte);

			if(utn_pedirInt(&opcion,"\nIngrese una opcion: ","\nERROR!, reintente.",1,4,3)==0)
			{
				switch(opcion)
				{
					case 1:
						if(utn_pedirFloat(hospedaje,"\nNuevo costo de hospedaje: ","\nError, reintente.",1,9999999,3)!=0){
							printf("\nHubo un error durante la actualizacion del precio. (Muchos reintentos?)");
						}else{
							printf("\nActualizado correctamente!");
						}
						pausa();
						break;

					case 2:
						if(utn_pedirFloat(comida,"\nNuevo costo de comida: ","\nError, reintente.",1,9999999,3)!=0){
							printf("\nHubo un error durante la actualizacion del precio. (Muchos reintentos?)");
						}else{
							printf("\nActualizado correctamente!");
						}
						pausa();
						break;

					case 3:
						if(utn_pedirFloat(transporte,"\nNuevo costo de transporte: ","\nError, reintente.",1,9999999,3)!=0){
							printf("\nHubo un error durante la actualizacion del precio. (Muchos reintentos?)");
						}else{
							printf("\nActualizado correctamente!");
						}
						pausa();
						break;

					case 4:
						continuar = 0;
						break;
					default:
						printf("\nNo corresponde a una opcion.");
				}

			}else{
				printf("\nError al seleccionar la opcion. (demasiados reintentos?).");
				pausa();
			}

			}while(continuar==1);
		retorno = 0;
	}

	return retorno;
}

int cargaJugadores(int* cArqueros,int* cDefensores,int* cMedioc,int* cDelanteros,
		int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int camisetas[])
{

	int retorno = -1;

	//Vars del submenu.
	int continuar = 1;
	int opcion;
	int totalJugadores;

	int confederacion;

	int camiseta;

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

			if(utn_pedirInt(&opcion,"\nIngrese su opcion: ","\nerror, reintente!",1,5,3)==0){//agregar al if si son mas de 22 jugadores

				switch(opcion){
					case 1:
						if(datosJugador(&camiseta,&confederacion)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0){

							*cArqueros+=1;
							printf("\nJugador agregado correctamente!");
							pausa();
						}else{
							printf("\nOcurrio un problema al aniadir el jugador!");
							pausa();
						}
						break;
					case 2:
						if(datosJugador(&camiseta,&confederacion)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0){

							*cDefensores+=1;
							printf("\nJugador agregado correctamente!");
							pausa();
						}else{
							printf("\nOcurrio un problema al aniadir el jugador!");
							pausa();
						}
						break;

					case 3:
						if(datosJugador(&camiseta,&confederacion)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0){

							*cMedioc+=1;
							printf("\nJugador agregado correctamente!");
							pausa();
						}else{
							printf("\nOcurrio un problema al aniadir el jugador!");
							pausa();
						}
						break;

					case 4:
						if(datosJugador(&camiseta,&confederacion)==0 &&
								sumarConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC,confederacion)==0){

							*cDelanteros+=1;
							printf("\nJugador agregado correctamente!");
							pausa();
						}else{
							printf("\nOcurrio un problema al aniadir el jugador!");
							pausa();									}
						break;

					case 5:
						continuar = 0;
						break;
				}

			}//un else que diga que ya se alcanzo el maximo de jugadores.

		}while(continuar == 1);

		retorno = 0;
	}


	return retorno;
}


int datosJugador(int* camisetas, int* confederacion){

	int retorno =-1;
	//int camiseta;

	if(camisetas != NULL){
		if(utn_pedirInt(camisetas,"\nIngrese el numero de la camiseta: ","\nError, fuera de rango.",1,99,3)==0 &&
				utn_pedirInt(confederacion,"\nCONFEDERACION?\n1.AFC\n2.CAF\n3.CONCACAF\n4.CONMEBOL\n5.UEFA"
						"\n6.OFC\nIngrese una opcion: ","\nError, reintente.",1,6,3)==0){
			retorno = 0;
		}

	}


	return retorno;
}


int sumarConfederacion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC,int confederacion){

	int retorno = -1;

	if(AFC != NULL && CAF != NULL && CONCACAF != NULL && CONMEBOL != NULL && UEFA != NULL && OFC != NULL &&
		confederacion>0 && confederacion<7){

		switch(confederacion){
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





