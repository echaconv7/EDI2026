/*
 * PreubaGestorUsuarios.cpp
 *
 *  Created on: 13 may 2026
 *      Author: Marcos
 */


#include "PruebaGestorUsuarios.h"


void todasPruebasGestorUsuarios () {
	GestorUsuarios *gestorUsuarios = new GestorUsuarios();
	Usuario *u = nullptr;

	cout << "\n--- 1. Pruebas con la estructura vacia ---" << endl;

	cout << " Busqueda en vacio (Dominguez Corchero, Mikel): ";
	if (gestorUsuarios->buscar("Dominguez Corchero, Mikel", u)) {
		cout << "FALLO. Encontrado en vacio." << endl;
	} else {
		cout << "EXITO. No encontrado." << endl;
	}

	cout << " Mostrar estructura vacia:" << endl;
	gestorUsuarios->mostrar();
	cout << "(Si no ha salido ningun usuario arriba, es un EXITO)." << endl;

	cout << "\n Inserción en estructura vacia (Dominguez Corchero, Mikel):" << endl;
	gestorUsuarios->insertar("MikelD", "Dominguez Corchero, Mikel", "mdominguet@gmail.com", "pass", 19, 7, 2004);
	cout << "EXITO. Usuario insertado." << endl;



	cout << "\n--- 2. Pruebas de Insercion en distintas posiciones ---" << endl;

	cout << " Inserción al principio (Aguado Pino, Marcos):" << endl;
	// La 'A' va antes que la 'D'
	gestorUsuarios->insertar("MarcosA", "Aguado Pino, Marcos", "tazuazot@gazi.com", "pass", 12, 1, 2004);

	cout << " Insercion al final (Jimenez Muñoz, Daniel):" << endl;
	// La 'J' va después que la 'D'
	gestorUsuarios->insertar("DanielJ", "Jimenez Muñoz, Daniel", "djimenezei@gmail.com", "pass", 24, 3, 2005);

	cout << " Inserción en medio (Carrasco Toscano, Jesus):" << endl;
	// La 'C' va entre la 'A' de Aguado y la 'D' de Dominguez
	gestorUsuarios->insertar("JesúsC", "Carrasco Toscano, Jesus", "jecarrasc@gmail.com", "pass", 10, 5, 2003);



	cout << "\n--- 3. Pruebas de Busqueda ---" << endl;

	cout << " Búsqueda de usuario existente (Carrasco Toscano, Jesus): ";
	if (gestorUsuarios->buscar("Carrasco Toscano, Jesus", u)) {
		cout << "EXITO. Encontrado." << endl;
	} else {
		cout << "FALLO. No encontrado." << endl;
	}

	cout << " Búsqueda de usuario inexistente (usuario inexistente): ";
	if (gestorUsuarios->buscar("Zanahoria, Pepe", u)) {
		cout << "FALLO. Encontrado (No deberia)." << endl;
	} else {
		cout << "EXITO. No encontrado." << endl;
	}

	cout << "\n--- 4. Prueba de Mostrar y Orden ---" << endl;
	cout << " El orden de salida DEBE ser: Aguado -> Carrasco -> Dominguez -> Jimenez" << endl;
	gestorUsuarios->mostrar();

	delete gestorUsuarios;
}



