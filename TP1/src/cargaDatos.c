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
		int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC)
{

	int retorno = -1;

	//Vars del submenu.
	int continuar = 1;
	int opcion;


	if(cArqueros != NULL && cDefensores != NULL && cMedioc != NULL && cDelanteros != NULL &&
		AFC != NULL && CAF != NULL && CONCACAF != NULL && CONMEBOL != NULL && UEFA != NULL && OFC != NULL)
	{
		do{
			system("CLS");
			printf("*** CARGA DE JUGADORES ***"
					"\n1.Agregar Arquero. -> %d"
					"\n2.Agregar Defensor. -> %d"
					"\n3.Agregar Mediocampista. -> %d"
					"\n4.Agregar Delantero. -> %d"
					"\n5.Volver al menu.",
					*cArqueros,*cDefensores,*cMedioc,*cDelanteros);

			if(utn_pedirInt(&opcion,"\nIngrese una opcion: ", "\nERROR! Reintente.",1,5,3)==0){

				switch(opcion){
					case 1:
						printf("\nIngrese el numero de la camiseta: ");
						getch(); //utilizo un getch para emular que tomo el dato, no lo guardo ya que no se le da uso en ninguna consigna.
								//Si fuera necesario el dato, entonces utilizaria mi funcion pedirInt() para validar que se ingrese un int valido.

						if(cargaConfederacion(AFC,CAF,CONCACAF,CONMEBOL,UEFA,OFC)!=-1){
							*cArqueros+=1;
							printf("\nEl jugador se agrego correctamente!.");
							pausa();
						}else{
							printf("\nOcurrio un error al intentar agregar al jugador, reintente.");
							pausa();
						}
						break;//caso1
					case 5:
						continuar = 0;
						break;//caso5
				}//switch

			}//if1

		}while(continuar == 1);

		retorno = 0;
	}


	return retorno;
}


int cargaConfederacion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC)
{
	int retorno = -1;
	int confederacion;

	if(AFC!=NULL && CAF!=NULL && CONCACAF!=NULL && CONMEBOL!=NULL && UEFA!=NULL && OFC!=NULL){
		if(utn_pedirInt(&confederacion,"\nCONFEDERACION?: \n1.AFC\n2.CAF\n3.CONCACAF\n4.CONMEBOL\n5.UEFA\n6.OFC\nIngrese una opcion: ",
				"ERROR! Reintente",1,6,3)==0){

			switch(confederacion){
				case 1:
					*AFC +=1;
					break;
				case 2:
					*CAF +=1;
					break;
				case 3:
					*CONCACAF +=1;
					break;
				case 4:
					*CONMEBOL +=1;
					break;
				case 5:
					*UEFA +=1;
					break;
				case 6:
					*OFC +=1;
					break;
			}
			retorno =0;
		}
	}

	return retorno;
}
