/*
 * calculos.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Leandro
 */
#include "calculos.h"
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

	if(promUEFA!=NULL && promCONMEBOL!=NULL && promCONCACAF!=NULL && promAFC!=NULL && promOFC!=NULL && promCAF!=NULL &&
			cUEFA!=0 && cCONMEBOL!=0 && cCONCACAF!=0 && cAFC!=0 && cOFC!=0 && cCAF!=0){

		//suma de totales.
		//Divido el individual por los totales.
		//multiplico por 100 y me da el porcentaje.
		printf("\nREALIZANDO CALCULOS...");
		jugadoresTotales=cUEFA+cCONMEBOL+cCONCACAF+cAFC+cOFC+cCAF;

		*promUEFA = (cUEFA/jugadoresTotales)*100;
		*promCONMEBOL = (cCONMEBOL/jugadoresTotales)*100;
		*promCONCACAF = (cCONCACAF/jugadoresTotales)*100;
		*promAFC = (cAFC/jugadoresTotales)*100;
		*promOFC = (cOFC/jugadoresTotales)*100;
		*promCAF = (cCAF/jugadoresTotales)*100;

		retorno = 0;
	}


	return retorno;
}
