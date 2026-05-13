/*
 * Artista.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef ARTISTA_H_
#define ARTISTA_H_
#include <iostream>

#include "Cancion.h"
#include "ListaDPI.h"

using namespace std;

class Artista {
private:
	string nombre;
	string pais;
	int numSeg;
	ListaDPI <Cancion*> *lCanciones;
public:
	Artista();
	Artista(string nombre, string pais, int numSeg);
	Artista (Artista &otroArtista);

	void setNombre (string nombre);
	void setPais (string pais);
	void setNumSeg (int numSeg);

	string getNombre () const;
	string getPais () const;
	int getNumSeg () const;

	bool operator == (const Artista &otroArtista) const;
	bool operator < (const Artista &otroArtista) const;

	void mostrar();

	//metodos listaCanciones
	int numElementos () const;
	void mostrarCanciones () const;
	bool buscarCancion (string titulo, Cancion *&c) const;
	void insertar (string titulo, string genero, int duracion);

	~Artista();

};



#endif /* ARTISTA_H_ */
