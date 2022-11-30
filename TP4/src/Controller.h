#include "Jugador.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador,LinkedList*listaSelecciones);
//int controller_agregarJugador(LinkedList* pArrayListJugador);

int controller_agregarJugador(LinkedList* pArrayListJugador,eNacionalidades listaNacionalidades[],
	int tamNacionalidades,int* idJugadores,ePosicion listaPosi[],int tamPosi);

int controller_editarJugador(LinkedList* pArrayListJugador,ePosicion listaPos[],
		eNacionalidades listaNacionalidades[],int tamPos, int tamNacionalidades);
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* selecciones);
int controller_listarJugadores(LinkedList* pArrayListJugador,LinkedList* selecciones);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* listaSeleccion);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

//-------------------------------------------------------------------------------------------------------

/// @brief Funcion encargada de crear o cargar el archivo que controla las ID de los jugadores.
/// Basicamente guardo el valor de id en un archivo y lo leo al iniciar el programa.
/// @param path Nombre del archivo
/// @return Retorna el valor ID guardado en el archivo o -1 en caso de error.
int iniciarID(char* path);

/// @brief Funcion que actualiza el ID a asignar en el archivo.
///
/// @param path
/// @param newId Valor de id nuevo.
/// @return retorna 0 si OK O -1 si hay error.
int actualizarArchivoID(char* path,int newId);

/// @brief Funcion que imprime el menu de la opcion 5, y permite elegir que listar.
///
/// @param listaJugadores
/// @param listaSelecciones
/// @param listaClonada
/// @return retorna 0 si OK O -1 si hay error.
int menuListados(LinkedList* listaJugadores,LinkedList* listaSelecciones,LinkedList* listaClonada);

/// @brief Esta funcion ordena y lista a los jugadores o selecciones segun el criterio dado.
///
/// @param listaJugadores
/// @param listaSelecciones
/// @return 0 si OK o -1 en caso de error.
int ordenarYlistar(LinkedList* listaJugadores,LinkedList* listaSelecciones);

/// @brief Esta funcion sirve para obtener la descripcion de la confederacion por medio de un ID
/// (utilizado en altas)
///
/// @param id Id de la confederacion de la cual se desea saber la descripcion.
/// @param respuesta Variable donde se guardara la descripcion.
/// @return retorna 0 si OK o -1 en caso de error.
int obtenerConfederacion(int id,char* respuesta);

