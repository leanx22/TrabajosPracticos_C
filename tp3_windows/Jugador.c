#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "utn.h"
#include "Seleccion.h"

Jugador* jug_new()
{
	return (Jugador*)malloc(sizeof(Jugador));
}

Jugador* jug_newParametros(int id,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* aux = NULL;
	aux = jug_new();
	if(aux!=NULL)
	{
		jug_setId(aux,id);
		jug_setNombreCompleto(aux,nombreCompletoStr);
		jug_setEdad(aux,atoi(edadStr));
		jug_setPosicion(aux,posicionStr);
		jug_setNacionalidad(aux,nacionalidadStr);
		jug_setIdSeleccion(aux,atoi(idSeleccionStr));
	}
	return aux;
}

int hardcodearNacionalidades(eNacionalidades lista[],int tam)
{
	int retorno = -1;

	if(lista!=NULL && tam>0)
	{
		lista[0].id = 1;
		strcpy(lista[0].descripcion,"saudita");

		lista[1].id = 2;
		strcpy(lista[1].descripcion,"australiano");

		lista[2].id = 3;
		strcpy(lista[2].descripcion,"coreano");

		lista[3].id = 4;
		strcpy(lista[3].descripcion,"irani");

		lista[4].id = 5;
		strcpy(lista[4].descripcion,"japones");

		lista[5].id = 6;
		strcpy(lista[5].descripcion,"qatari");

		lista[6].id = 7;
		strcpy(lista[6].descripcion,"camerunes");

		lista[7].id = 8;
		strcpy(lista[7].descripcion,"ghanes");

		lista[8].id = 9;
		strcpy(lista[8].descripcion,"marroqui");

		lista[9].id = 10;
		strcpy(lista[9].descripcion,"senegales");

		lista[10].id = 11;
		strcpy(lista[10].descripcion,"tunecino");

		lista[11].id = 12;
		strcpy(lista[11].descripcion,"canadiense");

		lista[12].id = 13;
		strcpy(lista[12].descripcion,"costarricense");

		lista[13].id = 14;
		strcpy(lista[13].descripcion,"estadounidense");

		lista[14].id = 15;
		strcpy(lista[14].descripcion,"mexicano");

		lista[15].id = 16;
		strcpy(lista[15].descripcion,"argentino");

		lista[16].id = 17;
		strcpy(lista[16].descripcion,"brasilero");

		lista[17].id = 18;
		strcpy(lista[17].descripcion,"ecuatoriano");

		lista[18].id = 19;
		strcpy(lista[18].descripcion,"uruguayo");

		lista[19].id = 20;
		strcpy(lista[19].descripcion,"aleman");

		lista[20].id = 21;
		strcpy(lista[20].descripcion,"belga");

		lista[21].id = 22;
		strcpy(lista[21].descripcion,"croata");

		lista[22].id = 23;
		strcpy(lista[22].descripcion,"danes");

		lista[23].id = 24;
		strcpy(lista[23].descripcion,"espanol");

		lista[24].id = 25;
		strcpy(lista[24].descripcion,"frances");

		lista[25].id = 26;
		strcpy(lista[25].descripcion,"gales");

		lista[26].id = 27;
		strcpy(lista[26].descripcion,"holandes");

		lista[27].id = 28;
		strcpy(lista[27].descripcion,"ingles");

		lista[28].id = 29;
		strcpy(lista[28].descripcion,"polaco");

		lista[29].id = 30;
		strcpy(lista[29].descripcion,"portugues");

		lista[30].id = 31;
		strcpy(lista[30].descripcion,"serbio");

		lista[31].id = 32;
		strcpy(lista[31].descripcion,"suizo");

		retorno = 0;
	}
	return retorno;
}

int imprimirNacionalidades(eNacionalidades lista[],int tam,int cls)
{
	int retorno = -1;

	if(lista!=NULL && tam>0)
	{
		if(cls==1){
			system("CLS");
		}

		printf("\n|ID|   NACIONALIDADES   |");
		for(int i=0;i<tam;i++)
		{
			printf("\n|%2d|%-20s|",lista[i].id,lista[i].descripcion);
			printf("\n-------------------------");
		}
		retorno = 0;
	}

	return retorno;
}

int imprimirPosiciones(ePosicion listaPos[],int tamPos,int cls)
{
	int retorno = -1;

	if(listaPos!=NULL && tamPos>0)
	{
		if(cls == 1){
			printf("\n");
			system("CLS");
		}

		printf("-----POSICIONES DISPONIBLES-----");
		printf("\n|ID|      POSICION      |");
		for(int i=0;i<tamPos;i++)
		{
			printf("\n|%-2d|%-20s|",listaPos[i].id,listaPos[i].descripcion);
		}
		retorno = 0;
	}

	return retorno;
}

int obtenerPosicionxID(ePosicion lista[],int tam,int id, char* respuesta)
{
	int retorno = -1;

	if(respuesta!=NULL && lista!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].id==id)
			{
				strcpy(respuesta,lista[i].descripcion);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int obtenerNacionalidad(eNacionalidades listaN[],int tam,int id, char* respuesta)
{
	int retorno = -1;
	if(listaN!=NULL && tam>0 && respuesta!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(listaN[i].id==id)
			{
				strcpy(respuesta,listaN[i].descripcion);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int editarJugador(Jugador* jugador,ePosicion listaPos[],eNacionalidades listaNacionalidades[],
		int tamPos,int tamNacionalidades)
{
	int retorno = -1;
	int opcion;
	int continuar = 1;
	char nombre[100];
	int edad;
	int idPosicion;
	char posicion[30];
	char nacionalidad[30];
	int idNacionalidad;

	if(jugador!=NULL)
	{
		do{
			system("CLS");
			jug_getNombreCompleto(jugador,nombre);
			jug_getEdad(jugador,&edad);
			jug_getPosicion(jugador,posicion);
			jug_getNacionalidad(jugador,nacionalidad);
			printf("EDICION DE %s.\n"
					"\n1.Editar nombre [%s]"
					"\n2.Editar edad [%d]"
					"\n3.Editar posicion [%s]"
					"\n4.Editar nacionalidad [%s]"
					"\n5.Volver",nombre,nombre,edad,posicion,nacionalidad);
			if(utn_pedirInt(&opcion,"\n>Ingrese una opcion: ","\n[!]Error, reingrese.",1,5,3)==0)
			{
				switch(opcion)
				{
				case 1:
					if(utn_getStr(nombre,"\n>Ingrese el nuevo nombre: ","\n[!]Error, reintente.",100,3)==0 &&
						jug_setNombreCompleto(jugador,nombre)==0)
					{
						printf("\nCambio realizado.\n");
					}else{
						printf("\nOcurrio un error al actuializar los datos :(\n");
					}system("PAUSE");
					break;
				case 2:
					if(utn_pedirInt(&edad,"\nIngrese la nueva edad[17-99]: ","\n[!]Error, reintente.",17,99,3)==0 &&
						jug_setEdad(jugador,edad)==0)
					{
						printf("\nCambio realizado.\n");
					}else{
						printf("\nOcurrio un error al actualizar los datos :(\n");
					}system("PAUSE");
					break;
				case 3:
					imprimirPosiciones(listaPos,tamPos,1);
					if(utn_pedirInt(&idPosicion,"\n>Ingrese el ID de posicion: ","\n[!]Error, reintente.",1,14,3)==0 &&
						obtenerPosicionxID(listaPos,tamPos,idPosicion,posicion)==0 &&
						jug_setPosicion(jugador,posicion)==0)
					{
						printf("\nCambio Realizado.\n");
					}else{
						printf("\nOcurrio un error al actualizar los datos :(\n");
					}system("PAUSE");
					break;
				case 4:
					imprimirNacionalidades(listaNacionalidades,tamNacionalidades,1);
					if(utn_pedirInt(&idNacionalidad,"\n>Ingrese el ID de Nacionalidad: ","\n[!]Error, reintente.",1,31,3)==0 &&
						obtenerNacionalidad(listaNacionalidades,tamNacionalidades,idNacionalidad,nacionalidad)==0 &&
						jug_setNacionalidad(jugador,nacionalidad)==0)
					{
						printf("\nCambio Realizado.\n");
					}else{
						printf("\nOcurrio un error al actualizar los datos :(\n");
					}system("PAUSE");
					break;
				case 5:
					continuar = 0;
					break;
				}
				retorno = 0;
			}
		}while(continuar == 1);
	}

	return retorno;
}

int listarJugadores(LinkedList* lista,LinkedList* listaSelecciones,int cls)
{
	int retorno = -1;
	int tam;

	int id;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	char seleccion[30];

	Jugador* aux = NULL;


	if(lista!=NULL)
	{
		if(cls==1){
			system("CLS");
		}
		printf("\n| ID |     NOMBRE COMPLETO     | EDAD |       POSICION       |  NACIONALIDAD  | SELECCION  |");
		printf("\n-------------------------------------------------------------------------------------------");
		tam = ll_len(lista);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(lista,i);
			jug_getId(aux,&id);
			jug_getNombreCompleto(aux,nombre);
			jug_getEdad(aux,&edad);
			jug_getPosicion(aux,posicion);
			jug_getNacionalidad(aux,nacionalidad);
			jug_getIdSeleccion(aux,&idSeleccion);
			obtenerSeleccionxID(listaSelecciones,idSeleccion,seleccion);
			printf("\n|%4d|%-25s|%6d|%-22s|%-16s|%-11s|",id,nombre,edad,posicion,nacionalidad,seleccion);
		}
		retorno = 0;
	}

	return retorno;
}

int listarJugadoresConvocados(LinkedList* lista,LinkedList* listaSelecciones,int cls)
{
	int retorno = -1;
	int tam;

	int id;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	char seleccion[30];
	int contador=0;
	Jugador* aux = NULL;

	if(lista!=NULL)
	{
		if(cls==1){
			system("CLS");
		}
		printf("\n| ID |     NOMBRE COMPLETO     | EDAD |       POSICION       |  NACIONALIDAD  | SELECCION  |");
		printf("\n-------------------------------------------------------------------------------------------");
		tam = ll_len(lista);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(lista,i);
			jug_getIdSeleccion(aux,&idSeleccion);
			if(idSeleccion!=0)
			{

				jug_getId(aux,&id);
				jug_getNombreCompleto(aux,nombre);
				jug_getEdad(aux,&edad);
				jug_getPosicion(aux,posicion);
				jug_getNacionalidad(aux,nacionalidad);
				obtenerSeleccionxID(listaSelecciones,idSeleccion,seleccion);
				printf("\n|%4d|%-25s|%6d|%-22s|%-16s|%-11s|",id,nombre,edad,posicion,nacionalidad,seleccion);
				contador++;
			}
		}
		if(contador==0)
		{
			system("CLS");
			printf("\n->Aun no hay jugadores convocados!");
		}

		retorno = 0;
	}

	return retorno;
}

int bajaJugador(LinkedList* lista, int idAeliminar,LinkedList* listaSeleccion)
{
	int retorno = -1;
	int tam;
	Jugador* aux = NULL;
	Seleccion* auxS=NULL;
	int bufId;
	char nombre[100];
	int confirmar;
	int idSeleccion;
	int convocados;

	if(lista!=NULL)
	{
		tam=ll_len(lista);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(lista,i);
			jug_getId(aux,&bufId);
			if(bufId==idAeliminar)
			{
				jug_getNombreCompleto(aux,nombre);
				printf("\nSe va a eliminar a %s",nombre);
				if(utn_pedirInt(&confirmar,"Ingrese (1)Para CONFIRMAR o (2)Para CANCELAR: ",
					"\n[!]No es una opcion valida, reintente.",1,2,3)==0 && confirmar == 1)
				{
					jug_getIdSeleccion(aux,&idSeleccion);
					auxS=ll_get(listaSeleccion,obtenerIndiceSeleccion(listaSeleccion,idSeleccion));
					selec_getConvocados(auxS,&convocados);
					convocados--;
					selec_setConvocados(auxS,convocados);
					retorno = ll_remove(lista,i);
				}
				break;
			}
		}
	}

	return retorno;
}


Jugador* convocarJugador(LinkedList*listaJugadores)
{
	Jugador* retorno = NULL;
	int idAconvocar;
	int buffer;
	int idSeleccion;

	Jugador* aux = NULL;
	int tam;

	if(listaJugadores!=NULL &&
		utn_pedirInt(&idAconvocar,"\nIngrese ID a convocar: ","[!]Error, reintente.",1,999,3)==0)
	{
		tam = ll_len(listaJugadores);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(listaJugadores,i);
			jug_getId(aux,&buffer);
			jug_getIdSeleccion(aux,&idSeleccion);
			if(buffer==idAconvocar)
			{
				if(idSeleccion==0)
				{
					retorno = aux;
					break;
				}else{
					printf("\nEl jugador esta convocado en otra seleccion!");
					break;
				}
			}
		}
	}

	return retorno;
}

int quitarJugadorDeSeleccion(LinkedList*listaJugadores,LinkedList* listaSeleccion)
{
	int retorno = -1;

	int idJugador;
	int indiceJugador;
	int idSeleccion;
	int indiceSeleccion;
	Jugador* auxJugador=NULL;
	Seleccion* auxSeleccion=NULL;
	int convocados;

	if(listaJugadores!=NULL && listaSeleccion!=NULL &&
		utn_pedirInt(&idJugador,"\n>Ingrese id del jugador: ","[!]Error, reintente.",1,999,3)==0)
	{
		indiceJugador = obtenerIndiceJugador(listaJugadores,idJugador);
		if(indiceJugador!=-1)
		{
			auxJugador=ll_get(listaJugadores,indiceJugador);
			jug_getIdSeleccion(auxJugador,&idSeleccion);
			if(idSeleccion!=0)
			{
				indiceSeleccion=obtenerIndiceSeleccion(listaSeleccion,idSeleccion);
				if(indiceSeleccion!=-1)
				{
					auxSeleccion=ll_get(listaSeleccion,indiceSeleccion);
					selec_getConvocados(auxSeleccion,&convocados);
					convocados-=1;
					selec_setConvocados(auxSeleccion,convocados);
					jug_setIdSeleccion(auxJugador,0);
					retorno = 0;
				}
			}else{
				printf("\nEste jugador no esta convocado aun.");
			}
		}

	}

	return retorno;
}

int obtenerIndiceJugador(LinkedList* listaJugadores,int id)
{
	int retorno = -1;
	int tam;
	Jugador* aux=NULL;
	int idJugador;

	if(listaJugadores!=NULL && id>0)
	{
		tam=ll_len(listaJugadores);
		for(int i=0;i<tam;i++)
		{
			aux=ll_get(listaJugadores,i);
			jug_getId(aux,&idJugador);
			if(idJugador==id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int jug_ordenarPorNacionalidad(void* this, void* this2)
{
	int retorno = 0;
	Jugador* j1;
	Jugador* j2;

	char nacionalidad[30];
	char nacionalidad2[30];

	j1=(Jugador*)this;
	j2=(Jugador*)this2;

	jug_getNacionalidad(j1,nacionalidad);
	jug_getNacionalidad(j2,nacionalidad2);

	if(this!=NULL && this2!=NULL)
	{
		if(strcmp(nacionalidad,nacionalidad2)>0)
		{
			retorno = 1;
		}else{
			retorno = -1;
		}
	}
	return retorno;
}

int jug_ordenarPorNombre(void* this, void* this2)
{
	int retorno = 0;
	Jugador* j1;
	Jugador* j2;

	char nombre[30];
	char nombre2[30];

	j1=(Jugador*)this;
	j2=(Jugador*)this2;

	jug_getNombreCompleto(j1,nombre);
	jug_getNombreCompleto(j2,nombre2);

	if(this!=NULL && this2!=NULL)
	{
		if(strcmp(nombre,nombre2)>0)
		{
			retorno = 1;
		}else{
			retorno = -1;
		}
	}
	return retorno;
}

int jug_ordenarPorEdad(void* this, void* this2)
{
	int retorno = 0;
	Jugador* j1;
	Jugador* j2;

	int edad;
	int edad2;

	j1=(Jugador*)this;
	j2=(Jugador*)this2;

	jug_getEdad(j1,&edad);
	jug_getEdad(j2,&edad2);

	if(this!=NULL && this2!=NULL)
	{
		if(edad>edad2)
		{
			retorno = 1;
		}else{
			retorno = -1;
		}
	}
	return retorno;
}


//-------------------------------------Setters y getters----------------------------------------------------||

int jug_setId(Jugador* this,int id)
{
	int retorno = -1;

	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno = 0;
	}
	else
	{
		printf("\nNo se pudo setear el ID!\n");
		system("PAUSE");
	}

	return retorno;
}
int jug_getId(Jugador* this,int* id)

{
	int retorno = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	else
	{
		printf("\nNo se pudo obtener el ID!\n");
		system("PAUSE");
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this!=NULL && nombreCompleto!=NULL && utn_esNombre(nombreCompleto,100)==0)
	{
		strcpy(this->nombreCompleto,nombreCompleto);
		retorno = 0;
	}
	else{
		printf("\nHubo un error al intentar setear el nombre!\n");
		system("PAUSE");
	}

	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;
	if(this!=NULL && nombreCompleto!=NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
	}
	else
	{
		printf("\nNo se pudo obtener el nombre!\n");
		system("PAUSE");
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;
	if(this!=NULL && posicion!=NULL)
	{
		strcpy(this->posicion,posicion);
		retorno = 0;
	}


	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion!=NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 0;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this!=NULL && nacionalidad!=NULL)
	{
		strcpy(this->nacionalidad,nacionalidad);
		retorno = 0;
	}

	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this!=NULL && nacionalidad!=NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;
	if(this!=NULL && edad>16)
	{
		this->edad = edad;
		retorno = 0;
	}else{
		printf("\nHubo un error en set_edad! (menor de edad?)\n");
		system("PAUSA");
	}

	return retorno;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this!=NULL && edad!=NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

	if(this!=NULL)
	{
		this->idSeleccion = idSeleccion;
	}

	return retorno;
}
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;
	if(this!=NULL && idSeleccion!=NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}

	return retorno;
}



