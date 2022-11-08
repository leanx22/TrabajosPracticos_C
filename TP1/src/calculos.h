/*
 * calculos.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Leandro
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#endif /* CALCULOS_H_ */


/// @brief Esta funcion es la encargada de mostrar los resultados pedidos y realizados por la opcion 3.
///
/// @param pUEFA puntero a variable donde se guarda el promedio de la confederacion.
/// @param pCONMEBOL ""
/// @param pCONCACAF ""
/// @param pAFC ""
/// @param pOFC ""
/// @param pCAF ""
/// @param costoMantenimiento Costo de mantenimiento original.
/// @param costoActualizado Costo de mantenimiento+el aumento.
/// @param comision SOLO EL AUMENTO que se le aplico al costo de mantenimiento.
/// @return retorna 0 si OK o -1 si hay error o null.
int mostrarResultados(float* pUEFA,float* pCONMEBOL,float* pCONCACAF,float* pAFC,float* pOFC,float* pCAF,
		float costoMantenimiento,float costoActualizado,float comision);

/// @brief Funcion encargada de realizar los calculos correspondientes a los porcentajes de las confederaciones y
/// guardarlas en los punteros.
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
int Porcentajes(int cUEFA, int cCONMEBOL,int cCONCACAF,int cAFC,int cOFC,int cCAF,
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

/// @brief Funcion encargada de sacar porcentaje entre una cantidad de jugadores de una confederacion y los totales.
///
/// @param cConfederacion cantidad de jugadores en X confederacion.
/// @param totalJugadores TOTAL de jugadores sin importar su confederacion,
/// @return retorna el porcentaje calculado o 0 en caso de que se quiera dividir por 0.
float calcularPorcentaje(int cConfederacion,int totalJugadores);



