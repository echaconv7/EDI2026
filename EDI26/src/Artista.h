/*
 * Artista.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef ARTISTA_H_
#define ARTISTA_H_
#include <iostream>

using namespace std;

class Artista {
private:
	string nombre;
	string pais;
	int numSeg;
public:
	Artista();
	Artista(string nombre, string pais, int numSeg);
	Artista (const Artista &otroArtista);

	void setNombre (string nombre);
	void setPais (string pais);
	void setNumSeg (int numSeg);

	string getNombre () const;
	string getPais () const;
	int getNumSeg () const;

	bool operator == (const Artista &otroArtista) const;
	bool operator < (const Artista &otroArtista) const;

	void mostrar();

	~Artista();

};



#endif /* ARTISTA_H_ */
