/*
 * Cancion.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */


#include "Cancion.h"

	Cancion::Cancion(){
		titulo=" ";
		genero=" ";
		duracion= 0;
	}

	Cancion::Cancion(string titulo, string genero, int duracion){
		this->titulo=titulo;
		this->genero=genero;
		this->duracion=duracion;
	}

	Cancion::Cancion (const Cancion &otraCancion){
		titulo=otraCancion.titulo;
		genero=otraCancion.genero;
		duracion=otraCancion.duracion;
	}

	void Cancion::setTitulo (string titulo){
		this->titulo=titulo;
	}

	void Cancion::setGenero (string genero){
		this->genero=genero;
	}

	void Cancion::setDuracion (int duracion){
		this->duracion=duracion;
	}

	string Cancion::getTitulo () const{
		return titulo;
	}

	string Cancion::getGenero () const{
		return genero;
	}

	int Cancion::getDuracion () const{
		return duracion;
	}

	void Cancion::mostrar() const{
		cout<< titulo << " " << genero << " " << duracion << endl;
	}

	bool Cancion::operator == (const Cancion &otraCancion) const{
		return (this->titulo==otraCancion.titulo);
	}

	bool Cancion::operator < (const Cancion &otraCancion) const{
		return (this->titulo<otraCancion.titulo);
	}

	Cancion::~Cancion(){

	}

