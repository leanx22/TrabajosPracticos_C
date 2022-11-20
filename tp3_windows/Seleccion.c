#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#include "Jugador.h"
#include "utn.h"


Seleccion* selec_new()
{
	return (Seleccion*)malloc(sizeof(Seleccion));
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* aux = NULL;

	if(idStr!=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{
		aux=selec_new();
		if(aux!=NULL)
		{
			aux->id = atoi(idStr);
			strcpy(aux->pais,paisStr);
			strcpy(aux->confederacion,confederacionStr);
			aux->convocados = atoi(convocadosStr);
			//Queria usar setters pero no estan declarados en seleccion.h ???
		}
	}

	return aux;
}

//void selec_delete();

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;
	if(this!=NULL && pais!=NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}

	return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;
	if(this!=NULL && confederacion!=NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno =0;
	}

	return retorno;
}

//int selec_getIsEmpty(Seleccion* this,int* isEmpty);

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;
	if(this!=NULL)
	{
		this->convocados=convocados;
		retorno = 0;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;
	if(this!=NULL && convocados!=NULL)
	{
		*convocados=this->convocados;
		retorno = 0;
	}

	return retorno;
}


int listarSelecciones(LinkedList* this,int cls)
{
	int retorno = -1;
	int tam;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	Seleccion* aux = NULL;

	if(this!=NULL)
	{
		if(cls==1){
			system("CLS");
		}
		tam = ll_len(this);
		printf("\n| ID |        PAIS       |  CONFEDERACION  | CONVOCADOS |");
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(this,i);
			selec_getId(aux,&id);
			selec_getPais(aux,pais);
			selec_getConfederacion(aux,confederacion);
			selec_getConvocados(aux,&convocados);

			printf("\n|%4d|%-19s|%-17s|%12d|",id,pais,confederacion,convocados);

		}
		retorno = 0;
	}

	return retorno;
}

int obtenerSeleccionxID(LinkedList* this,int idBusqueda,char* respuesta)
{
	int retorno = -1;
	int tam;
	int id;
	char pais[30];
	Seleccion* aux=NULL;

	if(this!=NULL && respuesta!=NULL)
	{
		tam = ll_len(this);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(this,i);
			selec_getId(aux,&id);
			if(id == idBusqueda)
			{
				selec_getPais(aux,pais);
				strcpy(respuesta,pais);
				retorno =0;
				break;
			}else if(idBusqueda == 0){
				strcpy(respuesta,"No convocado");
				retorno = 0;
				break;
			}

		}
	}

	return retorno;
}

int convocarJugadorAseleccion(LinkedList* listaSeleccion,Jugador* jugador)
{
	int retorno = -1;
	int idSeleccion;
	int bufferId;
	int convocados;

	Seleccion* aux = NULL;
	int tam;


	if(listaSeleccion!=NULL && jugador!=NULL)
	{
		if(utn_pedirInt(&idSeleccion,"\n>Ingrese id de la seleccion a la que agregar al jugador: ",
				"\n[!]Error, reintente.",1,32,3)==0)
		{
			tam = ll_len(listaSeleccion);
			for(int i=0;i<tam;i++)
			{
				aux=ll_get(listaSeleccion,i);
				selec_getId(aux,&bufferId);
				selec_getConvocados(aux,&convocados);
				if(idSeleccion==bufferId)
				{
					if(convocados<22)
					{
						convocados+=1;
						selec_setConvocados(aux,convocados);
						jug_setIdSeleccion(jugador,idSeleccion);
						retorno=0;
					}else{
						printf("\nSeleccion llena!");
					}
				}
			}
		}
	}

	return retorno;
}

int obtenerIndiceSeleccion(LinkedList* listaSeleccion,int id)
{
	int retorno = -1;
	int tam;
	Seleccion* aux=NULL;
	int idSeleccion;

	if(listaSeleccion!=NULL && id>0)
	{
		tam=ll_len(listaSeleccion);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(listaSeleccion,i);
			selec_getId(aux,&idSeleccion);
			if(idSeleccion==id)
			{
				retorno=i;
				break;
			}
		}
	}
		return retorno;
}


int selec_ordenarPorConfederacion(void* this,void* this2)
{
	int retorno = 0;
	Seleccion* s1; //s de seleccion
	Seleccion* s2;

	char confederacion[30];
	char confederacion2[30];

	s1=(Seleccion*)this;
	s2=(Seleccion*)this2;

	selec_getConfederacion(s1,confederacion);
	selec_getConfederacion(s2,confederacion2);

	if(this!=NULL && this2!=NULL)
	{
		if(strcmp(confederacion,confederacion2)>0)
		{
			retorno = 1;
		}else{
			retorno = -1;
		}
	}
	return retorno;
}
