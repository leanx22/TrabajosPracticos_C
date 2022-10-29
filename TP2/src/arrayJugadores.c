/*
 * arrayJugadores.c
 *
 *  Created on: 18 oct. 2022
 *      Author: leandro
 */
#include "arrayJugadores.h"
#include "confederaciones.h"
#include "utn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int inicializarArray(eJugador listaJugadores[], int tam)
{
	int retorno = -1;

	if(listaJugadores != NULL && tam > 0)
	{
		for(int i = 0;i<tam;i++)
		{
			listaJugadores[i].isEmpty = 1;
		}

		retorno = 0;
	}


	return retorno;
}

int hardcodear(eJugador listaJugadores[],int indice,int*id,char*nombre,
		char*posi,short camiseta,int idConfe, float salario, short aniosContrato,int*altas,float*salarios)
{
	int retorno = -1;
	if(listaJugadores!=NULL)
	{
		listaJugadores[indice].id = *id;
		strcpy(listaJugadores[indice].nombre,nombre);
		strcpy(listaJugadores[indice].posicion,posi);
		listaJugadores[indice].numCamiseta = camiseta;
		listaJugadores[indice].idConfederacion = idConfe;
		listaJugadores[indice].salario = salario;
		listaJugadores[indice].anioContrato = aniosContrato;

		listaJugadores[indice].isEmpty = 0;
		*id +=1;
		*altas+=1;
		*salarios+=salario;

		retorno=0;
	}


	return retorno;
}

int buscarLibre(eJugador listaJugadores[], int tam)
{
	int retorno = -1;

	if(listaJugadores != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if(listaJugadores[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int cargaJugador(eJugador listaJugadores[],eConfederacion listaConfe[],int tam,int tamConf,int*ids,int*altas,float* aSueldos)
{
	int retorno = -1;
	int indiceLibre;

	char nombre[50];
	char posi[50];

	int idPosi;
	int idConfe;

	int camiseta;
	int aniosContrato;//short
	float salario;


	if(listaJugadores != NULL && tam > 0 && ids!=NULL)
	{
		system("CLS");
		printf("\n>Carga de jugador nuevo<");
		indiceLibre = buscarLibre(listaJugadores,tam);
		if(indiceLibre != -1 &&
			utn_getStr(nombre,"\n>Ingrese nombre del jugador: ","\n[!]Error, reintente.",50,3)==0 &&
			utn_pedirInt(&idPosi,"\n----POSICION----\n1.Arquero\n2.Defensor\n3.MedioCampista\n4.Delantero\n>Ingrese la posicion del jugador: ",
			"\n[!]Error, reingrese.",1,4,3)==0 &&
			obtenerPosicion(posi,idPosi)==0 &&
			utn_pedirInt(&camiseta,"\n>Ingrese numero de camiseta: ","\n[!]Error, fuera de rango(1-99).",1,99,3)==0 &&
			utn_pedirFloat(&salario,"\n>Ingrese el salario: ","\n[!]Error!, reintente.",1,9999999,3)==0 &&
			utn_pedirInt(&aniosContrato,"\n>Ingrese anios de contrato: ","\n[!]Error, fuera de rango(1-99).",1,99,3)==0 &&
			imprimirConfederaciones(listaConfe,tamConf,0)==0 &&
			utn_pedirInt(&idConfe,"\n>Ingrese Id de la confederacion:","\n[!]Error, reintente",1000,1005,3)==0)
		{

			strcpy(listaJugadores[indiceLibre].nombre,nombre);
			strcpy(listaJugadores[indiceLibre].posicion,posi);
			listaJugadores[indiceLibre].numCamiseta = (short)camiseta;
			listaJugadores[indiceLibre].salario = salario;
			listaJugadores[indiceLibre].anioContrato = (short)aniosContrato;
			listaJugadores[indiceLibre].idConfederacion=idConfe;
			listaJugadores[indiceLibre].id = *ids;
			listaJugadores[indiceLibre].isEmpty = 0;
			*aSueldos+=salario;
			*altas+=1;
			*ids += 1;
			retorno = 0;
		}
		else
		{
			printf("\n[!]Error, demasiados reintentos o no hay mas espacios libres!\n");
			system("PAUSE");
		}
	}

	return retorno;
}

int obtenerPosicion(char*respuesta, int id)
{
	int retorno=-1;

	if(respuesta!=NULL && id>0 && id<=4)
	{
		switch(id)
		{
		case 1:
			strcpy(respuesta,"Arquero");
			break;
		case 2:
			strcpy(respuesta,"Defensor");
			break;
		case 3:
			strcpy(respuesta,"MedioCapista");
			break;
		case 4:
			strcpy(respuesta,"Delantero");
			break;
		}
		retorno = 0;
	}
	return retorno;
}

int listarJugadores(eJugador listaJugadores[],eConfederacion listaConfederacion[], int tamJugadores, int tamConfe,int cls)
{
	int retorno = -1;
	char confederacion[50];

	if(listaJugadores!=NULL && tamJugadores>0)
	{
		if(cls == 1){
			system("CLS");
		}
		printf("\n");
		printf("\n----------------------------------------------------------------------------------------------------");
		printf("\n|  ID  |       NOMBRE       |   POSICION   | CAMISETA |  SALARIO  | CONFEDERACION | ANIOS CONTRATO |");
		printf("\n----------------------------------------------------------------------------------------------------");

		for(int i=0;i<tamJugadores;i++)
		{
			if(listaJugadores[i].isEmpty==0)
			{
				obtenerConfederacion(listaConfederacion,tamConfe,listaJugadores[i].idConfederacion,confederacion);

				printf("\n|%6d|%-20s|%14s|%10d|%11.2f|%15s|%16d|",
				listaJugadores[i].id,listaJugadores[i].nombre,listaJugadores[i].posicion,listaJugadores[i].numCamiseta,
				listaJugadores[i].salario,confederacion,listaJugadores[i].anioContrato);
				printf("\n----------------------------------------------------------------------------------------------------");
			}
		}
		retorno =0;
	}

	return retorno;
}

int ordenarxID(eJugador listaJugadores[],int tamJugadores)
{
	int retorno = -1;
	eJugador aux;

	if(listaJugadores!=NULL && tamJugadores>0)
	{
		printf("\nEstoy ordenando! [por ID]\n");
		for(int i=0;i<tamJugadores-1;i++)
		{
			for(int j=i+1;j<tamJugadores;j++)
			{
				if(listaJugadores[i].id>listaJugadores[j].id)
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

int obtenerIndicexID(eJugador listaJugadores[], int tamJugadores,int idBusqueda)
{
	int retorno = -1;
	if(listaJugadores!=NULL && tamJugadores>0 && idBusqueda>=100)
	{
		for(int i=0;i<tamJugadores;i++)
		{
			if(listaJugadores[i].id == idBusqueda && listaJugadores[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int bajaJugador(eJugador listaJugadores[],int tamJugadores,int*altas,float*salarios)
{
	int retorno = -1;
	int idAbuscar;
	int indiceAeliminar;
	int confirmar = -1;

	if(listaJugadores!=NULL && tamJugadores>0 &&
		utn_pedirInt(&idAbuscar,"\n>Ingrese el ID del jugador que desea ELIMINAR: ","\n[!]Error!, reintente.",100,9999,3)==0)
	{
		indiceAeliminar = obtenerIndicexID(listaJugadores,tamJugadores,idAbuscar);
		if(indiceAeliminar!=-1)
		{
			printf("\n[!]ESTA A PUNTO DE ELIMINAR A: %s",listaJugadores[indiceAeliminar].nombre);

			utn_pedirInt(&confirmar,"\nEsta seguro?\n1.CONFIRMAR.\n2.CANCELAR.\n>","\n[!]Error, reintente.",1,2,999);
			if(confirmar==1)
			{
				listaJugadores[indiceAeliminar].isEmpty=1;
				*altas-=1;
				*salarios-=listaJugadores[indiceAeliminar].salario;
				retorno = 0;
			}
		}

	}

	return retorno;
}

int editarJugador(eJugador listaJugadores[],eConfederacion listaConfe[],int tamJugadores,int tamConfe)
{
	int retorno = -1;
	int continuar = 1;
	int idAbuscar;
	int indiceAeditar;
	int opcion;

	char nombreConfederacion[50];
	int buffCamiseta;
	int buffIdConfe;
	int idPosi;

	if(listaJugadores!=NULL && tamJugadores>0 &&
		utn_pedirInt(&idAbuscar,"\n>Ingrese el id del jugador a EDITAR: ","\n[!]Error, reintente!",100,9999,3)==0)
	{
		indiceAeditar = obtenerIndicexID(listaJugadores,tamJugadores,idAbuscar);
		if(indiceAeditar!=-1)
		{
			do{
				system("CLS");
				obtenerConfederacion(listaConfe,tamConfe,listaJugadores[indiceAeditar].idConfederacion,nombreConfederacion);
				printf("\n++MENU DE EDICION++"
						"\n1.Editar Nombre [%s]"
						"\n2.Editar Posicion [%s]"
						"\n3.Editar numero de camiseta [%d]"
						"\n4.Editar id de confederacion [%d][%s]"
						"\n5.Editar salario [%.2f]"
						"\n6.Editar contrato [%d anios]"
						"\n7.Volver al menu principal",
						listaJugadores[indiceAeditar].nombre,
						listaJugadores[indiceAeditar].posicion,
						listaJugadores[indiceAeditar].numCamiseta,
						listaJugadores[indiceAeditar].idConfederacion,
						nombreConfederacion,
						listaJugadores[indiceAeditar].salario,
						listaJugadores[indiceAeditar].anioContrato);

				if(utn_pedirInt(&opcion,"\n>Ingrese una opcion: ","[!]Error, reintente.",1,7,3)==0)
				{
					switch(opcion)
					{
					case 1:
						if(utn_getStr(listaJugadores[indiceAeditar].nombre,"\n>Ingrese nuevo nombre: ","\n[!]Error reintente.",50,3)==0)
						{
							printf("\n[>]El nombre fue actualizado correctamente!\n");
							system("PAUSE");
						}else{
							printf("\n[!]Ocurrio un error al editar!\n");
							system("PAUSE");
						}
						break;
					case 2:
						if(utn_pedirInt(&idPosi,"\n1.Arquero\n2.Defensor\n3.MedioCampo\n4.Delantero\n>Ingrese nueva posicion: ",
								"\n[!]Error reintente.",1,4,3)==0 &&
							obtenerPosicion(listaJugadores[indiceAeditar].posicion,idPosi)==0)
						{
							printf("\n[>]La posicion fue actualizada correctamente!\n");
							system("PAUSE");
						}else{
							printf("\n[!]Ocurrio un error al editar!\n");
							system("PAUSE");
						}
						break;
					case 3:
						if(utn_pedirInt(&buffCamiseta,"\n>Ingrese el nuevo numero de camiseta: ",
								"\n[!]Error, reingrese.",1,99,3)==0)
						{
							listaJugadores[indiceAeditar].numCamiseta = (short)buffCamiseta;
							printf("\n[>]La camiseta fue actualizada correctamente!\n");
							system("PAUSE");
						}else
						{
							printf("\n[!]Ocurrio un error al editar!\n");
							system("PAUSE");
						}
						break;
					case 4:
						imprimirConfederaciones(listaConfe, tamConfe, 0);
						if(utn_pedirInt(&buffIdConfe,"Ingrese el nuevo ID de confederacion: ","\n[!]Error, reintente.",1000,1005,3)==0)
						{
							listaJugadores[indiceAeditar].idConfederacion = buffIdConfe;
							printf("\n[>]La confederacion se actualizo correctamente!\n");
							system("PAUSE");
						}else{
							printf("\n[!]Ocurrio un error al actualizar!\n");
							system("PAUSE");
						}
						break;
					case 7:
						retorno = 0;
						continuar = 0;
						break;
					}

				}

			}while(continuar==1);
		}
		else
		{
			printf("\n[!]No se encontro al jugador!\n");
			system("PAUSE");
		}
	}


	return retorno;
}











