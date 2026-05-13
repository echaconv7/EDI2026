/*
 * PruebaArtista.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef PRUEBAARTISTA_H_
#define PRUEBAARTISTA_H_

void pruebaConstructoresArtista();
void pruebaGetYSetArtista();
void pruebaRestoArtista();
void todasPruebasArtista();

/* Pruebas lista de canciones de Artista:
 * - numElementos en lista vacía → 0
 * - Inserción en vacía, principio, final, intermedia → numElementos correcto
 * - Inserción de duplicado → no se inserta
 * - buscarCancion existente → true y puntero válido
 * - buscarCancion no existente → false
 * - buscarCancion en lista vacía → false
 * - mostrarCanciones → imprime en orden alfabético
 */
void pruebaCancionesArtista();

/* DISEÑO DE PRUEBAS PARA LA CLASE ARTISTA
 * 1. Prueba de Constructores:
 * - Caso 1: Constructor por defecto. Resultado esperado: Valores nulos o cero.
 * - Caso 2: Constructor parametrizado ("Malu"). Resultado esperado: Asignación correcta.
 * - Caso 3: Constructor por copia. Resultado esperado: Copia exacta del artista y sus atributos.
 * * 2. Prueba de Métodos de Acceso (Getters y Setters):
 * - Caso: Modificar nombre, país y seguidores y verificarlos.
 * - Resultado esperado: Los atributos se modifican correctamente sin fallos de memoria.
 * * 3. Prueba de Resto de Métodos y Operadores:
 * - Caso: Comprobar operadores (== y <) y métodos de canciones si procede.
 * - Resultado esperado: Las comparaciones alfabéticas devuelven el booleano correcto.
 */

#endif /* PRUEBAARTISTA_H_ */
