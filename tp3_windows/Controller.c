#include <stdio.h>
#include <stdlib.h>

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
int controller_agregarJugador(LinkedList* pArrayListJugador,eNacionalidades listaNacionalidades[],int tamNacionalidades)
{
   int retorno = -1;

   char nombre[50];
   int edad;
   int posicion;
   int idNacionalidad;
   int idSeleccion;

   if(pArrayListJugador!=NULL)
   {
	   if(utn_getStr(nombre,"\n>Ingrese el nombre del Jugador: ","\n[!]Error, reintente.",50,3)==0 &&
			utn_pedirInt(&edad,"\n>Ingrese la edad del Jugador: ","\n[!]Error, reintente.",17,100,3)==0 &&
			utn_pedirInt(&posicion,"\n>Ingrese la posicion: \n1.Arquero.\n2.Defensa.\n3.MedioCampo.\n4.Delantero.\n",
				"\n[!]Error, reingrese.",1,4,3)==0 &&
			imprimirNacionalidades(listaNacionalidades,tamNacionalidades)==0 &&
			utn_pedirInt(&idNacionalidad,"\n>Ingrese ID de nacionalidad: ","\n[!]Error, reintente.",1,32,3)==0 &&
			//IMPRIMIR SELECCIONES.
			utn_pedirInt(&idSeleccion,"\n>Ingrese ID de la seleccion: ","\n[!]Error, reintente.",1,31,3)==0)
	   {

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
int controller_editarJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
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
    return 1;
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


