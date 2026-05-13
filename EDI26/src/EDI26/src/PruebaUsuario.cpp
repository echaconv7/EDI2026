/*
 * PruebaUsuario.cpp
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */

#include "PruebaUsuario.h"
#include "Usuario.h"

void pruebasConstructores (){
	Usuario *u1, *u2, *u3;
	u1=new Usuario ();
	u2= new Usuario ("2345", "Elena Chacon Viniegra", "echaconv@alumnos.unex.es", "echaconv", 20, 6, 1996);
	u3= new Usuario (*u2);

	if (u1->getIdUsuario() != " "){
		cout << "Error en la prueba del constructor por defecto"<< endl;
	}

	if (u2->getPassword()!= "echaconv"){
		cout << "Error en la prueba del constructor parametrizado"<< endl;
	}

	if (u3->getIdUsuario () != "2345"){
		cout << "Error en la prueba del constructor por copia" << endl;
	}

	delete u1;
	delete u2;
	delete u3;

}

void pruebasSetYGet (){
	Usuario *u1;
	u1= new Usuario ();

	u1->setIdUsuario("2345");
	if (u1->getIdUsuario() != "2345"){
		cout << "Error en la prueba de get/set de idUsuario"<<endl;
	}

	u1->setApellidosNombre("Elena Chacon Viniegra");
	if (u1->getApellidosNombre() != "Elena Chacon Viniegra"){
		cout << "Error en la prueba de get/set de apellidosNombre"<< endl;
	}

	u1->setEmail ("echaconv@alumnos.unex.es");
	if (u1->getEmail() != "echaconv@alumnos.unex.es"){
		cout << "Error en la prueba de set/get de email"<< endl;
	}

	u1->setPassword("echaconv");
	if (u1->getPassword()!="echaconv"){
		cout << "Error en la prueba de set/get de password"<< endl;
	}

	delete u1;

}

void restoMetodos () {
	Usuario *u1;
	u1= new Usuario ("2345", "Elena Chacon Viniegra", "echaconv@alumnos.unex.es", "echaconv", 20, 6, 1996);
	u1->mostrar ();
	u1->pasarACadena();
	delete u1;
}

void todasPruebasUsuario (){
	cout << "\033[1;32mInicio pruebas Usuario\033[0m" << endl;
	pruebasConstructores();
	pruebasSetYGet();
	restoMetodos();
	pruebasPlaylistsYFavoritos();
	cout << "\033[1;31mFin pruebas Usuario\033[0m"<< endl;
}

void pruebasPlaylistsYFavoritos() {
    Cancion *c1 = new Cancion("Volver", "Pop", 200);
    Cancion *c2 = new Cancion("Todas Mentiras", "Pop", 210);
    Artista *a1 = new Artista("Malu", "Espana", 0);
    Artista *a2 = new Artista("Rihanna", "EEUU", 0);

    Usuario *u = new Usuario("001", "Test, Usuario", "test@test.com", "pass", 1, 1, 2000);

    // --- crearPlayList ---
    u->crearPlayList("favoritas");
    u->crearPlayList("rock");
    // duplicado: no debe insertarse una segunda vez
    u->crearPlayList("favoritas");

    // --- anadirCancionAPlayList ---
    u->anadirCancionAPlayList("favoritas", c1);
    u->anadirCancionAPlayList("favoritas", c2);
    // playlist inexistente: no debe crashear
    u->anadirCancionAPlayList("no existe", c1);

    // --- compartirPlayList ---
    Playlist *copia = u->compartirPlayList("favoritas");
    if (copia == nullptr) {
        cout << "Error: compartirPlayList no devolvio copia" << endl;
    }
    // playlist inexistente debe devolver nullptr
    Playlist *copiaNull = u->compartirPlayList("no existe");
    if (copiaNull != nullptr) {
        cout << "Error: compartirPlayList devolvio algo para una playlist inexistente" << endl;
    }
    delete copia;

    // --- eliminarPlayList ---
    u->eliminarPlayList("rock");
    // eliminar playlist inexistente: no debe crashear
    u->eliminarPlayList("no existe");

    // --- insertarArtistaFavorito ---
    u->insertarArtistaFavorito(a1);
    u->insertarArtistaFavorito(a2);
    // duplicado: no debe insertarse
    u->insertarArtistaFavorito(a1);

    // --- eliminarArtistaFavorito ---
    u->eliminarArtistaFavorito("Malu");
    // artista no en favoritos: no debe crashear
    u->eliminarArtistaFavorito("Artista Falso");

    delete u;
    delete c1;
    delete c2;
    delete a1;
    delete a2;
}


