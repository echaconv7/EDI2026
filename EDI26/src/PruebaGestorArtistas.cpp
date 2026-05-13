/*
 * PruebaGestorArtistas.cpp
 *
 *  Created on: 13 may 2026
 *      Author: elena
 */

#include "PruebaGestorArtistas.h"
#include "GestorArtistas.h"

void pruebaInsertarGestorArtistas(){
	GestorArtistas *ga;
	ga= new GestorArtistas();

	//insertamos en lista vacia
	ga->insertar ("Rihanna", "Estados Unidos", 197363);

	//para insertar al principio necesitamos un nombre que vaya antes alfabeticamente
	ga->insertar ("Arianna Grande", "Estados Unidos", 39827634);

	//para insertar al final nombre que vaya ultimo alfabeticamente
	ga->insertar ("Zenet", "España", 36293);

	//para insertar en medio un nombre que este por la mitad alfabeticamente
	ga->insertar ("Monica Naranjo", "España", 29832);

	//comprobamos que los artistas se guardan en el orden correcto en la lista y se han añadido todos correctamente
	//al estar vacia inserta correctamente
	ga->mostrar();

	delete ga;

}

void pruebaBusquedaGestorArtistas(){
	GestorArtistas *ga, *ga2;
	ga= new GestorArtistas();
	ga2=new GestorArtistas();
	Artista *a= new Artista();

	ga->insertar ("Rihanna", "Estados Unidos", 197363);
	ga->insertar ("Arianna Grande", "Estados Unidos", 39827634);
	ga->insertar ("Zenet", "España", 36293);
	ga->insertar ("Monica Naranjo", "España", 29832);

	//buscamos artista existente
	ga->buscar("Monica Naranjo", a);

	//buscamos artista no existente
	cout<<"Buscamos un artista no existente, no deberia salir nada"<< endl;
	ga->buscar("Coldplay", a);

	//buscamos en una lista vacia
	//actua correctamente con la lista vacia pues no muetra nada
	cout<<"Buscamos en una lista vacia, no deberia salir nada"<< endl;
	ga2->buscar("Rihanna", a);

	delete ga;
	delete ga2;
	delete a;

}


void todasPruebaGestorArtistas(){
	pruebaInsertarGestorArtistas();
	pruebaBusquedaGestorArtistas();
}

