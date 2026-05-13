//============================================================================
// Name        : EDI26.cpp
// Author      : Elena Chacon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#include "Usuario.h"
#include "PruebaUsuario.h"
#include "PruebaFecha.h"
#include "PruebaArtista.h"
#include "PruebaCancion.h"
#include "PruebaPlaylist.h"
#include "PruebaGestorArtistas.h"

const int TAM = 100;
typedef Usuario *TVector[TAM];

void leerFichero1() {
	string linea;
	int cont = 0;
	ifstream fEnt;
	fEnt.open("usuarios.csv");
	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while (!fEnt.eof()) {
			getline(fEnt, linea);
			if (!fEnt.eof()) {
				cont++;
				cout << cont << "-" << linea << endl;
			}
		}
		fEnt.close();
	} else {
		cerr << "Error al abrir el fichero" << endl;
	}
}
/*void leerFichero2(TVector &v, string inFileName) {
	string cadena[8];
	string linea;
	string token[7];
	int cont = 0;
	char separador[7] = { ';', ';', ';', ';', '/', '/', '\n' };
	int numTokens = sizeof(separador) / sizeof(separador[0]);
	ifstream fEnt;
	fEnt.open(inFileName);
	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while ((cont < TAM) && !fEnt.eof()) {
			for (int i = 0; i < numTokens; i++) {
				if (!fEnt.eof()) {
					getline(fEnt, token[i], separador[i]);
				}
				Usuario *nuevoUsuario = new Usuario(token[0], token[1],
						token[2], token[3], stoi(token[4]), stoi(token[5]),
						stoi(token[6]));

			}
		}
	}

}
*/
void mostrarVector(TVector v) {
	int i = 0;
	while (i < 8) {
		cout << v[i] << endl;
		i++;
	}
}

int main() {

	todasPruebasUsuario();
	todasPruebasFecha();
	todasPruebasArtista();
	todasPruebasCancion();
	todasPruebaPlaylist ();
	todasPruebaGestorArtistas();
	/*TVector v;
	leerFichero2(v);
	mostrarVector(v);
	for (int i = 0; i < TAM; i++)
		delete v[i];*/

	return 0;
}

