#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);

    LinkedList* listaJugadores = ll_newLinkedList();

    int opcion = 0;
    int idAux=370; //EL PRIMERO DEBE SER 371!

    do{
    	system("CLS");
    	if(utn_pedirInt(&opcion,"\nMENU:\n1.Cargar archivo.\n2.Alta de jugador.\n3.Modificar jugador.\n4.Baja de jugador."
    			"\n5.Listados\n6.Convocar jugadores.\n7.Ordenar y listar.\n8.Generar archivo binario.\n9.Cargar archivo binario."
    			"\n10.Guardar archivos .csv.\n11.SALIR\n\n>Ingrese una opcion: ","\nError, reintente.",1,11,99)==0)
    	{
    		switch(opcion)
    		{
    		  case 1:
    			  controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
    		  break;

    		}

    	}


    }while(opcion != 10);

    return 0;
}

