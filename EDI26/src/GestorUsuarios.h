/*
 * GestorUsuarios.h
 *
 *  Created on: 16 mar 2026
 *      Author: Marcos
 */

#ifndef GESTORUSUARIOS_H_
#define GESTORUSUARIOS_H_

#include "Usuario.h"
#include "ListaDPI.h"

class GestorUsuarios {
private:
	ListaDPI <Usuario*> *lUsuarios;
public:
	//constructor por defecto
	GestorUsuarios();
	//constructor por copia
	GestorUsuarios(const GestorUsuarios &otroGestorUsuarios);

	//otros métodos
	void insertar (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int year);
	bool buscar (string apellidosNombre, Usuario *&u) const;
	int numElementos () const;
	void mostrar () const;

	//destructor
	~GestorUsuarios();
};

#endif /* GESTORUSUARIOS_H_ */
