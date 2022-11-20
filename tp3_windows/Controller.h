#include "Jugador.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
//int controller_agregarJugador(LinkedList* pArrayListJugador);

int controller_agregarJugador(LinkedList* pArrayListJugador,eNacionalidades listaNacionalidades[],
	int tamNacionalidades,int* idJugadores,ePosicion listaPosi[],int tamPosi);

int controller_editarJugador(LinkedList* pArrayListJugador,ePosicion listaPos[],
		eNacionalidades listaNacionalidades[],int tamPos, int tamNacionalidades);
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* selecciones);
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* selecciones);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

//-------------------------------------------------------------------------------------------------------

/// @brief Funcion encargada de crear o cargar el archivo que controla las ID de los jugadores.
/// Basicamente guardo el valor de id en un archivo y lo leo al iniciar el programa.
/// @param path Nombre del archivo
/// @return Retorna el valor ID guardado en el archivo o -1 en caso de error.
int iniciarID(char* path);

/// @brief
///
/// @param path
/// @param newId
/// @return
int actualizarArchivoID(char* path,int newId);

/// @brief
///
/// @param listaJugadores
/// @param listaSelecciones
/// @return
int menuListados(LinkedList* listaJugadores,LinkedList* listaSelecciones);

/// @brief
///
/// @param listaJugadores
/// @param listaSelecciones
/// @return
int convocarJugadores(LinkedList* listaJugadores,LinkedList* listaSelecciones);
