/*
 * GestorArtistas.cpp
 *
 *  Created on: 12 may 2026
 *      Author: bychi
 */

#include "GestorArtistas.h"

#if defined (LISTA_ARTISTAS)

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

#else

GestorArtistas::GestorArtistas() {
	aArtistas = new BSTree<KeyValue<string, Artista*>>();
}

GestorArtistas::GestorArtistas(const GestorArtistas &otroGestor) {
	aArtistas = new BSTree<KeyValue<string, Artista*>>();
	copiarArbol(otroGestor.aArtistas);
}

bool GestorArtistas::buscarRec(BSTree<KeyValue<string, Artista*> > *arbol, string clave, Artista *&a) const {
	if (arbol->estaVacio()) {
		return false;
	}

	KeyValue<string, Artista*> kv = arbol->getDato();
	if (kv.getKey() == clave) {
		a = kv.getValue();
		return true;
	} else if (clave < kv.getKey()) {
		return buscarRec(arbol->getIzq(), clave, a);
	} else {
		return buscarRec(arbol->getDer(), clave, a);
	}
}

void GestorArtistas::mostrarRec(BSTree<KeyValue<string, Artista*> > *arbol) const {
	if (!arbol->estaVacio()) {
		mostrarRec(arbol->getIzq());
		arbol->getDato().getValue()->mostrar();
		mostrarRec(arbol->getDer());
	}
}

int GestorArtistas::numElementosRec(BSTree<KeyValue<string, Artista*> > *arbol) const {
	if (arbol->estaVacio()) {
		return 0;
	}

	return 1 + numElementosRec(arbol->getIzq()) + numElementosRec(arbol->getDer());
}

int GestorArtistas::profundidadRec(BSTree<KeyValue<string, Artista*> > *arbol) const {
	if (arbol->estaVacio()) {
		return 0;
	}
	int profundidadIzq = profundidadRec(arbol->getIzq());
	int profundidadDer = profundidadRec(arbol->getDer());

	if (profundidadIzq > profundidadDer) {
		return 1 + profundidadIzq;
	} else {
		return 1 + profundidadDer;
	}
}

void GestorArtistas::vaciarRec(BSTree<KeyValue<string, Artista*> > *arbol) {
	if (!arbol->estaVacio()) {
		vaciarRec(arbol->getIzq());
		vaciarRec(arbol->getDer());
		delete arbol->getDato().getValue();
	}
}

void GestorArtistas::masSeguidoresRec(BSTree<KeyValue<string, Artista*> > *arbol, Artista *&maxArtista, int &maxSeguidores) const {
	if (!arbol->estaVacio()) {
		masSeguidoresRec (arbol->getIzq(), maxArtista, maxSeguidores);

		Artista *aActual = arbol->getDato().getValue();
		if (aActual->getNumSeg() > maxSeguidores) {
			maxSeguidores = aActual->getNumSeg();
			maxArtista = aActual;
		}

		masSeguidoresRec (arbol->getDer(), maxArtista, maxSeguidores);
	}
}



void GestorArtistas::insertar(string nombre, string pais, int numSeguidores) {
	Artista *aNuevo = new Artista (nombre, pais, numSeguidores);
	KeyValue<string, Artista*> kv (nombre, aNuevo);

	if (!aArtistas->existe(kv)) {
		aArtistas->insertar(kv);
	} else {
		delete aNuevo;
	}
}

bool GestorArtistas::buscar(string nombre, Artista *&a) const {
	return buscarRec (aArtistas, nombre, a);
}

int GestorArtistas::numElementos() const {
	return numElementosRec(aArtistas);
}

void GestorArtistas::mostrar() const {
	mostrarRec(aArtistas);
	cout << "\nProfundidad del árbol de artistas: " << profundidadRec (aArtistas) << endl;
}

void GestorArtistas::mostrarMasSeguidores() const {
	Artista *maxArtista = nullptr;
	int maxSeguidores = -1;

	masSeguidoresRec(aArtistas, maxArtista, maxSeguidores);

	if (maxArtista != nullptr) {
		cout << "El artista con más seguidores es: " << endl;
		maxArtista->mostrar();
	} else {
		cout << "No hay artistas en el sistema." << endl;
	}
}

void GestorArtistas::copiarArbol(BSTree<KeyValue<string, Artista*> > *otroArbol) {
	if (!otroArbol->estaVacio()) {
		KeyValue<string, Artista*> kv = otroArbol->getDato();
		Artista *aCopia = new Artista(*kv.getValue());
		aArtistas->insertar(KeyValue<string, Artista*>(kv.getKey(), aCopia));
		copiarArbol(otroArbol->getIzq());
		copiarArbol(otroArbol->getDer());
	}
}

GestorArtistas::~GestorArtistas() {
	vaciarRec(aArtistas);
	delete aArtistas;
}

#endif /* defined*/

