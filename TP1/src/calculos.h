/*
 * calculos.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Leandro
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#endif /* CALCULOS_H_ */



int mostrarResultados(float* pUEFA,float* pCONMEBOL,float* pCONCACAF,float* pAFC,float* pOFC,float* pCAF,
		float costoMantenimiento,float costoActualizado,float comision);

/// @brief Funcion encargada de realizar los calclos correspondientes a los promedios de las confederaciones.
///
/// @param cUEFA variable contador de jugadores de la confederacion UEFA.
/// @param cCONMEBOL variable contador de jugadores de la confederacion CONMEBOL.
/// @param cCONCACAF variable contador de jugadores de la confederacion CONCACAF.
/// @param cAFC variable contador de jugadores de la confederacion AFC.
/// @param cOFC variable contador de jugadores de la confederacion OFC.
/// @param cCAF variable contador de jugadores de la confederacion AFC.
/// @param promUEFA puntero a variable donde se guardara el promedio de la confederacion UEFA.
/// @param promCONMEBOL puntero a variable donde se guardara el promedio de la confederacion CONMEBOL.
/// @param promCONCACAF puntero a variable donde se guardara el promedio de la confederacion CONCACAF.
/// @param promAFC puntero a variable donde se guardara el promedio de la confederacion AFC.
/// @param promOFC puntero a variable donde se guardara el promedio de la confederacion OFC.
/// @param promCAF puntero a variable donde se guardara el promedio de la confederacion CAF.
/// @return retorna 0 si salio OK o -1 en caso de puntero nulo.
int Promedios(int cUEFA, int cCONMEBOL,int cCONCACAF,int cAFC,int cOFC,int cCAF,
		float* promUEFA,float* promCONMEBOL,float* promCONCACAF,float* promAFC, float* promOFC,float* promCAF);


/// @brief  Funcion encargada de calcular los costos de mantenimiento junto con la comision en caso de que la mayoria
/// de jugadores sean de la UEFA.
///
/// @param pUEFA Puntero a variable donde se guarda el PROMEDIO de la confederacion
/// @param pCONMEBOL Puntero a variable donde se guarda el PROMEDIO de la confederacion
/// @param pCONCACAF Puntero a variable donde se guarda el PROMEDIO de la confederacion
/// @param pAFC Puntero a variable donde se guarda el PROMEDIO de la confederacion
/// @param pOFC Puntero a variable donde se guarda el PROMEDIO de la confederacion
/// @param pCAF Puntero a variable donde se guarda el PROMEDIO de la confederacion
/// @param hospedaje var
/// @param comida
/// @param transporte
/// @param costoOriginal
/// @param costoActualizado
/// @param comision
/// @return
int calcMantenimiento(float* pUEFA,float* pCONMEBOL,float* pCONCACAF,float* pAFC,float* pOFC,float* pCAF,
		float hospedaje,float comida,float transporte,float* costoOriginal,float* costoActualizado,float* comision);

//BORRAR
float calcularPromedio(int cConfederacion,int totalJugadores);



