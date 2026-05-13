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

	// PRE: El archivo usuarios.csv debe existir y tener un formato válido.
	// DESC: Lee el archivo CSV, e inserta los datos en el GestorUsuarios.
	// COMPLEJIDAD: O(n * log n) usando árbol / O(n^2) usando lista.
	void cargarUsuarios();

	// PRE: El archivo artistas.csv debe existir y tener un formato válido.
	// DESC: Lee el archivo CSV, e inserta los datos en el GestorArtistas.
	// COMPLEJIDAD: O(n * log n) usando árbol / O(n^2) usando lista.
	void cargarArtistas();

	// PRE: El archivo canciones.csv debe existir y tener un formato válido.
	// DESC: Lee el CSV y asigna cada canción al artista correspondiente buscándolo en el gestor.
	// COMPLEJIDAD: O(n * log m) siendo n las canciones y m los artistas (caso árbol).
	void cargarCanciones();

	// PRE: El archivo playList.csv debe existir y tener un formato válido.
	// DESC: Lee el CSV, crea playlists para los usuarios y les asigna sus canciones.
	// COMPLEJIDAD: O(n * log m) siendo n lineas y m el tamaño de usuarios/artistas.
	void cargarPlaylist();

public:

	// PRE: ---
	// DESC: Constructor por defecto. Inicializa los gestores y carga todos los datos de los CSV.
	// COMPLEJIDAD: O(Carga Ficheros)
	Sistema();

	// PRE: ---
	// DESC: Constructor parametrizado. Asigna un nombre al sistema e inicializa y carga los datos.
	// COMPLEJIDAD: O(Carga Ficheros)
	Sistema (string nombreSistema);

	// PRE: ---
	// DESC: Imprime por consola todos los usuarios registrados en el sistema y el total.
	// COMPLEJIDAD: O(n)
	void mostrarUsuarios();

	// PRE: ---
	// DESC: Busca un usuario por apellidos y nombre e imprime sus datos si lo encuentra.
	// COMPLEJIDAD: O(log n) usando árboles, O(n) usando listas.
	void buscarUsuario (string apellidosNombre);

	// PRE: ---
	// DESC: Imprime por consola todos los artistas registrados en el sistema y el total.
	// COMPLEJIDAD: O(n)
	void mostrarArtistas();

	// PRE: ---
	// DESC: Busca un artista por su nombre e imprime sus datos si lo encuentra.
	// COMPLEJIDAD: O(log n) usando árboles, O(n) usando listas.
	void buscarArtistas (string nombre);

	// PRE: ---
	// DESC: Busca un usuario y una de sus playlists y muestra sus canciones por consola.
	// COMPLEJIDAD: O(log u + p) donde u son usuarios y p las playlists del usuario.
	void reproducirPlaylist(string apellidosNombre, string nombrePlaylist);

	// PRE: ---
	// DESC: Busca un emisor y un receptor. Realiza una copia de la playlist del emisor y se la asigna al receptor.
	// COMPLEJIDAD: O(log u + p) siendo u el total de usuarios y p la búsqueda de la playlist.
	void compartirPlaylist(string emisor, string nombrePlaylist, string receptor);

	// PRE: ---
	// DESC: Busca un usuario y elimina una playlist específica de su lista.
	// COMPLEJIDAD: O(log u + p)
	void eliminarPlaylist(string apellidosNombre, string nombrePlaylist);

	// PRE: ---
	// DESC: Vincula un artista como favorito de un usuario y aumenta en 1 los seguidores del artista.
	// COMPLEJIDAD: O(log u + log a) siendo u usuarios y a artistas.
	void anadirArtistaFavorito (string apellidosNombre, string nombreArtista);

	// PRE: ---
	// DESC: Desvincula un artista favorito de un usuario y resta 1 a los seguidores del artista.
	// COMPLEJIDAD: O(log u + log a)
	void eliminarArtistaFavorito (string apellidosNombre, string nombreArtista);

	// PRE: ---
	// DESC: Busca en el gestor de artistas cuál es el que tiene más seguidores y lo muestra.
	// COMPLEJIDAD: O(n)
	void mostrarArtistaMasSeguidores();

	// PRE: ---
	// DESC: Destructor. Libera la memoria de los dos gestores (usuarios y artistas).
	// COMPLEJIDAD: O(u + a) donde u son usuarios y a artistas.
	~Sistema();
};

#endif /* SISTEMA_H_ */
