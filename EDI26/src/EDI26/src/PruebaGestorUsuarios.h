/*
 * PruebaGestorUsuarios.h
 *
 *  Created on: 13 may 2026
 *      Author: Marcos
 */

#ifndef PRUEBAGESTORUSUARIOS_H_
#define PRUEBAGESTORUSUARIOS_H_


#include "GestorUsuarios.h"
#include <iostream>

using namespace std;

void todasPruebasGestorUsuarios();

/* DISEÑO DE PRUEBAS PARA EL GESTOR DE USUARIOS
 *
 * 1. Pruebas de Comportamiento con Estructura Vacía:
 * - Caso 1.1: Búsqueda cuando la lista/árbol está vacía.
 * > Resultado Esperado: Devuelve false y muestra "No encontrado".
 * - Caso 1.2: Método mostrar cuando está vacía.
 * > Resultado Esperado: No imprime ningún usuario ni provoca errores.
 * - Caso 1.3: Inserción cuando la estructura está vacía ("Dominguez Corchero, Mikel").
 * > Resultado Esperado: Se inserta correctamente como primer y único elemento.
 *
 * 2. Pruebas de Inserción (Principio, Final, Medio):
 * - Caso 2.1: Inserción al principio ("Aguado Pino, Marcos", va antes que Dominguez).
 * > Resultado Esperado: Se inserta al inicio de la estructura.
 * - Caso 2.2: Inserción al final ("Jimenez Muñoz, Daniel", va después que Dominguez).
 * > Resultado Esperado: Se inserta al final de la estructura.
 * - Caso 2.3: Inserción en una posición intermedia ("Carrasco Toscano, Jesus", va
 * entre Aguado y Dominguez).
 * > Resultado Esperado: Se ubica correctamente en el medio respetando el orden alfabético.
 *
 * 3. Pruebas de Búsqueda con Elementos:
 * - Caso 3.1: Búsqueda de un usuario existente ("Carrasco Toscano, Jesus").
 * > Resultado Esperado: Devuelve true y permite el acceso al objeto.
 * - Caso 3.2: Búsqueda de un usuario que no se encuentra ("Zanahoria, Pepe").
 * > Resultado Esperado: Devuelve false.
 *
 * 4. Prueba de Mostrar y Recorrer:
 * - Caso 4.1: Mostrar todos los usuarios almacenados.
 * > Resultado Esperado: Se imprimen todos los usuarios insertados en estricto
 * orden alfabético (Aguado -> Carrasco -> Dominguez -> Jimenez).
 */

#endif /* PRUEBAGESTORUSUARIOS_H_ */
