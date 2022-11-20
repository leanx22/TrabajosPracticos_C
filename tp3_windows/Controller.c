#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Controller.h"
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
		ll_clear(pArrayListJugador);
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
				bajaJugador(pArrayListJugador,idAeliminar,selecciones)==0)
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
	int retorno = -1;
	int opcion;
	int continuar=1;

	if(pArrayListJugador!=NULL)
	{
		do{
			system("CLS");
			printf("---ORDENAMIENTO DE JUGADORES---"
					"\n1.Ordenar por nacionalidad."
					"\n2.Ordenar por edad."
					"\n3.ordenar por nombre."
					"\n4.Cancelar.");
			if(utn_pedirInt(&opcion,"\n>Ingrese la opcion: ","\n[!]Error, reintente.",1,4,3)==0)
			{
				switch(opcion)
				{
				case 1:
					ll_sort(pArrayListJugador,jug_ordenarPorNacionalidad,1);
					retorno = 0;
					continuar = 0;
					break;
				case 2:
					ll_sort(pArrayListJugador,jug_ordenarPorEdad,1);
					retorno = 0;
					continuar = 0;
					break;
				case 3:
					ll_sort(pArrayListJugador,jug_ordenarPorNombre,1);
					retorno = 0;
					continuar = 0;
					break;
				case 4:
					continuar=0;
					break;
				}
			}
		}while(continuar==1);

	}

    return retorno;
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
	int retorno = -1;
	int tam;
	FILE* archivo=NULL;
	Jugador* aux = NULL;

	int id;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

	if(pArrayListJugador!=NULL && path!=NULL)
	{
		archivo=fopen(path,"w");
		if(archivo!=NULL)
		{
			tam=ll_len(pArrayListJugador);
			fprintf(archivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion\n");
			for(int i=0;i<tam;i++)
			{
				aux=ll_get(pArrayListJugador,i);
				if(aux!=NULL)
				{
					jug_getId(aux,&id);
					jug_getNombreCompleto(aux,nombre);
					jug_getEdad(aux,&edad);
					jug_getPosicion(aux,posicion);
					jug_getNacionalidad(aux,nacionalidad);
					jug_getIdSeleccion(aux,&idSeleccion);
					fprintf(archivo,"%d,%s,%d,%s,%s,%d\n",id,nombre,edad,posicion,nacionalidad,idSeleccion);
				}
			}
			retorno=0;
		}
	}


    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* listaSeleccion)
{
    int retorno = -1;
    int idConfe;
    char filtroConfederacion[30];
    char bufferConfederacion[30];
    int tamJugadores;
    FILE* archivo=NULL;
    Jugador* auxJug=NULL;
    int idSeleccion;
    Seleccion* auxSelec=NULL;
    int contador=0;

	if(pArrayListJugador!=NULL && listaSeleccion!=NULL &&path!=NULL)
    {
		system("CLS");
		printf("\n-----EXPORTAR JUGADORES EN BINARIO (segun confederacion)-----"
				"\n1.CONMEBOL"
				"\n2.UEFA"
				"\n3.AFC"
				"\n4.CAF"
				"\n5.CONCACAF"
				"\n6.OFC");
		if(utn_pedirInt(&idConfe,"\nSeleccione la confederacion de los jugadores que desea exportar: ","[!]Error,reintente.",1,6,3)==0)
		{
			obtenerConfederacion(idConfe,filtroConfederacion);

			archivo=fopen(path,"wb");
			if(archivo!=NULL)
			{
				tamJugadores=ll_len(pArrayListJugador);
				for(int i=0;i<tamJugadores;i++)
				{
					auxJug=ll_get(pArrayListJugador,i);
					jug_getIdSeleccion(auxJug,&idSeleccion);
					auxSelec=ll_get(listaSeleccion,obtenerIndiceSeleccion(listaSeleccion,idSeleccion));
					selec_getConfederacion(auxSelec,bufferConfederacion);

					if(strcmp(bufferConfederacion,filtroConfederacion)==0 && idSeleccion!=0)
					{
						fwrite(auxJug,sizeof(Jugador),1,archivo);
						contador++;
					}
				}

				if(contador>0)
				{
					retorno=0;
					printf("\nGuardado completo!\n");
				}else{
					printf("\nError, esta confederacion no tiene convocados!.\n");
				}

				if(fclose(archivo)!=0){
					printf("\nNo se pudo cerrar el archivo!.\n");
				}
				system("PAUSE");
			}
		}
    }

	return retorno;
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
		ll_clear(pArrayListSeleccion);
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

/// @brief
///
/// @param pArrayListSeleccion
/// @param pArrayListJugador
/// @return
int controller_editarSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int continuar=1;
	int opcion;
	Jugador* jugadorAux = NULL;

	if(pArrayListSeleccion!=NULL && pArrayListJugador!=NULL)
	{
		do{
			system("CLS");
			printf("EDITAR SELECCIONES"
					"\n1.Convocar Jugadores."
					"\n2.Quitar Jugadores."
					"\n3.Volver");

			if(utn_pedirInt(&opcion,"\nIngrese una opcion: ","\n[!]Error, reintente.",1,3,3)==0)
			{
				switch(opcion)
				{
				case 1:
					controller_listarJugadores(pArrayListJugador,pArrayListSeleccion);
					printf("\n");
					jugadorAux=convocarJugador(pArrayListJugador);
					if(jugadorAux!=NULL)
					{
						listarSelecciones(pArrayListSeleccion,1);
						if(convocarJugadorAseleccion(pArrayListSeleccion,jugadorAux)==0)
						{
							printf("\nJugador convocado correctamente!\n");
							retorno=0;
						}else{
							printf("\nOcurrio un error al intentar convocar!\n");
						}system("PAUSE");
					}
				break;
				case 2:
					listarJugadoresConvocados(pArrayListJugador,pArrayListSeleccion,1);
					if(quitarJugadorDeSeleccion(pArrayListJugador,pArrayListSeleccion)==0)
					{
						printf("\nJugador quitado correctamente!\n");
					}else{
						printf("\nNo se pudo quitar al jugador!\n");
					}system("PAUSE");
					break;
				case 3:
					continuar =0;
					break;

				}

			}

		}while(continuar==1);


	}


    return retorno;
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
	int retorno = -1;

	if(pArrayListSeleccion!=NULL)
	{
		ll_sort(pArrayListSeleccion,selec_ordenarPorConfederacion,1);
		printf("\nOrdenando...");
		controller_listarSelecciones(pArrayListSeleccion);
		retorno = 0;
	}

    return retorno;
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
	int retorno = -1;
	int tam;
	FILE* archivo=NULL;
	Seleccion* aux = NULL;

	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

	if(pArrayListSeleccion!=NULL && path!=NULL)
	{
		archivo=fopen(path,"w");
		if(archivo!=NULL)
		{
			tam=ll_len(pArrayListSeleccion);
			fprintf(archivo,"id,pais,confederacion,convocados\n");
			for(int i=0;i<tam;i++)
			{
				aux=ll_get(pArrayListSeleccion,i);
				if(aux!=NULL)
				{
					selec_getId(aux,&id);
					selec_getPais(aux,pais);
					selec_getConfederacion(aux,confederacion);
					selec_getConvocados(aux,&convocados);
					fprintf(archivo,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
				}
			}
			retorno=0;
		}
	}


	    return retorno;
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

int ordenarYlistar(LinkedList* listaJugadores,LinkedList* listaSelecciones)
{
	int retorno = -1;
	int opcion;
	int continuar=1;

	if(listaJugadores!=NULL && listaSelecciones!=NULL)
	{
		do{
			system("CLS");
			printf("-----ORDENAR Y LISTAR-----"
				"\n1.Ordenar jugadores[->+]."
				"\n2.Ordenar selecciones por confederacion."
				"\n3.Volver");

			if(utn_pedirInt(&opcion,"\n>Ingrese el criterio deseado: ","\n[!]Error,reintente.",1,3,3)==0)
			{
				switch(opcion)
				{
				case 1:
					if(controller_ordenarJugadores(listaJugadores)==0)
					{
						controller_listarJugadores(listaJugadores,listaSelecciones);
						printf("\n");
						system("PAUSE");
					}
					break;
				case 2:
					if(controller_ordenarSelecciones(listaSelecciones)==0)
					{
						printf("\n");
					}else{
						printf("\nOcurrio un error en el ordenamiento de selecciones!.\n");
						system("PAUSE");
					}
					break;
				case 3:
					continuar=0;
					break;
				}
			}
		}while(continuar==1);
		retorno =0;
	}
	return retorno;
}

int obtenerConfederacion(int id,char* respuesta)
{
	int retorno = -1;
	if(respuesta!=NULL && id>0)
	{
		switch(id)
		{
		case 1:
			strcpy(respuesta,"CONMEBOL");
			break;
		case 2:
			strcpy(respuesta,"UEFA");
			break;
		case 3:
			strcpy(respuesta,"AFC");
			break;
		case 4:
			strcpy(respuesta,"CAF");
			break;
		case 5:
			strcpy(respuesta,"CONCACAF");
			break;
		case 6:
			strcpy(respuesta,"OFC");
			break;
		}
		retorno = 0;
	}

	return retorno;
}

int leerBinario(char* path,LinkedList* listaJugadores,LinkedList* listaSelecciones)
{
	int retorno = -1;
	FILE* archivo = NULL;

	if(path!=NULL)
	{
		archivo=fopen(path,"rb");
		if(archivo!=NULL)
		{
			parser_JugadorFromBinary(archivo,listaJugadores,listaSelecciones);
			printf("\n");
		}else{
			printf("\nPrimero se debe generar el archivo!\n");
		}system("PAUSE");

	}

	return retorno;
}
