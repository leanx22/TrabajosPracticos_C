/*
 * confederaciones.c
 *
 *  Created on: 18 oct. 2022
 *      Author: leandro
 */
#include "confederaciones.h"
#include "arrayJugadores.h"
#include "utn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int imprimirConfederaciones(eConfederacion lista[], int tam, int limpiar)
{
	int retorno = -1;

	if(lista != NULL && tam >0)
	{
		if(limpiar == 1)
		{
			system("CLS");
		}
		printf("\n<++CONFEDERACIONES++>");
		printf("\n-----------------------------------------------------");
		printf("\n|   ID   |   NOMBRE   |         REGION         |ANIO|");
		printf("\n-----------------------------------------------------");

		for(int i=0;i<tam;i++)
		{
			//printf("\n-------------------------------");
			printf("\n|%8d|%-12s|%-24s|%4d|",lista[i].idConfe,lista[i].nombre,lista[i].region,lista[i].anioCreacion);
			printf("\n-----------------------------------------------------");
		}
		retorno = 0;
	}

	return retorno;
}

int obtenerConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int id, char*respuesta)
{
	int retorno = -1;

	if(listaConfederaciones!=NULL && respuesta!=NULL && tamConfe>0)
	{
		for(int i=0;i<tamConfe;i++)
		{
			if(listaConfederaciones[i].idConfe == id)
			{
				strcpy(respuesta,listaConfederaciones[i].nombre);
				retorno = 0;
				break;
			}

		}

	}

	return retorno;
}

//ABM

int inicializarConfederaciones(eConfederacion listaConfederaciones[],int tamConfe)
{
	int retorno = -1;
	if(listaConfederaciones!=NULL && tamConfe>0)
	{
		for(int i=0;i<tamConfe;i++){
			listaConfederaciones[i].isEmpty=1;
		}
		retorno = 0;
	}

	return retorno;
}

int buscarConfederacionLibre(eConfederacion listaConfederaciones[],int tamConfe,int*indiceLibre)
{
	int retorno = -1;
	if(listaConfederaciones!=NULL && tamConfe>0 && indiceLibre!=NULL)
	{
		*indiceLibre = -1;
		for(int i=0;i<tamConfe;i++){
			if(listaConfederaciones[i].isEmpty==1)
			{
				*indiceLibre = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int altaConfederacion(eConfederacion listaConfederaciones[],int tamConfe,int* idConfederaciones)
{
	int retorno = -1;

	int indiceLibre;
	char nombre[50];
	char region[50];
	int anioCreacion;

	if(listaConfederaciones!=NULL && tamConfe>0)
	{
		printf("\n");
		system("CLS");
		printf("+++++CARGA DE CONFEDERACION+++++");

		buscarConfederacionLibre(listaConfederaciones,tamConfe,&indiceLibre);
		if(indiceLibre!=-1 &&
			utn_getStr(nombre,"\n>Ingrese el nombre de la confederacion: ","\n[!]Error, reintente!.",50,3)==0 &&
			utn_getStr(region,"\n>Ingrese region de la confederacion: ","\n[!]Error, reintente!.",50,3)==0 &&
			utn_pedirInt(&anioCreacion,"\n>Ingrese el anio de creacion[min:1700 - max:2022]: ","[!]Error, reintente!.",1700,2022,3)==0)
		{
			strcpy(listaConfederaciones[indiceLibre].nombre,nombre);
			strcpy(listaConfederaciones[indiceLibre].region,region);
			listaConfederaciones[indiceLibre].anioCreacion = anioCreacion;
			listaConfederaciones[indiceLibre].idConfe = *idConfederaciones;
			*idConfederaciones+=1;
			listaConfederaciones[indiceLibre].isEmpty=0;
			retorno = 0;
		}

	}

	return retorno;
}

int bajaConfederacion(eConfederacion listaConfederaciones[],int tamConfe)
{
	int retorno = -1;
	int idAbuscar;
	int indiceAeliminar;

	if(listaConfederaciones!=NULL && tamConfe>0)
	{
		system("CLS");
		printf("\n+++++BAJA CONFEDERACION+++++");
		if(imprimirConfederaciones(listaConfederaciones,tamConfe,0)==0 &&
			utn_pedirInt(&idAbuscar,"\n>Ingrese el id a eliminar: ","\n[!]Error, reintente.",100,999,3)==0 &&
			buscarConfederacionxID(listaConfederaciones,tamConfe,idAbuscar,&indiceAeliminar)==0)
		{
			listaConfederaciones[indiceAeliminar].isEmpty=1;
			printf("\nEliminado correctamente!.\n");
			retorno = 0;
		}
		else{
			printf("\nOcurrio un error, o el ID no corresponde a ninguna confederacion.\n");
		}
		system("PAUSE");
	}

	return retorno;
}

int buscarConfederacionxID(eConfederacion lista[],int tamConfe,int id,int* respuesta)
{
	int retorno = -1;

	if(lista!=NULL && tamConfe>0 && id>0)
	{
		for(int i=0;i<tamConfe;i++)
		{
			if(lista[i].idConfe==id)
			{
				*respuesta = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int editarConfederacion(eConfederacion lista[],int tamConfe)
{
	int retorno = -1;

	int continuar =1;
	int opcion;
	int id;
	int indice;
	int bufAnio;

	if(lista!=NULL && tamConfe>0 &&
		imprimirConfederaciones(lista,tamConfe,1)==0 &&
		utn_pedirInt(&id,">\nIngrese ID de confederacion a editar: ","\n[!]Error, reintente.",100,999,3)==0 &&
		buscarConfederacionxID(lista,tamConfe,id,&indice)==0)
	{
		do{
			system("CLS");
			printf("+++MODIFICAR CONFEDERACION+++\n"
					"1.Editar Nombre.[%s]\n"
					"2.Editar Region.[%s]\n"
					"3.Editar anio de creacion.[%d]\n"
					"4.Salir",lista[indice].nombre,lista[indice].region,lista[indice].anioCreacion);

			if(utn_pedirInt(&opcion,"\n>Ingrese su opcion: ","\n[!]Error, reintente.",1,4,3)==0)
			{
				switch(opcion)
				{
				case 1:
					if(utn_getStr(lista[indice].nombre,"\n>Ingrese nuevo nombre: ","\n[!]Error, reintente.",50,3)==0)
					{
						printf("\nCambios realizados!\n");
					}else{
						printf("\nNo se pudo realizar el cambio!\n");
					}
					system("PAUSE");
				break;
				case 2:
					if(utn_getStr(lista[indice].region,"\n>Ingrese nueva region: ","\n[!]Error, reintente.",50,3)==0)
					{
						printf("\nCambios realizados!\n");
					}else{
						printf("\nNo se pudo realizar el cambio!\n");
					}
					system("PAUSE");
				break;
				case 3:
					if(utn_pedirInt(&bufAnio,"\n>Ingrese nuevo anio[1700-2022]: ","\n[!]Error, reintente!",1700,2022,3)==0)
					{
						lista[indice].anioCreacion = bufAnio;
						printf("\nLos cambios se realizaron correctamente!\n");
					}else{
						printf("\n[!]Ocurrio un error al intentar hacer los cambios!\n");
					}
					system("PAUSE");
				break;
				case 4:
					continuar = 0;
					break;
				}
				retorno = 0;
			}
		}while(continuar==1);
	}
	return retorno;
}








