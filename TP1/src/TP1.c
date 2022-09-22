//Guia Leandro 1A.

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cargaDatos.h"
#include "calculos.h"

#define TAM 22

int main ()
{
	setbuf(stdout,NULL);

	//Variables del menu principal.
	int continuar = 1;
	int opcion;

	//Variables de costos.
	float costoHospedaje =0;
	float costoComida =0;
	float costoTransporte =0;

	//variables de jugadores.
	int arqueros =0;
	int defensores =0;
	int medioCampo =0;
	int delanteros =0;
	int camisetas[TAM];

	//confederaciones.
	int AFC =0;
	int CAF =0;
	int CONCACAF =0;
	int CONMEBOL =0;
	int UEFA =0;
	int OFC =0;

	//promedio confederaciones.
	float promAFC=0;
	float promCAF=0;
	float promCONCACAF=0;
	float promCONMEBOL=0;
	float promUEFA=0;
	float promOFC=0;

	inicializarCamisetas(camisetas,TAM);

	do{
		system("CLS");
		printf(" ***OPCIONES***\n1.Ingresar costos de mantenimiento."
				"\n  |Costo de hospedaje -> $%.2f"
				"\n  |Costo de comida -> $%.2f"
				"\n  `Costo de transporte -> $%.2f"
				"\n\n2.Carga de jugadores."
				"\n  |Arqueros -> %d"
				"\n  |Defensores -> %d"
				"\n  |Mediocampistas -> %d"
				"\n  `Delanteros -> %d"
				"\n\n3.Realizar los calculos."
				"\n4.Informar resultados."
				"\n5.Salir.\n\n",
				costoHospedaje,costoComida,costoTransporte,
				arqueros,defensores,medioCampo,delanteros);

		if(utn_pedirInt(&opcion,"Ingrese una opcion: ","error!",1,5,3)==0){
			switch(opcion){
			case 1:
				costosMantenimiento(&costoHospedaje,&costoComida,&costoTransporte);
				break;
			case 2:
				cargaJugadores(&arqueros,&defensores,&medioCampo,&delanteros,
						&AFC,&CAF,&CONCACAF,&CONMEBOL,&UEFA,&OFC,camisetas,TAM);
				break;
			case 3:
				if(calcularPromedio(UEFA,CONMEBOL,CONCACAF,AFC,OFC,CAF,
						&promUEFA,&promCONMEBOL,&promCONCACAF,&promAFC,&promOFC,&promCAF)!=-1){
					printf("\nCALCULOS OK!");
					pausa();
				}else{
					printf("\nOcurrio un problema al realizar los calculos!"
							"\n--POSIBLES CAUSAS--"
							"\n-Debe haber POR LO MENOS 1 jugador en cada CONFEDERACION, ya que para calcular promedios no se puede dividir por 0!."
							"\n-Se pudo haber recibido un puntero nulo.");
					pausa();
				}
				break;
			case 5:
				continuar = 0;
				break;

			}
		}else{
			printf("\nERROR, sin mas reintentos.");
			system("PAUSE");
		}


	}while(continuar == 1);


	return 0;
}