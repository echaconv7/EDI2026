/*
 * Artista.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef ARTISTA_H_
#define ARTISTA_H_
#include <iostream>

#include "Cancion.h"
#include "ListaDPI.h"

using namespace std;

class Artista {
private:
	string nombre;
	string pais;
	int numSeg;
	ListaDPI <Cancion*> *lCanciones;
public:

	// PRE: ---
	// DESC: Constructor por defecto.
	// COMPLEJIDAD: O(1)
	Artista();

	// PRE: ---
	// DESC: Constructor parametrizado. Asigna datos y crea la lista de canciones vacía.
	// COMPLEJIDAD: O(1)
	Artista(string nombre, string pais, int numSeg);

	// PRE: otroArtista debe estar correctamente inicializado.
	// DESC: Constructor por copia. Realiza copia de las canciones.
	// COMPLEJIDAD: O(c) donde c son las canciones del artista.
	Artista (const Artista &otroArtista);

	// PRE: ---
	// DESC: Modifica el nombre..
	// COMPLEJIDAD: O(1)
	void setNombre (string nombre);

	// PRE: ---
	// DESC: Modifica el pais..
	// COMPLEJIDAD: O(1)
	void setPais (string pais);

	// PRE: ---
	// DESC: Modifica el número de seguidores.
	// COMPLEJIDAD: O(1)
	void setNumSeg (int numSeg);

	// PRE: ---
	// DESC: Devuelve el nombre del artista.
	// COMPLEJIDAD: O(1)
	string getNombre () const;

	// PRE: ---
	// DESC: Devuelve el país del artista.
	// COMPLEJIDAD: O(1)
	string getPais () const;

	// PRE: ---
	// DESC: Devuelve el número de seguidores.
	// COMPLEJIDAD: O(1)
	int getNumSeg () const;


	// PRE: otroArtista debe estar inicializado.
	// DESC: Compara si dos artistas son iguales basándose en su nombre.
	// COMPLEJIDAD: O(1)
	bool operator == (const Artista &otroArtista) const;

	// PRE: otroArtista debe estar inicializado.
	// DESC: Compara si un artista es "menor" que otro alfabéticamente por su nombre.
	// COMPLEJIDAD: O(1)
	bool operator < (const Artista &otroArtista) const;


	// PRE: ---
	// DESC: Muestra por consola los datos básicos del artista y su lista de canciones.
	// COMPLEJIDAD: O(c) donde c es el número de canciones.
	void mostrar() const;


	//metodos listaCanciones:

	// PRE: ---
	// DESC: Devuelve el número de canciones que tiene el artista en su lista.
	// COMPLEJIDAD: O(c)
	int numElementos () const;

	// PRE: ---
	// DESC: Muestra por pantalla únicamente los títulos de las canciones del artista.
	// COMPLEJIDAD: O(c)
	void mostrarCanciones () const;

	// PRE: ---
	// DESC: Busca una canción por su título. Devuelve true y modifica el puntero si la encuentra.
	// COMPLEJIDAD: O(c)
	bool buscarCancion (string titulo, Cancion *&c) const;

	// PRE: ---
	// DESC: Crea una nueva canción y la inserta de forma ordenada en la lista.
	// COMPLEJIDAD: O(c)
	void insertar (string titulo, string genero, int duracion);

	// PRE: ---
	// DESC: Destructor. Libera la memoria de la lista y destruye todas las canciones del artista.
	// COMPLEJIDAD: O(c)
	~Artista();

};



#endif /* ARTISTA_H_ */
