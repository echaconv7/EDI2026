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
#include "PlayList.h"
#include "Artista.h"
#include "ListaDPI.h"

using namespace std;

class Usuario {

private:
	string idUsuario;
	string apellidosNombre;
	string email;
	string password;
	Fecha *fechaNacimiento;

	ListaDPI<Playlist*> *lPlaylists;
	ListaDPI<Artista*> *lArtistasFavoritos;

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

	void crearPlayList (string nombre);
	void anadirCancionAPlayList (string nombrePlaylist, Cancion *c);
	void reproducirPlayList();
	Playlist* compartirPlayList(string nombrePlaylist);
	void anadirPlayListCompartida(Playlist *p);
	void eliminarPlayList(string nombre);

	void insertarArtistaFavorito(Artista *a);
	void eliminarArtistaFavorito(string nombreArtista);
	void mostrarFavoritos();


	~Usuario ();


};






#endif /* USUARIO_H_ */
