/*
 * PruebaUsuario.h
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */

#ifndef PRUEBAUSUARIO_H_
#define PRUEBAUSUARIO_H_

#include "Usuario.h"

#include <iostream>

void pruebasConstructores ();

void pruebasSetYGet ();

void restoMetodos ();

void pruebasPlaylistsYFavoritos();

void todasPruebasUsuario ();

/* DISEÑO DE PRUEBAS PARA LA CLASE USUARIO
 * 1. Prueba de Constructores:
 * - Caso 1: Constructor por defecto. Resultado esperado: Atributos en blanco, listas vacías.
 * - Caso 2: Constructor parametrizado. Resultado esperado: Atributos asignados correctamente.
 * - Caso 3: Constructor por copia. Resultado esperado: Copia profunda de datos, fecha y listas.
 *
 * 2. Prueba de Getters y Setters:
 * - Caso: Modificar y recuperar id, nombre, email y password.
 * - Resultado esperado: Los valores devueltos coinciden con los asignados.
 *
 * 3. Prueba de Playlists (crearPlayList, anadirCancion, compartir, eliminar):
 * - Inserción en lista vacía, inserción de duplicado (no debe insertarse).
 * - Añadir canción a una playlist existente e inexistente.
 * - Compartir genera una copia independiente.
 * - Eliminar playlist existente e inexistente.
 *
 * 4. Prueba de Artistas Favoritos (insertar, eliminar):
 * - Inserción de un artista nuevo. Resultado esperado: se añade correctamente.
 * - Inserción de duplicado. Resultado esperado: no se vuelve a insertar.
 * - Eliminación de artista existente e inexistente.
 */

#endif /* PRUEBAUSUARIO_H_ */
