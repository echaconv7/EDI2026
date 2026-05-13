/*
 * PruebaPlaylist.cpp
 *
 *  Created on: 12 may 2026
 *      Author: elena
 */

#include "PruebaPlaylist.h"
#include "Playlist.h"
#include "Cancion.h"

void pruebaPlaylistConstructores(){
	Playlist *p1, *p2, *p3;

	p1 = new Playlist ();
	p2 = new Playlist ("musiquita");
	p3 = new Playlist (*p2);

	if (p1->getNombre()!= " "){
		cout << "Error en la prueba del constructor por defecto de Playlist" << endl;
	}

	if (p2-> getNombre() != "musiquita"){
	cout << "Error en la prueba del constructor parametrizado de Playlist" << endl;
	}

	if (p3 -> getNombre() != "musiquita"){
		cout << "Error en la prueba del constructor por copia de Playlist" << endl;
	}

	delete p1;
	delete p2;
	delete p3;
}

void pruebaGetYSetPlaylist (){
	Playlist *p1;
	p1=new Playlist ();

	p1->setNombre ("musiquita");
	if (p1-> getNombre() != "musiquita"){
		cout << "Error en la prueba set/get de Nombre de Playlist" << endl;
		}
	p1->setNumCanciones (5);
	if (p1->getNumCanciones()!=5){
		cout << "Error en la prueba set/get de NumCanciones de Playlist"<< endl;
	}

	p1->setTotalDuracion(245);
	if (p1->getTotalDuracion()!=245){
		cout<<"Error en la prueba set/get de TotalDuracion de Playlist" << endl;
	}
	delete p1;
}
void pruebaRestoPlaylist(){

	Playlist *p1=new Playlist ("musiquita");
	Cancion *c1= new Cancion ("La Perla", "Pop", 176);
	Cancion *c2= new Cancion ("DTMF", "Reggaeton", 135);

	p1->agregarCancion(c1);
	p1->agregarCancion(c2);
	if (p1->getNumCanciones()!=2){
		cout<< "Error en la prueba de agregarCancion de Playlist" << endl;
	}

	p1->eliminarCancion();

	if(p1->getTotalDuracion()!= 135){
		cout<<"Error en la prueba de eliminarCancion de Playlist"<< endl;
	}
	p1->agregarCancion(c1);
	cout << "Deberia mostrar: "<< endl;
	cout << "Nombre de la lista: musiquita"<< endl;
	cout << "Hay 1 cancion/es en la lista"<< endl;
	cout << "La duracion de la lista es de 0 h, 2 min, 15 seg"<< endl;
	cout << "Estas son las canciones que pertenecen a la lista: "<< endl;
	cout << "DTMF Reggaeton 135"<< endl;
	cout << "Y lo que muestra es: " << endl;
	p1->mostrar();

	cout << "Al reproducir la lista deberia aparecer: DTMF Reggaeton 135 y aparece: "<<endl;
	p1->reproducirTodo();

	cout << "Al reproducir la cancion 2 de la lista deberia aparecer La Perla Pop 176 y aparece: "<< endl;
	p1->repUnNumCancion(2);

	delete p1;

}
void todasPruebaPlaylist (){
	cout<< "\033[1;32mInicio pruebas Playlist\033[0m"<< endl;
	pruebaPlaylistConstructores();
	pruebaGetYSetPlaylist ();
	pruebaRestoPlaylist();
	cout << "\033[1;31mFin pruebas Playlist\033[0m"<< endl;
}



