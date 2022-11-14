#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;

	char bufId[4];
	char bufNombre[100];
	char bufEdad[4];
	char bufPos[30];
	char nacionalidad[30];
	char idSeleccion[4];

	Jugador* aux = NULL;

	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufNombre,bufEdad,bufPos,nacionalidad,idSeleccion);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufId,bufNombre,bufEdad,bufPos,nacionalidad,idSeleccion)==6)
			{

				aux = jug_newParametros(bufId,bufNombre,bufEdad,bufPos,nacionalidad,idSeleccion);
				retorno = ll_add(pArrayListJugador,aux);
			}

		}while(!feof(pFile));
		if(fclose(pFile)!=0)
		{
			printf("\nNo se pudo cerrar el archivo!");
			system("PAUSE");
		}
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* aux=NULL;

	char id[4];
	char pais[20];
	char confederacion[20];
	char convocados[4];

	if(pArrayListSeleccion!=NULL && pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados)==4)
			{
				aux=selec_newParametros(id,pais,confederacion,convocados);
				retorno = ll_add(pArrayListSeleccion,aux);//
			}

		}while(!feof(pFile));
		if(fclose(pFile)!=0)
		{
			printf("\nEl archivo no se pudo cerrar!\n");
			retorno = -1;
			system("PAUSE");
		}
	}

    return retorno;
}





