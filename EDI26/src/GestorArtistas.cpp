/*
 * GestorArtistas.cpp
 *
 *  Created on: 12 may 2026
 *      Author: bychi
 */

#include "GestorArtistas.h"

GestorArtistas::GestorArtistas() {
	lArtistas = new ListaDPI <Artista*> ();
}

GestorArtistas::GestorArtistas(const GestorArtistas &otroGestorArtistas) {
	Artista *a = nullptr;
	lArtistas = new ListaDPI <Artista*> ();
	lArtistas->moverPrimero();
	otroGestorArtistas.lArtistas->moverPrimero();
	while (!otroGestorArtistas.lArtistas->alFinal()) {
		a = otroGestorArtistas.lArtistas->consultar();
		Artista *aNuevo = new Artista (*a);
		lArtistas->insertar(aNuevo);
		otroGestorArtistas.lArtistas->avanzar();
	}
}

void GestorArtistas::insertar(string nombre, string pais, int numSeguidores) {
	Artista *a;
	bool encontrado = false;
	bool igual = false;
	lArtistas->moverPrimero();
	while (!lArtistas->alFinal() && !encontrado && !igual) {
		lArtistas->consultar(a);
		if (a->getNombre() == nombre) {
			igual = true;
		} else if (a->getNombre() > nombre) {
			encontrado = true;
		} else {
			lArtistas->avanzar();
		}
	}
	if (!igual) {
		a = new Artista (nombre, pais, numSeguidores);
		lArtistas->insertar(a);
	}
}

bool GestorArtistas::buscar(string nombre, Artista *&a) const {
	bool enc = false;
	lArtistas->moverPrimero();
	while (!lArtistas->alFinal() && !enc) {
		if (lArtistas->consultar()->getNombre() == nombre) {
			a = lArtistas->consultar();
			cout << "El siguiente artista ha sido encontrado: " << endl;
			a->mostrar();
			enc = true;
		}
		else {
			lArtistas->avanzar();
		}
	}
	return enc;
}

int GestorArtistas::numElementos() const {
	int cont = 0;
	lArtistas->moverPrimero();
	while (!lArtistas->alFinal()) {
		cont++;
		lArtistas->avanzar();
	}
	return cont;
}

void GestorArtistas::mostrar() const {
	lArtistas->moverPrimero();
	while (!lArtistas->alFinal()) {
		lArtistas->consultar()->mostrar();
		lArtistas->avanzar();
	}
}

GestorArtistas::~GestorArtistas() {
	lArtistas->moverPrimero();
	while (!lArtistas->alFinal()) {
		delete lArtistas->consultar();
		lArtistas->eliminar();
	}
	delete lArtistas;
}

void GestorArtistas::mostrarMasSeguidores() const {
	if (lArtistas->estaVacia()) {
		cout << "No hay artistas cargados en el sistema." << endl;
		return;
	}

	Artista *maxArtista = nullptr;
	int maxSeguidores = -1;

	lArtistas->moverPrimero();
	while (!lArtistas->alFinal()) {
		Artista *a = lArtistas->consultar();

		if (a->getNumSeg() > maxSeguidores) {
			maxSeguidores = a->getNumSeg();
			maxArtista = a;
		}
		lArtistas->avanzar();
	}

	if (maxArtista != nullptr) {
		cout << "El artista con más seguidores es: " << endl;
		maxArtista->mostrar();
	}

}
