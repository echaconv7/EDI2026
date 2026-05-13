/*
 * PruebaPlaylist.h
 *
 *  Created on: 12 may 2026
 *      Author: elena
 */

#ifndef PRUEBAPLAYLIST_H_
#define PRUEBAPLAYLIST_H_

void pruebaPlaylistConstructores();
void pruebaGetYSetPlaylist ();
void pruebaRestoPlaylist();
void todasPruebaPlaylist ();

/* DISEÑO DE PRUEBAS PARA LA CLASE PLAYLIST (COLA)
 * 1. Prueba de Constructores:
 * - Caso 1: Constructor por defecto. Resultado esperado: Cola vacía, nombre vacío y contadores a 0.
 * - Caso 2: Constructor parametrizado ("musiquita"). Resultado esperado: Nombre asignado correctamente.
 * - Caso 3: Constructor por copia. Resultado esperado: Realiza una copia idéntica de la estructura y elementos de la cola.
 * * 2. Prueba de Métodos de Acceso (Getters y Setters):
 * - Caso: Modificar nombre, numCanciones y duracion usando los setters.
 * - Resultado esperado: Los getters devuelven exactamente los valores modificados.
 * * 3. Prueba de Resto de Métodos (Gestión de la Cola):
 * - Caso 1: Inserción de canciones (agregarCancion) y comprobación del contador.
 * - Caso 2: Eliminación de canciones (eliminarCancion).
 * - Resultado esperado (Casos 1 y 2): Se respeta el orden FIFO y los contadores de tiempo y número se ajustan automáticamente.
 * - Caso 3: Mostrar y simular reproducción (reproducirTodo y repUnNumCancion).
 * - Resultado esperado: La cola se recorre correctamente mostrando la información sin vaciarse de forma permanente.
 */

#endif /* PRUEBAPLAYLIST_H_ */
