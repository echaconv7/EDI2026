/*
 * Artista.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */
#include "Artista.h"

	Artista::Artista() {
	nombre = " ";
	pais = " ";
	numSeg = 0;
	lCanciones = new ListaDPI <Cancion*> ();
	}

	Artista::Artista(string nombre, string pais, int numSeguidores) {
		this->nombre = nombre;
		this->pais = pais;
		this->numSeg = numSeguidores;
		lCanciones = new ListaDPI <Cancion*> ();
	}

	Artista::Artista(const Artista &otroArtista) {
		this->nombre = otroArtista.nombre;
		this->pais = otroArtista.pais;
		this->numSeg = otroArtista.numSeg;
		Cancion *c = nullptr;
			lCanciones = new ListaDPI <Cancion*> ();
			lCanciones->moverPrimero();
			otroArtista.lCanciones->moverPrimero();
			while (!otroArtista.lCanciones->alFinal()) {
				c = otroArtista.lCanciones->consultar();
				lCanciones->insertar(new Cancion (*c));
				otroArtista.lCanciones->avanzar();
			}
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

	void Artista::mostrar() const {
		cout << "\n--------------------------------------------------" << endl;
		cout << "Nombre: " << nombre << "; " << "Pais: " << pais <<"; "<< "Nº de seguidores: " << numSeg<< endl;
		cout << "Canciones: " << endl;
		mostrarCanciones();
	}

	int Artista::numElementos() const {
		int cont = 0;
		lCanciones->moverPrimero();
		while (!lCanciones->alFinal()) {
			cont++;
			lCanciones->avanzar();
		}
		return cont;
	}

	void Artista::mostrarCanciones() const {
		lCanciones->moverPrimero();
		while (!lCanciones->alFinal()) {
			lCanciones->consultar()->mostrar();
			lCanciones->avanzar();
		}
	}

	bool Artista::buscarCancion(string titulo, Cancion *&c) const {
		bool enc = false;
		lCanciones->moverPrimero();
		while (!lCanciones->alFinal() && !enc) {
			if (lCanciones->consultar()->getTitulo() == titulo) {
				c = lCanciones->consultar();
				enc = true;
			}
			else {
				lCanciones->avanzar();
			}
		}
		return enc;
	}

	void Artista::insertar(string titulo, string genero, int duracion) {
		Cancion *c = nullptr;
		bool encontrado = false;
		bool igual = false;
		lCanciones->moverPrimero();
		while (!lCanciones->alFinal() && !encontrado && !igual) {
			lCanciones->consultar(c);
			if (c->getTitulo() == titulo) {
				igual = true;
			} else if (c->getTitulo() > titulo) {
				encontrado = true;
			} else {
				lCanciones->avanzar();
			}
		}
		if (!igual) {
			c = new Cancion (titulo, genero, duracion);
			lCanciones->insertar(c);
		}

	}

	Artista::~Artista() {
		lCanciones->moverPrimero();
		while (!lCanciones->alFinal()) {
			delete lCanciones->consultar();
			lCanciones->eliminar();
		}
		delete lCanciones;
	}

