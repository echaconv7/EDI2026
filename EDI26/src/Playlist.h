/*
 * Playlist.h
 *
 *  Created on: 15 mar 2026
 *      Author: elena
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
#include "Cola.h"
#include "Cancion.h"
using namespace std;

class Playlist {
private:
	string nombre;
	int numCanciones;
	int totalDuracion;
	Cola <Cancion*> *colaReproduccion;
public:
	Playlist();
	Playlist (string nombre);
	Playlist (const Playlist &otraPlaylist);

	void setNombre (string nombre);
	void setNumCanciones (int numCanciones);
	void setTotalDuracion (int totalDuracion);

	string getNombre() const;
	int getNumCanciones () const;
	int getTotalDuracion ()const;

	void agregarCancion (Cancion *cancion);
	void eliminarCancion ();
	void mostrar ();
	void reproducirTodo();
	void repUnNumCancion(int numEnLista);

	~Playlist ();


};



#endif /* PLAYLIST_H_ */
