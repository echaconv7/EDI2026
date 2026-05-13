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
	this->idUsuario=otroUsuario.idUsuario;
	this->apellidosNombre = otroUsuario.apellidosNombre;
	this->email=otroUsuario.email;
	this->password=otroUsuario.password;
	this->fechaNacimiento=new Fecha(*otroUsuario.fechaNacimiento);
	Playlist *p = nullptr;
	Artista *a = nullptr;
	lPlaylists= new ListaDPI<Playlist*>();
	lArtistasFavoritos = new ListaDPI<Artista*>();
	otroUsuario.lPlaylists->moverPrimero();
	otroUsuario.lArtistasFavoritos->moverPrimero();
	while (!otroUsuario.lPlaylists->alFinal()){
			p = otroUsuario.lPlaylists->consultar();
			lPlaylists->insertar(new Playlist(*p));
			otroUsuario.lPlaylists->avanzar();
	}

	while (!otroUsuario.lArtistasFavoritos->alFinal()) {
		a = otroUsuario.lArtistasFavoritos->consultar();
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
	cout << "--------------------------------------------------" << endl;
	cout << "IdUsuario: " << idUsuario << "; ";
	cout << "Nombre: " << apellidosNombre << "; ";
	cout << "Email: " << email << "; ";
	cout << "Contraseña: " << password << "; " << endl;
	cout << "Fecha de nacimiento: ";
	fechaNacimiento->mostrarFecha();

	cout << "PlayLists: " << endl;
	lPlaylists->moverPrimero();
	while (!lPlaylists->alFinal()) {
		lPlaylists->consultar()->mostrar();
		lPlaylists->avanzar();
	}

	cout << "Artistas favoritos: " << endl;
	lArtistasFavoritos->moverPrimero();
	while (!lArtistasFavoritos->alFinal()) {
		lArtistasFavoritos->consultar()->mostrar();
		lArtistasFavoritos->avanzar();
	}
}

string Usuario::pasarACadena () const {
	string cadena;
	cadena= idUsuario + " " + apellidosNombre + " " + email + " " + password + " "
			+ to_string(fechaNacimiento->getDia()) + "/"
			+ to_string(fechaNacimiento->getMes()) + "/"
			+ to_string(fechaNacimiento->getAno());
	return cadena;
}

void Usuario::crearPlayList(string nombre) {
	bool enc = false;
	lPlaylists->moverPrimero();

	while (!lPlaylists->alFinal() && !enc) {
		if (lPlaylists->consultar()->getNombre() == nombre) {
			enc = true;
		} else {
			lPlaylists->avanzar();
		}
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
		} else {
			lPlaylists->avanzar();
		}
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
		} else {
			lPlaylists->avanzar();
		}
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
		} else {
			lArtistasFavoritos->avanzar();
		}
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

bool Usuario::esArtistaFavorito(string nombreArtista) const {
	lArtistasFavoritos->moverPrimero();
	while (!lArtistasFavoritos->alFinal()) {
		if (lArtistasFavoritos->consultar()->getNombre() == nombreArtista)
			return true;
		lArtistasFavoritos->avanzar();
	}
	return false;
}

void Usuario::reproducirPlayListPorNombre(string nombrePlaylist) {
	bool enc = false;
	lPlaylists->moverPrimero();
	while (!lPlaylists->alFinal() && !enc) {
		if (lPlaylists->consultar()->getNombre() == nombrePlaylist) {
			lPlaylists->consultar()->reproducirTodo();
			enc = true;
		} else {
			lPlaylists->avanzar();
		}
	}
	if (!enc) {
		cout << "No se ha podido encontrar la PlayList." << endl;
	}
}

Usuario::~Usuario(){
	delete fechaNacimiento;

	lPlaylists->moverPrimero();
	Playlist *p= nullptr;
	while (!lPlaylists->estaVacia()) {
		p = lPlaylists->consultar();
		delete p;
		lPlaylists->eliminar();
	}
	delete lPlaylists;
	lArtistasFavoritos->moverPrimero();
	while (!lArtistasFavoritos->estaVacia()){
		lArtistasFavoritos->eliminar();
	}
	delete lArtistasFavoritos;

}


