/*
 * Usuario.h
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
#include "Fecha.h"
using namespace std;

class Usuario {

private:
	string idUsuario;
	string apellidosNombre;
	string email;
	string password;
	Fecha *fechaNacimiento;

public:
	Usuario ();
	Usuario (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int ano);
	Usuario (const Usuario &otroUsuario);

	void setIdUsuario (string idUsuario);
	void setApellidosNombre (string apellidosNombre);
	void setEmail (string email);
	void setPassword (string password);

	string getIdUsuario () const;
	string getApellidosNombre () const;
	string getEmail () const;
	string getPassword () const;

	void mostrar () const;
	string pasarACadena () const;

	~Usuario ();


};






#endif /* USUARIO_H_ */
