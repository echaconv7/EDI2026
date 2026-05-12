/*
 * Cancion.h
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */

#ifndef CANCION_H_
#define CANCION_H_

#include <iostream>
using namespace std;

class Cancion{
private:
	string titulo;
	string genero;
	int duracion;
public:
	Cancion();
	Cancion(string titulo, string genero, int duracion);
	Cancion (const Cancion &otraCancion);

	void setTitulo (string titulo);
	void setGenero (string genero);
	void setDuracion (int duracion);

	string getTitulo () const;
	string getGenero () const;
	int getDuracion () const;

	void mostrar();

	bool operator == (const Cancion &otraCancion) const;
	bool operator < (const Cancion &otraCancion) const;

	~Cancion();
};



#endif /* CANCION_H_ */
