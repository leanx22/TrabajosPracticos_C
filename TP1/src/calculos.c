/*
 * calculos.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Leandro
 */
#include "calculos.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>

int mostrarResultados(float* pUEFA,float* pCONMEBOL,float* pCONCACAF,float* pAFC,float* pOFC,float* pCAF,float costoMantenimiento,float costoActualizado,float comision)
{
	int retorno = -1;
	if(pUEFA!=NULL && pCONMEBOL!=NULL && pCONCACAF!=NULL && pAFC!=NULL && pOFC!=NULL && pCAF!=NULL)
	{
		system("CLS");
		printf("***INFORME DE RESULTADOS***");
		printf("\nPorcentaje UEFA: %.2f",*pUEFA);
		printf("\nPorcentaje CONMEBOL: %.2f",*pCONMEBOL);
		printf("\nPorcentaje CONCACAF: %.2f",*pCONCACAF);
		printf("\nPorcentaje AFC: %.2f",*pAFC);
		printf("\nPorcentaje OFC: %.2f",*pOFC);
		printf("\nPorcentaje CAF: %.2f",*pCAF);

		printf("\n\nCOSTOS DE MANTENIMIENTO:");
		if(comision != 0)
		{
			printf("\nEl costo de mantenimiento era de %.2f, pero recibio un aumento de %.2f. El valor actual es de %.2f\n", costoMantenimiento,comision,costoActualizado);
			system("PAUSE");
		}else{
			printf("\nEl costo de mantenimiento es de %.2f\n",costoMantenimiento);
			system("PAUSE");
		}

	}



	return retorno;
}

int Promedios(int cUEFA, int cCONMEBOL,int cCONCACAF,int cAFC,int cOFC,int cCAF,
		float* promUEFA,float* promCONMEBOL,float* promCONCACAF,float* promAFC, float* promOFC,float* promCAF)
{

	int retorno =-1;

	int jugadoresTotales=0;

	if(promUEFA!=NULL && promCONMEBOL!=NULL && promCONCACAF!=NULL && promAFC!=NULL && promOFC!=NULL && promCAF!=NULL)
	{

		printf("\nREALIZANDO CALCULOS...");
		jugadoresTotales=cUEFA+cCONMEBOL+cCONCACAF+cAFC+cOFC+cCAF;

		*promUEFA=calcularPromedio(cUEFA,jugadoresTotales);
		*promCONMEBOL=calcularPromedio(cCONMEBOL,jugadoresTotales);
		*promCONCACAF=calcularPromedio(cCONCACAF,jugadoresTotales);
		*promAFC=calcularPromedio(cAFC,jugadoresTotales);
		*promOFC=calcularPromedio(cOFC,jugadoresTotales);
		*promCAF=calcularPromedio(cCAF,jugadoresTotales);

		retorno = 0;
	}


	return retorno;
}


int calcMantenimiento(float* pUEFA,float* pCONMEBOL,float* pCONCACAF,float* pAFC,float* pOFC,float* pCAF,
		float hospedaje,float comida,float transporte,float* costoOriginal,float* costoActualizado,float* comision)
{
	int retorno = -1;
	float total = 0;
	float totalActualizado = 0;
	float aumento = 0;

	if(pUEFA!=NULL && pCONMEBOL!=NULL && pCONCACAF!=NULL && pAFC!=NULL && pOFC!=NULL && pCAF!=NULL)
	{
		total = hospedaje+comida+transporte;


		if(*pUEFA>*pCONMEBOL && *pUEFA>*pCONCACAF && *pUEFA>*pAFC && *pUEFA>*pOFC && *pUEFA>*pCAF)
		{
			printf("\nLa mayoria de jugadores en el equipo son de la UEFA, se aplicara comision!");

			aumento = total*35/100;
			totalActualizado = total+aumento;
		}

		*costoOriginal = total;
		*costoActualizado = totalActualizado;
		*comision = aumento;
		retorno = 0;
	}


	return retorno;
}


float calcularPromedio(int cConfederacion,int totalJugadores){
	float retorno = 0;

	if(cConfederacion!=0)
	{
		//retorno = (cConfederacion*100)/totalJugadores;
		retorno= (float)cConfederacion/totalJugadores;
	}
	return retorno;
}








