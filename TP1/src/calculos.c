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

int mostrarResultados(){

	printf("\nsas");
	return 0;
}

int calcularPromedio(int cUEFA, int cCONMEBOL,int cCONCACAF,int cAFC,int cOFC,int cCAF,
		float* promUEFA,float* promCONMEBOL,float* promCONCACAF,float* promAFC, float* promOFC,float* promCAF){

	int retorno =-1;

	int jugadoresTotales=0;

	if(promUEFA!=NULL && promCONMEBOL!=NULL && promCONCACAF!=NULL && promAFC!=NULL && promOFC!=NULL && promCAF!=NULL)
	{

		//&& cUEFA!=0 && cCONMEBOL!=0 && cCONCACAF!=0 && cAFC!=0 && cOFC!=0 && cCAF!=0){
		//suma de totales.
		//Divido el individual por los totales.
		//multiplico por 100 y me da el porcentaje.
		printf("\nREALIZANDO CALCULOS...");
		jugadoresTotales=cUEFA+cCONMEBOL+cCONCACAF+cAFC+cOFC+cCAF;

		if(cUEFA!=0)
		{
			*promUEFA = (cUEFA/jugadoresTotales)*100;
		}

		if(cCONMEBOL!=0)
		{
			*promCONMEBOL = (cCONMEBOL/jugadoresTotales)*100;
		}

		if(cCONCACAF!=0)
		{
			*promCONCACAF = (cCONCACAF/jugadoresTotales)*100;
		}

		if(cAFC!=0)
		{
			*promAFC = (cAFC/jugadoresTotales)*100;
		}

		if(cOFC!=0)
		{
			*promOFC = (cOFC/jugadoresTotales)*100;
		}

		if(cCAF!=0)
		{
			*promCAF = (cCAF/jugadoresTotales)*100;
		}

		retorno = 0;
	}


	return retorno;
}


int calcMantenimiento(int* pUEFA,int* pCONMEBOL,int* pCONCACAF,int* pAFC,int* pOFC,int* pCAF,int* hospedaje,int* comida,int* transporte)
{
	int retorno = -1;
	int total = 0;
	int totalActualizado = 0;
	int aumento = 0;
	int flagAumento = 0; //sacable

	if(pUEFA!=NULL && pCONMEBOL!=NULL && pCONCACAF!=NULL && pAFC!=NULL && pOFC!=NULL && pCAF!=NULL
		&& hospedaje!=NULL && comida!=NULL && transporte!=NULL)
	{
		total = *hospedaje+*comida+*transporte;


		if(*pUEFA>*pCONMEBOL && *pUEFA>*pCONCACAF && *pUEFA>*pAFC && *pUEFA>*pOFC && *pUEFA>*pCAF)
		{
			printf("\nLa mayoria de jugadores en el equipo son de la UEFA, se aplicara comision!");
			flagAumento = 1;

			aumento = total*35/100;
			totalActualizado = total+aumento;

			pausa();
		}

	}


	return retorno;
}
