/*
 * cargaDatos.c
 *
 *  Created on: 12 sep. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include "cargaDatos.h"
#include "utn.h"

int costosMantenimiento(float* hospedaje,float* comida,float* transporte){

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
