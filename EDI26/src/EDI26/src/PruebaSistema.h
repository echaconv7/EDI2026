/*
 * PruebaSistema.h
 *
 *  Created on: 13 may 2026
 *      Author: Marcos
 */

#ifndef PRUEBASISTEMA_H_
#define PRUEBASISTEMA_H_

#include "Sistema.h"
#include <iostream>

using namespace std;


// PRE: ---
// DESC: Función principal que invoca todas las pruebas de la clase Sistema.
void todasPruebasSistema();

/* ==============================================================================
 * DISEÑO DE PRUEBAS PARA LA CLASE SISTEMA
 * ==============================================================================
 *
 * 1. Prueba de Carga Inicial (Constructores y Mostrar):
 * - Se creará un objeto dinámico Sistema ("Spotify Pruebas").
 * - Resultado Esperado: Se leen los ficheros CSV y se cargan los usuarios,
 * artistas, canciones y playlists sin errores. Las funciones mostrar volcarán
 * los datos reales de los CSV en la consola.
 *
 * 2. Prueba de Búsquedas (buscarUsuario y buscarArtistas):
 * - Caso 1: Búsqueda de un usuario/artista que SI existe en el CSV (Ej: Alcobendas Santos, Jaime).
 * Resultado Esperado: Muestra los datos correctamente por pantalla.
 * - Caso 2: Búsqueda de un usuario/artista que NO existe.
 * Resultado Esperado: Muestra el mensaje de que no se ha encontrado.
 *
 * 3. Prueba de Playlists (Reproducir, Compartir, Eliminar):
 * - Caso 1: Reproducir una playlist real cargada ("Zona estudio" de Jaime).
 * Resultado Esperado: Se muestran las canciones por consola (Alejandro Sanz, Coldplay, etc).
 * - Caso 2: Compartir esa playlist con otro usuario válido ("Madruga Maraver, Angel").
 * Resultado Esperado: Mensaje de éxito de compartición.
 * - Caso 3: Reproducir la playlist en el usuario receptor para comprobar la copia.
 * Resultado Esperado: Se muestran las mismas canciones.
 * - Caso 4: Eliminar la playlist copiada del usuario receptor.
 * Resultado Esperado: Mensaje de éxito al eliminar.
 *
 * 4. Prueba de Artistas Favoritos:
 * - Caso 1: Añadir artista favorito a dos usuarios distintos (Ej: "Coldplay").
 * Resultado Esperado: Mensaje de éxito y aumenta el numSeg del artista a 2.
 * - Caso 2: Mostrar el artista con más seguidores.
 * Resultado Esperado: Debería salir "Coldplay" al ser el único con seguidores forzados.
 * ==============================================================================
 */

// PRE: ---
// DESC: Ejecuta los casos de prueba de carga y búsquedas (existentes e inexistentes).
void pruebaConstructoresYBusquedas();

// PRE: ---
// DESC: Ejecuta los casos de prueba de las interacciones con Playlists y Favoritos.
void pruebaPlaylistsYFavoritos();

#endif /* PRUEBASISTEMA_H_ */
