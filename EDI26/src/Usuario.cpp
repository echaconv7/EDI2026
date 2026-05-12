/*
 * Usuario.cpp
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */

#include "Usuario.h"

Usuario::Usuario(){
	idUsuario = " ";
	apellidosNombre = " ";
	email = " ";
	password = " ";
	fechaNacimiento = new Fecha ();
}

Usuario::Usuario (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int ano){
	this->idUsuario= idUsuario;
	this->apellidosNombre=apellidosNombre;
	this->email=email;
	this->password=password;
	fechaNacimiento = new Fecha(dia, mes, ano);
}

Usuario::Usuario (const Usuario &otroUsuario){
	idUsuario=otroUsuario.idUsuario;
	apellidosNombre = otroUsuario.apellidosNombre;
	email=otroUsuario.email;
	password=otroUsuario.password;
	fechaNacimiento=new Fecha(*otroUsuario.fechaNacimiento);

}

void Usuario::setIdUsuario (string idUsuario){
	this->idUsuario= idUsuario;
}

void Usuario::setApellidosNombre (string apellidosNombre){
	this->apellidosNombre= apellidosNombre;
}

void Usuario::setEmail (string email){
	this->email= email;
}

void Usuario::setPassword (string password){
	this->password= password;
}


string Usuario::getIdUsuario() const{
	return idUsuario;
}

string Usuario::getApellidosNombre() const {
	return apellidosNombre;
}

string Usuario::getEmail() const {
	return email;
}

string Usuario::getPassword() const {
	return password;
}


void Usuario::mostrar () const {
	cout << idUsuario << " ";
	cout << apellidosNombre << " ";
	cout << email << " ";
	cout << password << " ";
	fechaNacimiento->mostrarFecha();
}

string Usuario::pasarACadena () const {
	string cadena;
	cadena= idUsuario + " " + apellidosNombre + " " + email + " " + password + " " ;
	return cadena;
}

Usuario::~Usuario(){

}



