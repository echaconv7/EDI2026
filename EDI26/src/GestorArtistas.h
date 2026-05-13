/*
 * GestorArtistas.h
 *
 *  Created on: 12 may 2026
 *      Author: bychi
 */

#ifndef GESTORARTISTAS_H_
#define GESTORARTISTAS_H_

#include "Artista.h"
#include "ListaDPI.h"

class GestorArtistas {
private:

	ListaDPI<Artista*> *lArtistas;

public:
	GestorArtistas();
	GestorArtistas(const GestorArtistas &otroGestorArtistas);

	void insertar (string nombre, string pais, int numSeguidores);
	bool buscar (string nombre, Artista *&a) const;
	int numElementos () const;
	void mostrar () const;
	void mostrarMasSeguidores() const;

	~GestorArtistas();
};
#endif /* GESTORARTISTAS_H_ */

