/*
 * PruebaGestorArtistas.h
 *
 *  Created on: 13 may 2026
 *      Author: Marcos
 */

#ifndef PRUEBAGESTORARTISTAS_H_
#define PRUEBAGESTORARTISTAS_H_

#include "GestorArtistas.h"
#include <iostream>

using namespace std;

void todasPruebasGestorArtistas();


/* DISEÑO DE PRUEBAS PARA EL GESTOR DE ARTISTAS
 *
 * 1. Pruebas de Comportamiento con Estructura Vacía:
 * - Caso 1.1: Búsqueda cuando la lista/árbol está vacía.
 * > Resultado Esperado: Devuelve false y muestra "No encontrado".
 * - Caso 1.2: Método mostrar cuando está vacía.
 * > Resultado Esperado: No se cuelga y no imprime ningún artista.
 * - Caso 1.3: Inserción cuando la estructura está vacía (Ej: "Mecano").
 * > Resultado Esperado: Se inserta correctamente como único elemento.
 *
 * 2. Pruebas de Inserción (Principio, Medio, Final):
 * - Caso 2.1: Inserción al principio (Ej: "Adele", va antes que "Mecano").
 * > Resultado Esperado: Se inserta a la izquierda (árbol) o al inicio (lista).
 * - Caso 2.2: Inserción al final (Ej: "Rosalía", va después que "Mecano").
 * > Resultado Esperado: Se inserta a la derecha (árbol) o al final (lista).
 * - Caso 2.3: Inserción en una posición intermedia (Ej: "Estopa", entre Adele y Mecano).
 * > Resultado Esperado: Se ubica en el hueco alfabético correcto.
 *
 * 3. Pruebas de Búsqueda con Elementos:
 * - Caso 3.1: Búsqueda de un artista existente ("Estopa").
 * > Resultado Esperado: Devuelve true y permite acceder a sus datos.
 * - Caso 3.2: Búsqueda de un artista que no se encuentra ("Artista Falso").
 * > Resultado Esperado: Devuelve false.
 *
 * 4. Prueba de Mostrar y Recorrer:
 * - Caso 4.1: Mostrar todos los artistas almacenados.
 * > Resultado Esperado: Se imprimen en orden estrictamente alfabético
 * (Adele -> Estopa -> Mecano -> Rosalía) demostrando que la inserción fue correcta.
 */

#endif /* PRUEBAGESTORARTISTAS_H_ */
