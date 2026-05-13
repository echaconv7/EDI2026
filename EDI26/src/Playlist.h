/*
 * Playlist.h
 *
 *  Created on: 15 mar 2026
 *      Author: elena
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include "Cola.h"
#include "Cancion.h"
using namespace std;

class Playlist {
private:
	string nombre;
	int numCanciones;
	int totalDuracion;
	Cola <Cancion*> *colaReproduccion;
public:

	// PRE: ---
	// DESC: Constructor por defecto. Inicializa los atributos a cero y crea la cola vacía.
	// COMPLEJIDAD: O(1)
	Playlist();

	// PRE: ---
	// DESC: Constructor parametrizado. Asigna el nombre, inicializa contadores y crea la cola vacía.
	// COMPLEJIDAD: O(1)
	Playlist (string nombre);

	// PRE: otraPlaylist debe estar correctamente inicializada.
	// DESC: Constructor por copia. Realiza una copia de la estructura de la cola.
	// COMPLEJIDAD: O(n) donde n es el número de canciones en la cola.
	Playlist (const Playlist &otraPlaylist);


	// PRE: ---
	// DESC: Modifica el nombre de la playlist.
	// COMPLEJIDAD: O(1)
	void setNombre (string nombre);

	// PRE: numCanciones >= 0
	// DESC: Modifica el contador de canciones de la playlist.
	// COMPLEJIDAD: O(1)
	void setNumCanciones (int numCanciones);

	// PRE: totalDuracion >= 0
	// DESC: Modifica el tiempo total de duración de la playlist.
	// COMPLEJIDAD: O(1)
	void setTotalDuracion (int totalDuracion);


	// PRE: ---
	// DESC: Devuelve el nombre de la playlist.
	// COMPLEJIDAD: O(1)
	string getNombre() const;

	// PRE: ---
	// DESC: Devuelve el número de canciones que contiene la playlist.
	// COMPLEJIDAD: O(1)
	int getNumCanciones () const;

	// PRE: ---
	// DESC: Devuelve la duración total (en segundos) de la playlist.
	// COMPLEJIDAD: O(1)
	int getTotalDuracion ()const;


	// PRE: cancion debe ser un puntero válido a un objeto Cancion.
	// DESC: Inserta una canción al final de la cola de reproducción y actualiza estadísticas.
	// COMPLEJIDAD: O(1)
	void agregarCancion (Cancion *cancion);

	// PRE: La cola no debe estar vacía.
	// DESC: Elimina la canción que se encuentra al frente de la cola de reproducción.
	// COMPLEJIDAD: O(1)
	void eliminarCancion ();

	// PRE: ---
	// DESC: Muestra por consola los datos de la playlist y el listado de sus canciones.
	// COMPLEJIDAD: O(n)
	void mostrar ();

	// PRE: ---
	// DESC: Recorre la cola simulando la reproducción de todas las canciones.
	// COMPLEJIDAD: O(n)
	void reproducirTodo();

	// PRE: numEnLista debe ser un índice válido dentro del rango de la cola.
	// DESC: Reproduce una cantidad específica de canciones de la cola o una posición concreta.
	// COMPLEJIDAD: O(n)
	void repUnNumCancion(int numEnLista);


	// PRE: ---
	// DESC: Destructor. Libera la memoria dinámica ocupada por la cola de reproducción.
	// COMPLEJIDAD: O(n)
	~Playlist ();


};



#endif /* PLAYLIST_H_ */
