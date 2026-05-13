/*
 * PruebaCancion.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef PRUEBACANCION_H_
#define PRUEBACANCION_H_
#include "Cancion.h"

void pruebaConstructoresCancion();
void pruebaGetYSetCancion();
void pruebaRestoCancion();
void todasPruebasCancion();

/* DISEÑO DE PRUEBAS PARA LA CLASE CANCION
 * 1. Prueba de Constructores:
 * - Caso 1: Constructor por defecto. Resultado esperado: Atributos en blanco o a 0.
 * - Caso 2: Constructor parametrizado ("Beautiful things"). Resultado esperado: Atributos correctos.
 * - Caso 3: Constructor por copia. Resultado esperado: Copia profunda exacta de la canción.
 * * 2. Prueba de Métodos de Acceso (Getters y Setters):
 * - Caso: Modificar el título, género y duración y comprobarlos.
 * - Resultado esperado: Los valores se actualizan y devuelven correctamente.
 * * 3. Prueba de Operadores:
 * - Caso: Comprobar el funcionamiento de los operadores sobrecargados (== y <).
 * - Resultado esperado: Ordenación y comparación correctas por título.
 */


#endif /* PRUEBACANCION_H_ */
