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
#include "Playlist.h"
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

	// PRE: ---
	// DESC: Constructor por defecto. Inicializa los atributos en blanco y crea las listas vacías.
	// COMPLEJIDAD: O(1)
	Usuario ();

	// PRE: ---
	// DESC: Constructor parametrizado. Asigna los valores básicos y crea las listas vacías.
	// COMPLEJIDAD: O(1)
	Usuario (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int ano);

	// PRE: otroUsuario debe estar correctamente inicializado.
	// DESC: Constructor por copia. Realiza una copia de listas y fecha.
	// COMPLEJIDAD: O(p + a) donde p son playlists y a son artistas favoritos.
	Usuario (const Usuario &otroUsuario);


	// PRE: ---
	// DESC: Modifica el identificador del usuario.
	// COMPLEJIDAD: O(1)
	void setIdUsuario (string idUsuario);

	// PRE: ---
	// DESC: Modifica los apellidos y nombre del usuario.
	// COMPLEJIDAD: O(1)
	void setApellidosNombre (string apellidosNombre);

	// PRE: ---
	// DESC: Modifica el email del usuario.
	// COMPLEJIDAD: O(1)
	void setEmail (string email);

	// PRE: ---
	// DESC: Modifica la contraseña del usuario.
	// COMPLEJIDAD: O(1)
	void setPassword (string password);


	// PRE: ---
	// DESC: Devuelve el identificador del usuario.
	// COMPLEJIDAD: O(1)
	string getIdUsuario () const;

	// PRE: ---
	// DESC: Devuelve los apellidos y el nombre del usuario.
	// COMPLEJIDAD: O(1)
	string getApellidosNombre () const;

	// PRE: ---
	// DESC: Devuelve el email del usuario.
	// COMPLEJIDAD: O(1)
	string getEmail () const;

	// PRE: ---
	// DESC: Devuelve la contraseña del usuario.
	// COMPLEJIDAD: O(1)
	string getPassword () const;

	// PRE: ---
	// DESC: Muestra por consola los datos del usuario, sus playlists y artistas favoritos.
	// COMPLEJIDAD: O(p + a)
	void mostrar () const;

	// PRE: ---
	// DESC: Devuelve un string con los datos básicos y fecha del usuario.
	// COMPLEJIDAD: O(1)
	string pasarACadena () const;


	// PRE: ---
	// DESC: Crea una nueva playlist vacía con el nombre indicado y la inserta en la lista si no existe.
	// COMPLEJIDAD: O(p) donde p es el número de playlists del usuario.
	void crearPlayList (string nombre);

	// PRE: c debe ser un puntero a Cancion inicializado.
	// DESC: Busca la playlist por su nombre y, si la encuentra, le añade la canción.
	// COMPLEJIDAD: O(p + c) donde p son las playlists y c las canciones de esa playlist.
	void anadirCancionAPlayList (string nombrePlaylist, Cancion *c);

	// PRE: ---
	// DESC: Reproduce secuencialmente todas las canciones de todas las playlists del usuario.
	// COMPLEJIDAD: O(p * c)
	void reproducirPlayList();

	// PRE: ---
	// DESC: Busca una playlist por nombre y devuelve un puntero a una COPIA dinámica de la misma.
	// COMPLEJIDAD: O(p)
	Playlist* compartirPlayList(string nombrePlaylist);

	// PRE: p debe apuntar a una playlist válida en memoria dinámica.
	// DESC: Añade la playlist recibida a la lista de playlists del usuario.
	// COMPLEJIDAD: O(1)
	void anadirPlayListCompartida(Playlist *p);

	// PRE: ---
	// DESC: Busca una playlist por nombre, libera su memoria y la saca de la lista.
	// COMPLEJIDAD: O(p)
	void eliminarPlayList(string nombre);


	// PRE: a debe apuntar a un artista válido.
	// DESC: Añade el puntero del artista a la lista de favoritos si no estaba ya.
	// COMPLEJIDAD: O(a) siendo a el número de favoritos del usuario.
	void insertarArtistaFavorito(Artista *a);

	// PRE: ---
	// DESC: Busca al artista por nombre en la lista de favoritos y lo quita de la lista (no lo destruye).
	// COMPLEJIDAD: O(a)
	void eliminarArtistaFavorito(string nombreArtista);

	// PRE: ---
	// DESC: Muestra por pantalla los datos de todos los artistas favoritos del usuario.
	// COMPLEJIDAD: O(a)
	void mostrarFavoritos();

	// PRE: ---
	// DESC: Reproduce la playlist seleccionada.
	// COMPLEJIDAD: O(p)
	void reproducirPlayListPorNombre(string nombrePlaylist);

	// PRE: ---
	// DESC: Devuelve true si el artista dado ya está como artista favorito.
	// COMPLEJIDAD: O(a)
	bool esArtistaFavorito(string nombreArtista) const;

	// PRE: ---
	// DESC: Destructor. Libera la fecha, vacía la lista de favoritos y destruye todas las playlists.
	// COMPLEJIDAD: O(p + a)
	~Usuario ();

};






#endif /* USUARIO_H_ */
