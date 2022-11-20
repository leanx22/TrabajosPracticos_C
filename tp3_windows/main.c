#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"

#define CANT_NACIONALIDADES 31 //32 mepa
#define CANT_POS 14
#define ARCHIVO_ID "valor_id.utn"

int main(void)
{
	setbuf(stdout,NULL);

	int continuar = 1;
	int opcion = 0;
	int idAux; //EL PRIMERO DEBE SER 371!

	//todo FLAGS!

    eNacionalidades listaNacionalidad[CANT_NACIONALIDADES];
    hardcodearNacionalidades(listaNacionalidad,CANT_NACIONALIDADES);

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    ePosicion listaPosiciones[CANT_POS] =
    {{1,"Portero"},{2,"Defensa"},{3,"Defensa central"},{4,"Lateral izquierdo"},
     {5,"Lateral derecho"},{6,"Pivote"},{7,"Mediocentro"},{8,"Extremo izquierdo"},
     {9,"Extremo derecho"},{10,"Mediapunta"},{11,"Delantero centro"},{12,"Mediocentro ofensivo"},
     {13,"Interior derecho"},{14,"Interior izquierdo"}};

    idAux = iniciarID(ARCHIVO_ID);

    do{
    	system("CLS");
    	if(utn_pedirInt(&opcion,"\nMENU:\n1.Cargar archivo.\n2.Alta de jugador.\n3.Modificar jugador.\n4.Baja de jugador."
    			"\n5.Listados\n6.Convocar jugadores.\n7.Ordenar y listar.\n8.Generar archivo binario.\n9.Cargar archivo binario."
    			"\n10.Guardar archivos .csv.\n11.SALIR\n\n>Ingrese una opcion: ","\nError, reintente.",1,11,99)==0)
    	{
    		switch(opcion)
    		{
    		  case 1:
    			  if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) ==0 &&
    			  controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones)==0)
    			  {
    				  printf("\nLos archivos se cargaron satisfactoriamente!.\n");
    			  }else{
    				  printf("\nOcurrio un error al intentar abrir los archivos!.\n");
    			  }
    			  system("PAUSE");
    		  break;
    		  case 2:
    			  if(controller_agregarJugador(listaJugadores,listaNacionalidad,CANT_NACIONALIDADES,
    					&idAux,listaPosiciones,CANT_POS)==0 && actualizarArchivoID(ARCHIVO_ID,idAux)==0)
    			  {
    				  printf("\n>Jugador agregado satisfactoriamente!\n");
    			  }else{
    				  printf("\nOcurrio un problema al aniadir al jugador.\n");
    			  }
    			  system("PAUSE");
    			  break;
    		  case 3:
    			  if(controller_listarJugadores(listaJugadores,listaSelecciones)==0 &&
    				 controller_editarJugador(listaJugadores,listaPosiciones,listaNacionalidad,
    					  CANT_POS,CANT_NACIONALIDADES)!=0)
    			  {
    				  printf("\nError en edicion.\n");
    				  system("PAUSE");
    			  }
    			  break;
    		  case 4: //todo modificar el contador de la seleccion.
    			  if(controller_removerJugador(listaJugadores,listaSelecciones)==0)
    			  {
    				  printf("\nJugador eliminado correctamente!\n");
    			  }else{
    				  printf("\n[!]No se encontro o no se pudo eliminar al jugador!\n");
    			  }system("PAUSE");
    			  break;
    		  case 5:
    			  menuListados(listaJugadores,listaSelecciones);
    			  break;
    		  case 6:
    			  controller_editarSeleccion(listaSelecciones,listaJugadores);
    			  break;
    		  case 11:
    			  continuar = 0;
    			 break;
    		}

    	}


    }while(continuar == 1);

    return 0;
}

