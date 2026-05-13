/*
 * Sistema.h
 *
 *  Created on: 12 may 2026
 *      Author: Marcos
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <string>
#include <fstream>

#include "GestorUsuarios.h"
#include "GestorArtistas.h"

class Sistema {
private:
	string nombreSistema;
	GestorUsuarios *usuarios;
	GestorArtistas *artistas;

	void cargarUsuarios();
	void cargarArtistas();
	void cargarCanciones();
	void cargarPlaylist();
public:
	Sistema();
	Sistema (string nombreSistema);

	void mostrarUsuarios();
	void buscarUsuario (string apellidosNombre);
	void mostrarArtistas();
	void buscarArtistas (string nombre);
	void reproducirPlaylist(string apellidosNombre, string nombrePlaylist);
	void compartirPlaylist(string emisor, string nombrePlaylist, string receptor);
	void eliminarPlaylist(string apellidosNombre, string nombrePlaylist);
	void anadirArtistaFavorito (string apellidosNombre, string nombreArtista);
	void eliminarArtistaFavorito (string apellidosNombre, string nombreArtista);
	void mostrarArtistaMasSeguidores();


	~Sistema();
};

#endif /* SISTEMA_H_ */
