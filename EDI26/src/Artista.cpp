/*
 * Artista.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */
#include "Artista.h"

	Artista::Artista(){
		nombre=" ";
		pais=" ";
		numSeg=0;
	}

	Artista::Artista(string nombre, string pais, int numSeg){
		this->nombre=nombre;
		this->pais=pais;
		this->numSeg=numSeg;
	}

	Artista::Artista (const Artista &otroArtista){
		nombre=otroArtista.nombre;
		pais=otroArtista.pais;
		numSeg=otroArtista.numSeg;
	}

	void Artista::setNombre (string nombre){
		this->nombre=nombre;
	}

	void Artista::setPais (string pais){
		this->pais=pais;
	}

	void Artista::setNumSeg (int numSeg){
		this->numSeg=numSeg;
	}

	string Artista::getNombre () const{
		return nombre;
	}

	string Artista::getPais () const{
		return pais;
	}

	int Artista::getNumSeg () const{
		return numSeg;
	}

	bool Artista::operator == (const Artista &otroArtista) const{
		return (this->nombre==otroArtista.nombre);
	}

	bool Artista::operator < (const Artista &otroArtista) const{
		return (this->nombre<otroArtista.nombre);
	}

	void Artista::mostrar(){
		cout << nombre << " " << pais <<" "<< numSeg <<" " << endl;
	}

	Artista::~Artista(){

	}

