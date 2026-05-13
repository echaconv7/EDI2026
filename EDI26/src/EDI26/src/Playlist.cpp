/*
 * Playlist.cpp
 *
 *  Created on: 15 mar 2026
 *      Author: elena
 */

#include "Playlist.h"
#include "Cola.h"



Playlist::Playlist(){
		nombre = " ";
		numCanciones = 0;
		totalDuracion = 0;
		colaReproduccion = new Cola <Cancion*>;
}

Playlist::Playlist (string nombre){
		this->nombre = nombre;
		numCanciones = 0;
		totalDuracion = 0;
		colaReproduccion = new Cola <Cancion*>;
}
Playlist::Playlist (Playlist &otraPlaylist){
		nombre = otraPlaylist.nombre;
		numCanciones = otraPlaylist.numCanciones;
		totalDuracion = otraPlaylist.totalDuracion;
		colaReproduccion = new Cola <Cancion*>;
		Cancion *c = nullptr;
		Cola <Cancion *> *cAux = new Cola <Cancion*>;
		while (!otraPlaylist.colaReproduccion->estaVacia()){
			c=otraPlaylist.colaReproduccion->getPrimero();
			colaReproduccion->encolar(c);
			cAux->encolar(c);
			otraPlaylist.colaReproduccion->desencolar();
		}
		while (!cAux->estaVacia()){
			c=cAux->getPrimero();
			otraPlaylist.colaReproduccion->encolar(c);
			cAux->desencolar();
		}

		delete cAux;

}

void Playlist::setNombre (string nombre){
	this->nombre=nombre;
}
void Playlist::setNumCanciones (int numCanciones){
	this->numCanciones=numCanciones;
}
void Playlist::setTotalDuracion (int totalDuracion){
	this->totalDuracion=totalDuracion;
}

string Playlist::getNombre() const{
	return nombre;
}
int Playlist::getNumCanciones () const{
	return numCanciones;
}
int Playlist::getTotalDuracion ()const{
	return totalDuracion;
}

void Playlist::agregarCancion (Cancion *cancion){
	colaReproduccion->encolar(cancion);
	numCanciones++;
	totalDuracion=totalDuracion+cancion->getDuracion();
}
void Playlist::eliminarCancion (){
	int duracion;
	if (!colaReproduccion->estaVacia()){
		Cancion *c=colaReproduccion->getPrimero();
		duracion=c->getDuracion();
		numCanciones--;
		colaReproduccion->desencolar();
		totalDuracion=totalDuracion-duracion;
	}

}
void Playlist::mostrar (){
	int segundos, minutos, horas;
	segundos = totalDuracion % 60;
	minutos = (totalDuracion % 3600) / 60;
	horas = totalDuracion / 3600;
	Cola <Cancion*> *cAux = new Cola <Cancion*>;
	Cancion *c = nullptr;

	cout << "\n~~~~~~~~\n" << endl;
	cout << "Nombre de la playlist: "<< nombre << endl << endl;
	cout << "Hay " << numCanciones << " cancion/es en la lista" << endl << endl;
	cout << "La duracion de la lista es de: "<< horas << "h, "<< minutos << "min, " << segundos << "seg"<< endl << endl;
	cout << "Estas son las canciones que pertenecen a la lista:" << endl;
	while (!colaReproduccion->estaVacia()){
		c=colaReproduccion->getPrimero();
		cAux->encolar(c);
		colaReproduccion->desencolar();
		c->mostrar();
	}
	while (!cAux->estaVacia()){
		c=cAux->getPrimero();
		colaReproduccion->encolar(c);
		cAux->desencolar();
	}

	delete cAux;

}
void Playlist::reproducirTodo(){
	Cancion *c=nullptr;
	if (!colaReproduccion->estaVacia()){
		for (int i=1; i<=numCanciones; i++){
			c=colaReproduccion->getPrimero();
			c->mostrar();
			colaReproduccion->desencolar();
			colaReproduccion ->encolar(c);
		}
	}
}
void Playlist::repUnNumCancion(int numEnLista){
	Cancion *c=nullptr;
	Cola <Cancion*>  *cAux = new Cola <Cancion*>;
	int i = 1;

	while (!colaReproduccion->estaVacia()){
		c = colaReproduccion->getPrimero();
		cAux->encolar(c);
		colaReproduccion->desencolar();
	}

	while (!cAux->estaVacia()){
		c = cAux->getPrimero();
		colaReproduccion->encolar(c);
		cAux->desencolar();
		if (i >= numEnLista) {
			c->mostrar();
		}
		i++;
	}

	delete cAux;
}

Playlist::~Playlist (){
	delete colaReproduccion;

}
