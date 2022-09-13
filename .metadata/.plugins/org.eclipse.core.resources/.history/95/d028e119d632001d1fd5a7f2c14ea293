//Guia Leandro 1A.

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cargaDatos.h"

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

	do{
		system("CLS");
		printf(" ***OPCIONES***\n1)Ingresar costos de mantenimiento.\n2)Carga de jugadores.\n"
				"3)Realizar los calculos.\n4)Informar resultados.\n5)Salir.\n\n");

		if(utn_pedirInt(&opcion,"Ingrese una opcion: ","error!",1,5,3)==0){
			switch(opcion){
			case 1:
				costosMantenimiento(&costoHospedaje,&costoComida,&costoTransporte);
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
