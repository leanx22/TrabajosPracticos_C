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
	int cConvocados=0;

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
    	if(utn_pedirInt(&opcion,"\nMENU:\n1.Cargar archivos.\n2.Alta de jugador.\n3.Modificar jugador.\n4.Baja de jugador."
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
    			  if(ll_isEmpty(listaJugadores)==0)
    			  {
    				  if(controller_listarJugadores(listaJugadores,listaSelecciones)==0 &&
    						  controller_editarJugador(listaJugadores,listaPosiciones,listaNacionalidad,
    								  CANT_POS,CANT_NACIONALIDADES)!=0)
    				  {
    					  printf("\nError en edicion.\n");
    					  system("PAUSE");
    				  }
    			  }else{
    				  printf("\nAun no hay jugadores para editar!\n");
    				  system("PAUSE");
    			  }
    			  break;
    		  case 4:
    			  if(ll_isEmpty(listaJugadores)==0)
    			  {
    				  if(controller_removerJugador(listaJugadores,listaSelecciones)==0)
    				  {
    					  printf("\nJugador eliminado correctamente!\n");
    				  }else{
    					  printf("\n[!]No se encontro o no se pudo eliminar al jugador!\n");
    				  }system("PAUSE");
    			  }else{
    				  printf("\nPrimero debe cargarse al menos un jugador!\n");
    				  system("PAUSE");
    			  }
    			  break;
    		  case 5:
    			  if(ll_isEmpty(listaJugadores)==0)
    			  {
    				  menuListados(listaJugadores,listaSelecciones);
    			  }else{
    				  printf("\nAun no se cargaron jugadores!\n");
    				  system("PAUSE");
    			  }
    			  break;
    		  case 6:
    			  if(ll_isEmpty(listaJugadores)==0)
    			  {
    				  controller_editarSeleccion(listaSelecciones,listaJugadores);
    			  }else{
    				  printf("\nAun no hay jugadores cargados!\n");
    				  system("PAUSE");
    			  }
    			  break;
    		  case 7:
    			  if(ll_isEmpty(listaJugadores)==0&&cConvocados>0)
    			  {
    				  ordenarYlistar(listaJugadores,listaSelecciones);
    			  }else{
    				  printf("\nError, aun no hay altas o no se convoco a ningun jugador!\n");
    				  system("PAUSE");
    			  }
    			  break;
    		  case 8:
    			  //flag
    			  controller_guardarJugadoresModoBinario("JugadoresFiltrados.bin",listaJugadores,listaSelecciones);
    			  break;
    		  case 9:
    			  leerBinario("JugadoresFiltrados.bin",listaJugadores,listaSelecciones);
    			  break;
    		  case 10:
    			  if(ll_isEmpty(listaJugadores)==0 &&
    					controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores)==0 &&
						controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones)==0)
    			  {
    				  printf("\nArchivos guardados!\n");
    			  }else{
    				  printf("\nOcurrio un error o aun no hay jugadores para guardar!\n");
    			  }system("PAUSE");
    			  break;
    		  case 11:
    			  continuar = 0;
    			 break;
    		}

    	}

    }while(continuar == 1);

    return 0;
}

