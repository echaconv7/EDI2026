//============================================================================
// Name        : progPrincipal.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 25/26
// Copyright   :
// Description : Programa principal proyecto EDI
//============================================================================


#include <iostream>
#include <string>

#include "Sistema.h"
#include "PruebaUsuario.h"
#include "PruebaFecha.h"
#include "PruebaArtista.h"
#include "PruebaCancion.h"
#include "PruebaPlaylist.h"

using namespace std;



int menu(string nombreSistema) {
	int opcion;
	do {
		cout << endl<<endl;
		cout << " -------- " << nombreSistema << " --------" << endl <<endl;
		cout << " 1. Mostrar todos los usuarios             " << endl;
		cout << " 2. Buscar y mostrar un usuario            " << endl;
		cout << " 3. Mostrar artistas y sus canciones       " << endl;
		cout << " 4. Buscar y mostrar un artista            " << endl;
		cout << " 5. Reproducir una playlist de un usuario  " << endl;
		cout << " 6. Compartir playlist entre dos usuarios  " << endl;
		cout << " 7. Eliminar playlist de un usuario        " << endl;
		cout << " 8. Añadir artista a favoritos de un usuario" << endl;
		cout << " 9. Eliminar artista de favoritos de un usuario" << endl;
		cout << " 10. Artista con mas seguidores          " << endl;

		cout << " 0. Finalizar. " << endl;
		cout << " Opción: ";
		cout<<"_";
		cin>>opcion;
		cin.ignore();
		cout<<endl;

	} while ((opcion < 0) || (opcion > 11));
	return opcion;
}


int main() {

	//todasPruebasUsuario();
	//todasPruebasFecha();
	//todasPruebasArtista();
	//todasPruebasCancion();
	//todasPruebaPlaylist ();

	Sistema *spotify = new Sistema ("Spotify");

	bool salir = false;
	int opcion;

	string aux1, aux2, aux3;

	while (!salir) {

		opcion = menu("Simulador Spotify");
		switch (opcion) {
		case 1:
			spotify->mostrarUsuarios();
			break;
		case 2:
			cout << "Introduce los Apellidos y el Nombre del usuario: ";
			getline (cin, aux1);
			spotify->buscarUsuario(aux1);
			break;
		case 3:
			spotify->mostrarArtistas();
			break;
		case 4:
			cout << "Introduce el nombre del artista: ";
			getline (cin, aux1);
			spotify->buscarArtistas(aux1);
			break;
		case 5:
			cout << "Introduce los Apellidos y el Nombre del usuario: ";
			getline (cin, aux1);
			cout << "Introduce el nombre de la PlayList: ";
			getline (cin, aux2);
			spotify->reproducirPlaylist(aux1, aux2);
			break;
		case 6:
			cout << "Introduce los Apellidos y el Nombre del usuario EMISOR: ";
			getline (cin, aux1);
			cout << "Introduce el nombre de la PlayList a compartir: ";
			getline (cin, aux2);
			cout << "Introduce los Apellidos y el Nombre del usuario RECEPTOR: ";
			getline (cin, aux3);
			spotify->compartirPlaylist(aux1, aux2, aux3);
			break;
		case 7:
			cout << "Introduce los Apellidos y el Nombre del usuario: ";
			getline (cin, aux1);
			cout << "Introduce el nombre de la PlayList a eliminar: ";
			getline (cin, aux2);
			spotify->eliminarPlaylist(aux1, aux2);
			break;
		case 8:
			cout << "Introduce los Apellidos y el Nombre del usuario: ";
			getline (cin, aux1);
			cout << "Introduce el nombre del artista a añadir en favoritos: ";
			getline (cin, aux2);
			spotify->anadirArtistaFavorito(aux1, aux2);
			break;
		case 9:
			cout << "Introduce los Apellidos y el Nombre del usuario: ";
			getline (cin, aux1);
			cout << "Introduce el nombre del artista a eliminar de favoritos: ";
			getline (cin, aux2);
			spotify->eliminarArtistaFavorito(aux1, aux2);
			break;
		case 10:
			spotify->mostrarArtistaMasSeguidores();
			break;
		case 0:
			salir = true;
			break;
		default:
			break;
		}
	}

	delete spotify;
	return 0;
}



