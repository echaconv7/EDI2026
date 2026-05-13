/*
 * PruebaGestorArtistas.cpp
 *
 *  Created on: 13 may 2026
 *      Author: Marcos
 */

#include "PruebaGestorArtistas.h"

void todasPruebasGestorArtistas () {
	GestorArtistas *gestorArtistas = new GestorArtistas();
	Artista *a = nullptr;

	cout << "\n--- 1. Pruebas con la estructura vacia ---" << endl;
	cout << " Buscando en vacio (Mecano): ";
	if (gestorArtistas->buscar("Mecano", a)) {
		cout << "FALLO. Encontrado en vacio." << endl;
	} else {
		cout << "EXITO. No encontrado." << endl;
	}

	cout << " Mostrar lista vacia:" << endl;
	gestorArtistas->mostrar();
	cout << "(Si no ha salido ningun artista arriba, es un correcto)." << endl;

	cout << "\n Insercion en estructura vacia (Mecano):" << endl;
	gestorArtistas->insertar("Mecano", "España", 100);
	cout << "EXITO. Mecano insertado." << endl;



	cout << "\n--- 2. Pruebas de Insercion en distintas posiciones ---" << endl;

	cout << " Insercion al PRINCIPIO (Adele):" << endl;
	gestorArtistas->insertar("Adele", "Reino Unido", 500); // A va antes que M

	cout << " Insercion al FINAL (Rosalía):" << endl;
	gestorArtistas->insertar("Rosalía", "España", 900); // R va despues que M

	cout << " Insercion INTERMEDIA (Estopa):" << endl;
	gestorArtistas->insertar("Estopa", "España", 300); // E va entre A y M



	cout << "\n--- 3. Pruebas de Busqueda ---" << endl;

	cout << " Búsqueda de artista existente (Estopa): ";
	if (gestorArtistas->buscar("Estopa", a)) {
		cout << "EXITO. Encontrado." << endl;
	} else {
		cout << "FALLO. No encontrado." << endl;
	}



	cout << " Búsqueda de artista inexistente (Artista Falso): ";
	if (gestorArtistas->buscar("Artista Falso", a)) {
		cout << "FALLO. Encontrado (No deberia)." << endl;
	} else {
		cout << "EXITO. No encontrado." << endl;
	}



	cout << "\n--- 4. Prueba de Mostrar y Orden ---" << endl;
	cout << " El orden de salida DEBE ser: Adele -> Estopa -> Mecano -> Rosalía" << endl;
	gestorArtistas->mostrar();



	cout << "\n--- 5. Prueba de Artista con mas seguidores ---" << endl;
	cout << " Deberia mostrar a Rosalía (900 seguidores):" << endl;
	gestorArtistas->mostrarMasSeguidores();

	delete gestorArtistas;
}


