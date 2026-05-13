/*
 * Sistema.cpp
 *
 *  Created on: 12 may 2026
 *      Author: bychi
 */

#include "Sistema.h"

Sistema::Sistema() {
	nombreSistema = " ";
	usuarios = new GestorUsuarios();
	artistas = new GestorArtistas();

	cargarUsuarios();
	cargarArtistas();
	cargarCanciones();
	cargarPlaylist();
}

Sistema::Sistema(string nombreSistema) {
	this->nombreSistema = nombreSistema;
	usuarios = new GestorUsuarios();
	artistas = new GestorArtistas();

	cargarUsuarios();
	cargarArtistas();
	cargarCanciones();
	cargarPlaylist();
}

void Sistema::cargarUsuarios() {
	string linea, idUsuario, apellidosNombre, email, password, dia, mes, year;
	ifstream fEnt;
	fEnt.open("usuarios.csv");

	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while (!fEnt.eof()) {
			getline(fEnt, idUsuario, ';');
			getline(fEnt, apellidosNombre, ';');
			getline(fEnt, email, ';');
			getline(fEnt, password, ';');
			getline(fEnt, dia, '/');
			getline(fEnt, mes, '/');
			getline(fEnt, year);

			if (!fEnt.eof() && idUsuario != "") {
				usuarios->insertar(idUsuario, apellidosNombre, email, password, stoi(dia), stoi(mes), stoi(year));
			}
		}
		fEnt.close();
	} else {
		cerr << "Error al abrir el archivo usuarios.csv" << endl;
	}
}

void Sistema::cargarArtistas() {
	string linea, nombre, pais;
	ifstream fEnt;
	fEnt.open("artistas.csv");

	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while (!fEnt.eof()) {
			getline(fEnt, nombre, ';');
			getline(fEnt, pais);

			if (!fEnt.eof() && nombre != "") {
				artistas->insertar(nombre, pais, 0); //numero de seguidores a 0
			}
		}
		fEnt.close();
	} else {
		cerr << "Error al abrir el archivo artistas.csv" << endl;
	}
}

void Sistema::cargarCanciones() {
	string linea, nombreArtista, titulo, genero, duracion;
	ifstream fEnt;
	fEnt.open("canciones.csv");

	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while (!fEnt.eof()) {
			getline(fEnt, nombreArtista, ';');
			getline(fEnt, titulo, ';');
			getline(fEnt, genero, ';');
			getline(fEnt, duracion);

			if (!fEnt.eof() && nombreArtista != "") {
				Artista *a = nullptr;
				if (artistas->buscar(nombreArtista, a)) {
					a->insertar(titulo, genero, stoi(duracion));
				}
			}
		}
		fEnt.close();
	} else {
		cerr << "Error al abrir el archivo canciones.csv" << endl;
	}
}

void Sistema::cargarPlaylist() {
	string linea, apellidosNombre, nombrePlaylist, nombreArtista, tituloCancion;
	ifstream fEnt;
	fEnt.open("playList.csv");

	if (fEnt.is_open()) {
		getline(fEnt, linea);
		while (!fEnt.eof()) {
			getline(fEnt, apellidosNombre, ';');
			getline(fEnt, nombrePlaylist, ';');
			getline(fEnt, nombreArtista, ';');
			getline(fEnt, tituloCancion);

			if (!fEnt.eof() && nombreArtista != "") {
				Usuario *u = nullptr;
				Artista *a = nullptr;
				Cancion *c = nullptr;

				if (usuarios->buscar(apellidosNombre, u) && artistas->buscar(nombreArtista, a)) {
					if (a->buscarCancion(tituloCancion, c)) {
						u->crearPlayList(nombrePlaylist);
						u->anadirCancionAPlayList(nombrePlaylist, c);
					}
				}
			}
		}
		fEnt.close();
	} else {
		cerr << "Error al abrir el archivo playList.csv" << endl;
	}
}


void Sistema::mostrarUsuarios() {
	cout << "~~~ USUARIOS EN EL SISTEMA ~~~" << endl;
	usuarios->mostrar();
	cout << "Total de usuarios en el sistema: " << usuarios->numElementos() << endl;
}

void Sistema::buscarUsuario(string apellidosNombre) {
	Usuario *u = nullptr;
	if (usuarios->buscar(apellidosNombre, u)) {
		cout << "Usuario encontrado: " << endl;
		u->mostrar();
	} else {
		cout << "El usuario " << apellidosNombre << " no existe." << endl;
	}
}

void Sistema::mostrarArtistas() {
	cout << "~~~ ARTISTAS EN EL SISTEMA ~~~" << endl;
	artistas->mostrar();
	cout << "Total de artistas en el sistema: " << artistas->numElementos() << endl;
}

void Sistema::buscarArtistas(string nombre) {
	Artista *a = nullptr;
	if (artistas->buscar(nombre, a)) {
		cout << "Artista encontrado: " << endl;
		a->mostrar();
	} else {
		cout << "El artista " << nombre << " no existe." << endl;
	}
}

void Sistema::reproducirPlaylist(string apellidosNombre, string nombrePlaylist) {
	Usuario *u = nullptr;
	if (usuarios->buscar(apellidosNombre, u)) {
		u->reproducirPlayListPorNombre(nombrePlaylist);
	} else {
		cout << "No se ha podido encontrar al usuario." << endl;
	}
}

void Sistema::compartirPlaylist(string emisor, string nombrePlaylist, string receptor) {
	Usuario *uEmisor = nullptr;
	Usuario *uReceptor = nullptr;

	if (usuarios->buscar(emisor, uEmisor) && usuarios->buscar(receptor, uReceptor)) {
		Playlist *copia = uEmisor->compartirPlayList(nombrePlaylist);
		if (copia != nullptr) {
			uReceptor->anadirPlayListCompartida(copia);
			cout << "La PlayList ha sido compartida con éxito." << endl;
		} else {
			cout << "El emisor no tiene esa PlayList" << endl;
		}
	} else {
		cout << "Emisor o receptor no encontrados." << endl;
	}
}

void Sistema::eliminarPlaylist(string apellidosNombre, string nombrePlaylist) {
	Usuario *u = nullptr;
	if (usuarios->buscar(apellidosNombre, u)) {
		u->eliminarPlayList(nombrePlaylist);
		cout << "La PlayList ha sido eliminada." << endl;
	} else {
		cout << "Usuario no encontrado." << endl;
	}
}

void Sistema::anadirArtistaFavorito(string apellidosNombre, string nombreArtista) {
	Usuario *u = nullptr;
	Artista *a = nullptr;

	if (usuarios->buscar(apellidosNombre, u)) {
		if (artistas->buscar(nombreArtista, a)) {
			bool yaEraFavorito = u->esArtistaFavorito(nombreArtista); // nuevo método
			u->insertarArtistaFavorito(a);
			if (!yaEraFavorito) {
				a->setNumSeg(a->getNumSeg() + 1);
				cout << "Artista añadido a favoritos." << endl;
			} else {
				cout << "El artista ya era favorito." << endl;
			}
		} else {
			cout << "No se ha podido encontrar al artista." << endl;
		}
	} else {
		cout << "No se ha podido encontrar al usuario." << endl;
	}
}

void Sistema::eliminarArtistaFavorito(string apellidosNombre, string nombreArtista) {
    Usuario *u = nullptr;
    Artista *a = nullptr;

    if (usuarios->buscar(apellidosNombre, u)) {
        if (artistas->buscar(nombreArtista, a)) {
            bool eraFavorito = u->esArtistaFavorito(nombreArtista);
            u->eliminarArtistaFavorito(nombreArtista);
            if (eraFavorito) {
                a->setNumSeg(a->getNumSeg() - 1);
                cout << "El artista ha sido eliminado de favoritos." << endl;
            } else {
                cout << "El artista no estaba en favoritos." << endl;
            }
        } else {
            cout << "No se ha podido encontrar al artista." << endl;
        }
    } else {
        cout << "No se ha podido encontrar al usuario." << endl;
    }
}

void Sistema::mostrarArtistaMasSeguidores() {
	artistas->mostrarMasSeguidores();
}

Sistema::~Sistema() {
	delete usuarios;
	delete artistas;
}

