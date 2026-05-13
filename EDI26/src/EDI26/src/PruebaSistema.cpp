/*
 * PruebaSistema.cpp
 *
 *  Created on: 13 may 2026
 *      Author: Marcos
 */

#include "PruebaSistema.h"


void pruebaConstructoresYBusquedas() {
	Sistema *sistema = new Sistema("Spotify Pruebas");

	cout << "\n--- 1. Prueba de Mostrar Usuarios y Artistas ---" << endl;
	sistema->mostrarUsuarios();
	sistema->mostrarArtistas();

	cout << "\n--- 2. Prueba de Busqueda de Usuario ---" << endl;
	cout << " Buscando a un usuario que deberia existir (Dominguez Fernandez, Emiliano):" << endl;
	sistema->buscarUsuario("Dominguez Fernandez, Emiliano");

	cout << "\n Buscando a un usuario inexistente:" << endl;
	sistema->buscarUsuario("Falso, Usuario Inventado");

	cout << "\n--- 3. Prueba de Busqueda de Artista ---" << endl;
	cout << "> Buscando artista que deberia existir (Rosalía):" << endl;
	sistema->buscarArtistas("Rosalía");

	cout << "\n> Buscando artista inexistente:" << endl;
	sistema->buscarArtistas("Artista Falso Inventado");

	delete sistema;
}

void pruebaPlaylistsYFavoritos() {
	Sistema *sistema = new Sistema("Spotify Pruebas 2");
	cout << "\n--- 1. Prueba de Anadir Favorito y Mas Seguidores ---" << endl;
	// hacemos que un par de ususarios sigan a un artista
	sistema->anadirArtistaFavorito("Alcobendas Santos, Jaime", "Coldplay");
	sistema->anadirArtistaFavorito("Madruga Maraver, Angel", "Coldplay");
	sistema->mostrarArtistaMasSeguidores();

	cout << "\n--- 2. Prueba de Reproducir y Compartir Playlist ---" << endl;
	cout << "\n> Reproduciendo playlist original 'Zona estudio' de Jaime Alcobendas:" << endl;
	sistema->reproducirPlaylist("Alcobendas Santos, Jaime", "Zona estudio");

	cout << "\n> Jaime comparte 'Zona estudio' con Angel Madruga:" << endl;
	sistema->compartirPlaylist("Alcobendas Santos, Jaime", "Zona estudio", "Madruga Maraver, Angel");

	cout << "\n> Reproduciendo la playlist copiada en Angel Madruga:" << endl;
	sistema->reproducirPlaylist("Madruga Maraver, Angel", "Zona estudio");

	cout << "\n--- 3. Prueba de Eliminar Playlist ---" << endl;
	sistema->eliminarPlaylist("Madruga Maraver, Angel", "Zona estudio");

	delete sistema;
}

void todasPruebasSistema() {
	pruebaConstructoresYBusquedas();
	pruebaPlaylistsYFavoritos();
}



