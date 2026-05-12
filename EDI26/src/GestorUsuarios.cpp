/*
 * GestorUsuarios.cpp
 *
 *  Created on: 16 mar 2026
 *      Author: Marcos
 */

#include "GestorUsuarios.h"

GestorUsuarios::GestorUsuarios() {
	lUsuarios = new ListaDPI <Usuario*> ();
}

GestorUsuarios::GestorUsuarios(const GestorUsuarios &otroGestorUsuarios) {
	Usuario *u = nullptr;
	lUsuarios = new ListaDPI <Usuario*> ();
	lUsuarios->moverPrimero();
	otroGestorUsuarios.lUsuarios->moverPrimero();
	while (!otroGestorUsuarios.lUsuarios->alFinal()) {
		u = otroGestorUsuarios.lUsuarios->consultar();
		Usuario *uNuevo = new Usuario (*u);
		lUsuarios->insertar(uNuevo);
		otroGestorUsuarios.lUsuarios->avanzar();
	}
}

void GestorUsuarios::insertar(string idUsuario, string apellidosNombre,
		string email, string password, int dia, int mes, int year) {
	Usuario *u;
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
			cout << "El siguiente usuario ha sido encontrado: " << endl;
			u->mostrar();
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
