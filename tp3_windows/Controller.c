#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo!=NULL && parser_JugadorFromText(pArchivo,pArrayListJugador)==0)
		{
			retorno = 0;
		}else{
			printf("\nError en: [JUGADORES]\n");
		}
	}

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador,eNacionalidades listaNacionalidades[],
	int tamNacionalidades,int* idJugadores,ePosicion listaPosi[],int tamPosi)
{
   int retorno = -1;

   char nombre[50];
   char edad[3];
   int idPosicion;
   char posicion[50];
   int idNacionalidad;
   char nacionalidad[50];

   if(pArrayListJugador!=NULL)
   {
	   if(utn_getStr(nombre,"\n>Ingrese el nombre del Jugador: ","\n[!]Error, reintente.",50,3)==0 &&
			//utn_pedirInt(&edad,"\n>Ingrese la edad del Jugador: ","\n[!]Error, reintente.",17,99,3)==0 &&
			getIntComoStr(edad,"\nIngrese la edad del jugador: ","\n[!]Error, reintente.",17,99,3)==0 &&
			imprimirPosiciones(listaPosi,tamPosi,1)==0 &&
			utn_pedirInt(&idPosicion,"\n>Ingrese id de la posicion: ","\n[!]Error, reingrese.",1,14,3)==0 &&
			imprimirNacionalidades(listaNacionalidades,tamNacionalidades,1)==0 &&
			utn_pedirInt(&idNacionalidad,"\n>Ingrese ID de nacionalidad: ","\n[!]Error, reintente.",1,32,3)==0)
	   {
		   obtenerNacionalidad(listaNacionalidades,tamNacionalidades,idNacionalidad,nacionalidad);
		   obtenerPosicionxID(listaPosi,tamPosi,idPosicion,posicion);
		   if(ll_add(pArrayListJugador,jug_newParametros(*idJugadores,nombre,edad,posicion,nacionalidad,"0"))==0)
		   {
			   *idJugadores+=1;
			   retorno = 0;
		   }

	   }
   }

	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador,ePosicion listaPos[],
		eNacionalidades listaNacionalidades[],int tamPos, int tamNacionalidades)
{
    int retorno = -1;
    int idAmodificar;
    int tam;
    int idActual;

    Jugador* aux = NULL;

    if(pArrayListJugador!=NULL)
    {
    	tam = ll_len(pArrayListJugador);
    	if(utn_pedirInt(&idAmodificar,"\n>Ingrese el id del jugador: ","\n[!]Error, reintente.",1,999,3)==0)
    	{
    		for(int i=0;i<tam;i++)
    		{
    			aux = ll_get(pArrayListJugador,i);
    			jug_getId(aux,&idActual);
    			if(idActual==idAmodificar)
    			{
    				retorno = editarJugador(aux,listaPos,listaNacionalidades,tamPos,tamNacionalidades);
    				break;
    			}
    		}
    	}
    }

	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* selecciones)
{
	int retorno = -1;
	int idAeliminar;

	if(pArrayListJugador!=NULL)
	{
		listarJugadores(pArrayListJugador,selecciones,1);
		if(utn_pedirInt(&idAeliminar,"\n>Ingrese el ID del jugador que desea eliminar: ",
				"\n[!]Error, reintente.",1,999,3)==0 &&
				bajaJugador(pArrayListJugador,idAeliminar)==0)
		{
			retorno = 0;
		}

	}

    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* selecciones)
{
	int retorno = -1;
	if(pArrayListJugador!=NULL)
	{
		retorno = listarJugadores(pArrayListJugador,selecciones,1);
	}
	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;

	FILE* pArchivo = NULL;


	if(pArrayListSeleccion!=NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL && parser_SeleccionFromText(pArchivo,pArrayListSeleccion)==0)
		{
			retorno = 0;
		}
		else{
			printf("\nError en: [SELECCIONES]\n");
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	if(pArrayListSeleccion!=NULL)
	{
		listarSelecciones(pArrayListSeleccion,1);
		printf("\n");
		system("PAUSE");
	}

    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}

//-------------------------PROPIAS-----------------------------------------------------

int iniciarID(char* path)
{
	int retorno = -1;
	int idInicial = 371;

	FILE* archivo = NULL;


	archivo = fopen(path,"r");
	if(archivo==NULL)
	{
		system("CLS");
		printf("El archivo de ID no existe, se va a crear uno nuevo.\n");
		system("PAUSE");
		archivo = fopen(path,"w");
		if(archivo!=NULL)
		{
			fprintf(archivo,"%d",idInicial);
			retorno = idInicial;
		}else{
			printf("\nOcurrio un error al intentar crear el archivo de ID.\n");
			system("PAUSE");
		}
	}else
	{
		fscanf(archivo,"%d",&retorno);
	}

	if(fclose(archivo)!=0)
	{
		printf("\nATENCION: el archivo de ID no se pudo cerrar de manera correcta, esto puede generar problemas!\n");
		system("PAUSE");
	}
	return retorno;
}

int actualizarArchivoID(char* path,int newId)
{
	int retorno = -1;
	FILE* archivo = NULL;

	archivo = fopen(path,"w");
	if(archivo!=NULL)
	{
		fprintf(archivo,"%d",newId);
		retorno = 0;
	}else{
		printf("\nHubo un error al modificar el archivo de ID\n");
		system("PAUSE");
	}

	if(fclose(archivo)!=0)
	{
		printf("\nATENCION: no se pudo cerrar el archivo de ID!\n");
		system("PAUSE");
	}

	return retorno;
}

int menuListados(LinkedList* listaJugadores,LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;
	int continuar = 1;

	do{
		system("CLS");
		printf("Que desea mostrar?:"
				"\n1.Todos los jugadores."
				"\n2.Todas las selecciones."
				"\n3.Solo jugadores convocados."
				"\n4.Salir.");
		if(utn_pedirInt(&opcion,"\n>Ingrese opcion: ","\n[!]Error, reingrese.",1,4,3)==0)
		{
			switch(opcion)
			{
			case 1:
				controller_listarJugadores(listaJugadores,listaSelecciones);
				printf("\n");
				system("PAUSE");
				break;
			case 2:
				controller_listarSelecciones(listaSelecciones);
				break;
			case 3:
				listarJugadoresConvocados(listaJugadores,listaSelecciones,1);
				printf("\n");
				system("PAUSE");
				break;
			case 4:
				continuar = 0;
				break;
			}
			retorno = 0;
		}

	}while(continuar == 1);


	return retorno;
}

int convocarJugadores(LinkedList* listaJugadores,LinkedList* listaSelecciones)
{
	int retorno = -1;
	Jugador* jugadorAux=NULL;


	if(listaJugadores!=NULL && listaSelecciones!=NULL)
	{
		controller_listarJugadores(listaJugadores,listaSelecciones);
		printf("\n");
		jugadorAux=convocarJugador(listaJugadores);
		if(jugadorAux!=NULL)
		{
			listarSelecciones(listaSelecciones,1);
			if(convocarJugadorAseleccion(listaSelecciones,jugadorAux)==0)
			{
				printf("\nJugador convocado correctamente!\n");
				retorno=0;
			}else{
				printf("\nOcurrio un error al intentar convocar!\n");
			}system("PAUSE");
		}

	}

	return retorno;
}




