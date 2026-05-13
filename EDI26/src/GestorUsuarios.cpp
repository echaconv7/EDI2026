/*
 * GestorUsuarios.cpp
 *
 *  Created on: 16 mar 2026
 *      Author: Marcos
 */

#include "GestorUsuarios.h"

#if defined (LISTA_USUARIOS)

GestorUsuarios::GestorUsuarios() {
	lUsuarios = new ListaDPI <Usuario*> ();
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios &otroGestorUsuarios) {
	Usuario *u = nullptr;
	lUsuarios = new ListaDPI <Usuario*> ();
	lUsuarios->moverPrimero();
	Usuario *uCopia=nullptr;
	otroGestorUsuarios.lUsuarios->moverPrimero();
	while (!otroGestorUsuarios.lUsuarios->alFinal()) {
		u = otroGestorUsuarios.lUsuarios->consultar();
		uCopia=new Usuario (*u);
		lUsuarios->insertar(uCopia);
		otroGestorUsuarios.lUsuarios->avanzar();
	}
}

void GestorUsuarios::insertar(string idUsuario, string apellidosNombre,
		string email, string password, int dia, int mes, int year) {
	Usuario *u=nullptr;
	bool encontrado = false;
	bool igual = false;
	lUsuarios->moverPrimero();
	while (!lUsuarios->alFinal() && !encontrado && !igual) {
		lUsuarios->consultar(u);
		if (u->getApellidosNombre() == apellidosNombre) {
			igual = true;
		} else if (u->getApellidosNombre() > apellidosNombre) {
			encontrado = true;
		} else {
			lUsuarios->avanzar();
		}
	}
	if (!igual) {
		u = new Usuario (idUsuario, apellidosNombre, email, password, dia, mes, year);
		lUsuarios->insertar(u);
	}

}

bool GestorUsuarios::buscar(string apellidosNombre, Usuario *&u) const {
	bool enc = false;
	lUsuarios->moverPrimero();
	while (!lUsuarios->alFinal() && !enc) {
		if (lUsuarios->consultar()->getApellidosNombre() == apellidosNombre) {
			u = lUsuarios->consultar();
			enc = true;
		}
		else {
			lUsuarios->avanzar();
		}
	}
	return enc;
}

int GestorUsuarios::numElementos() const {
	int cont = 0;
	lUsuarios->moverPrimero();
	while (!lUsuarios->alFinal()) {
		cont++;
		lUsuarios->avanzar();
	}
	return cont;
}

void GestorUsuarios::mostrar() const {
	lUsuarios->moverPrimero();
	while (!lUsuarios->alFinal()) {
		lUsuarios->consultar()->mostrar();
		lUsuarios->avanzar();
	}
}

GestorUsuarios::~GestorUsuarios() {
	lUsuarios->moverPrimero();
	while (!lUsuarios->alFinal()) {
		delete lUsuarios->consultar();
		lUsuarios->eliminar();
	}
	delete lUsuarios;
}

#else

GestorUsuarios::GestorUsuarios() {
	aUsuarios = new BSTree<KeyValue<string, Usuario*>>();
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios &otroGestor) {
	aUsuarios = new BSTree<KeyValue<string, Usuario*>>();
	copiarArbol(otroGestor.aUsuarios);
}

bool GestorUsuarios::buscarRec(BSTree<KeyValue<string, Usuario*> > *arbol, string clave, Usuario *&u) const {
	if (arbol->estaVacio()) {
		return false;
	}

	KeyValue<string, Usuario*> kv = arbol->getDato();
	if (kv.getKey() == clave) {
		u = kv.getValue();
		return true;
	} else if (clave < kv.getKey()) {
		return buscarRec(arbol->getIzq(), clave, u);
	} else {
		return buscarRec(arbol->getDer(), clave, u);
	}
}

void GestorUsuarios::mostrarRec(BSTree<KeyValue<string, Usuario*> > *arbol) const {
	if (!arbol->estaVacio()) {
		mostrarRec(arbol->getIzq());
		arbol->getDato().getValue()->mostrar();
		mostrarRec(arbol->getDer());
	}
}

int GestorUsuarios::numElementosRec(BSTree<KeyValue<string, Usuario*> > *arbol) const {
	if (arbol->estaVacio()) {
		return 0;
	}
	return 1 + numElementosRec(arbol->getIzq()) + numElementosRec(arbol->getDer());
}

int GestorUsuarios::profundidadRec(BSTree<KeyValue<string, Usuario*> > *arbol) const {
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

void GestorUsuarios::vaciarRec(BSTree<KeyValue<string, Usuario*> > *arbol) {
	if (!arbol->estaVacio()) {
		vaciarRec(arbol->getIzq());
		vaciarRec(arbol->getDer());
		delete arbol->getDato().getValue();
	}
}



void GestorUsuarios::insertar(string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int year) {
	Usuario *uNuevo = new Usuario (idUsuario, apellidosNombre, email, password, dia, mes, year);
	KeyValue<string, Usuario*> kv (apellidosNombre, uNuevo);

	if (!aUsuarios->existe(kv)) {
		aUsuarios->insertar(kv);
	} else {
		delete uNuevo;
	}
}

bool GestorUsuarios::buscar(string apellidosNombre, Usuario *&u) const {
	return buscarRec(aUsuarios, apellidosNombre, u);
}

int GestorUsuarios::numElementos() const {
	return numElementosRec (aUsuarios);
}

void GestorUsuarios::mostrar() const {
	mostrarRec(aUsuarios);
	cout << "Profundidad del árbol de usuarios: " << profundidadRec(aUsuarios) << endl;
}

void GestorUsuarios::copiarArbol(BSTree<KeyValue<string, Usuario*> > *otroArbol) {
	if (!otroArbol->estaVacio()) {
			KeyValue<string, Usuario*> kv = otroArbol->getDato();
			Usuario *uCopia = new Usuario(*kv.getValue());
			aUsuarios->insertar(KeyValue<string, Usuario*>(kv.getKey(), uCopia));
			copiarArbol(otroArbol->getIzq());
			copiarArbol(otroArbol->getDer());
		}
}

GestorUsuarios::~GestorUsuarios() {
	vaciarRec(aUsuarios);
	delete aUsuarios;
}

#endif /* defined*/


