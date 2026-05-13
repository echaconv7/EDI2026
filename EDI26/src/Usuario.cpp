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
	lPlaylists = new ListaDPI<Playlist*>();
	lArtistasFavoritos = new ListaDPI<Artista*>();
}

Usuario::Usuario (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int ano){
	this->idUsuario= idUsuario;
	this->apellidosNombre=apellidosNombre;
	this->email=email;
	this->password=password;
	fechaNacimiento = new Fecha(dia, mes, ano);
	lPlaylists = new ListaDPI<Playlist*>();
	lArtistasFavoritos = new ListaDPI<Artista*>();
}

Usuario::Usuario (const Usuario &otroUsuario){
	idUsuario=otroUsuario.idUsuario;
	apellidosNombre = otroUsuario.apellidosNombre;
	email=otroUsuario.email;
	password=otroUsuario.password;
	fechaNacimiento=new Fecha(*otroUsuario.fechaNacimiento);

	lPlaylists = new ListaDPI<Playlist*>();
	otroUsuario.lPlaylists->moverPrimero();
	while (!otroUsuario.lPlaylists->alFinal()) {
		Playlist *p = otroUsuario.lPlaylists->consultar();
		lPlaylists->insertar(new Playlist(*p));
		otroUsuario.lPlaylists->avanzar();
	}

	lArtistasFavoritos = new ListaDPI<Artista*>();
	otroUsuario.lArtistasFavoritos->moverPrimero();
	while (!otroUsuario.lArtistasFavoritos->alFinal()) {
		Artista *a = otroUsuario.lArtistasFavoritos->consultar();
		lArtistasFavoritos->insertar(a);
		otroUsuario.lArtistasFavoritos->avanzar();
	}
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

void Usuario::crearPlayList(string nombre) {
	bool enc = false;
	lPlaylists->moverPrimero();

	while (!lPlaylists->alFinal() && !enc) {
		if (lPlaylists->consultar()->getNombre() == nombre) {
			enc = true;
		}
		lPlaylists->avanzar();
	}

	if (!enc) {
		Playlist *pNueva = new Playlist(nombre);
		lPlaylists->insertar(pNueva);
	}
}

void Usuario::anadirCancionAPlayList(string nombrePlaylist, Cancion *c) {
	bool enc = false;
	lPlaylists->moverPrimero();

	while (!lPlaylists->alFinal() && !enc) {
		if (lPlaylists->consultar()->getNombre() == nombrePlaylist) {
			lPlaylists->consultar()->agregarCancion(c);
			enc = true;
		}
		lPlaylists->avanzar();
	}
}

void Usuario::reproducirPlayList() {
	lPlaylists->moverPrimero();
	while (!lPlaylists->alFinal()) {
		lPlaylists->consultar()->reproducirTodo();
		lPlaylists->avanzar();
	}
}

Playlist* Usuario::compartirPlayList(string nombrePlaylist) {
	Playlist *copia = nullptr;
	bool enc = false;
	lPlaylists->moverPrimero();

	while (!lPlaylists->alFinal() && !enc) {
		if (lPlaylists->consultar()->getNombre() == nombrePlaylist) {
			copia = new Playlist(*(lPlaylists->consultar()));
			enc = true;
		}
		lPlaylists->avanzar();
	}

	return copia;
}

void Usuario::anadirPlayListCompartida(Playlist *p) {
	if (p != nullptr) {
		lPlaylists->insertar(p);
	}
}

void Usuario::insertarArtistaFavorito(Artista *a) {
	bool enc = false;
	lArtistasFavoritos->moverPrimero();

	while (!lArtistasFavoritos->alFinal() && !enc) {
		if (lArtistasFavoritos->consultar()->getNombre() == a->getNombre()) {
			enc = true;
		}
		lArtistasFavoritos->avanzar();
	}

	if (!enc) {
		lArtistasFavoritos->insertar(a);
	}
}

void Usuario::eliminarArtistaFavorito(string nombreArtista) {
	bool enc = false;
	lArtistasFavoritos->moverPrimero();

	while(!lArtistasFavoritos->alFinal() && !enc) {
		if (lArtistasFavoritos->consultar()->getNombre() == nombreArtista) {
			lArtistasFavoritos->eliminar();
			enc = true;
		} else {
			lArtistasFavoritos->avanzar();
		}
	}
}

void Usuario::mostrarFavoritos() {
	lArtistasFavoritos->moverPrimero();
	while (!lArtistasFavoritos->alFinal()) {
		lArtistasFavoritos->consultar()->mostrar();
		lArtistasFavoritos->avanzar();
	}
}

void Usuario::eliminarPlayList(string nombre) {
	bool enc = false;
	lPlaylists->moverPrimero();

	while (!lPlaylists->alFinal() && !enc) {
		if (lPlaylists->consultar()->getNombre() == nombre) {
			delete lPlaylists->consultar();
			lPlaylists->eliminar();
			enc = true;
		} else {
			lPlaylists->avanzar();
		}
	}
}

Usuario::~Usuario(){
	delete fechaNacimiento;

	lPlaylists->moverPrimero();
	while (!lPlaylists->alFinal()) {
		delete lPlaylists->consultar();
		lPlaylists->eliminar();
	}
	delete lPlaylists;

	delete lArtistasFavoritos;

}
