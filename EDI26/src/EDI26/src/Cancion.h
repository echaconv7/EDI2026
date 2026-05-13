/*
 * Cancion.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef CANCION_H_
#define CANCION_H_

#include <iostream>
using namespace std;

class Cancion{
private:
	string titulo;
	string genero;
	int duracion;
public:

	// PRE: ---
	// DESC: Constructor por defecto. Inicializa los atributos a valores vacíos o cero.
	// COMPLEJIDAD: O(1)
	Cancion();

	// PRE: ---
	// DESC: Constructor parametrizado. Asigna el título, género y duración recibidos.
	// COMPLEJIDAD: O(1)
	Cancion(string titulo, string genero, int duracion);

	// PRE: otraCancion debe estar correctamente inicializada.
	// DESC: Constructor por copia.
	// COMPLEJIDAD: O(1)
	Cancion (const Cancion &otraCancion);


	// PRE: ---
	// DESC: Modifica el título de la canción.
	// COMPLEJIDAD: O(1)
	void setTitulo (string titulo);

	// PRE: ---
	// DESC: Modifica el género de la canción.
	// COMPLEJIDAD: O(1)
	void setGenero (string genero);

	// PRE: duracion >= 0.
	// DESC: Modifica la duración de la canción en segundos.
	// COMPLEJIDAD: O(1)
	void setDuracion (int duracion);


	// PRE: ---
	// DESC: Devuelve el título de la canción.
	// COMPLEJIDAD: O(1)
	string getTitulo () const;

	// PRE: ---
	// DESC: Devuelve el género de la canción.
	// COMPLEJIDAD: O(1)
	string getGenero () const;

	// PRE: ---
	// DESC: Devuelve la duración de la canción.
	// COMPLEJIDAD: O(1)
	int getDuracion () const;


	// PRE: ---
	// DESC: Muestra por consola los datos de la canción (título, género y duración).
	// COMPLEJIDAD: O(1)
	void mostrar() const;


	// PRE: otraCancion debe estar inicializada.
	// DESC: Compara si dos canciones son iguales basándose en su título.
	// COMPLEJIDAD: O(1)
	bool operator == (const Cancion &otraCancion) const;

	// PRE: otraCancion debe estar inicializada.
	// DESC: Compara si una canción es "menor" que otra alfabéticamente por su título.
	// COMPLEJIDAD: O(1)
	bool operator < (const Cancion &otraCancion) const;


	// PRE: ---
	// DESC: Destructor.
	// COMPLEJIDAD: O(1)
	~Cancion();
};



#endif /* CANCION_H_ */
