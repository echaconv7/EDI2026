/*
 * PruebaArtista.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */


#include "PruebaArtista.h"
#include "Artista.h"

void pruebaConstructoresArtista(){
	Artista *a1, *a2, *a3;
	a1=new Artista ();
	a2=new Artista("Malu", "Espana", 200192);
	a3=new Artista (*a2);

	if (a1->getNombre()!=" "){
		cout<<"Error en la prueba del constructor por defecto"<<endl;
	}
	if(a2->getPais()!="Espana"){
		cout<<"Error en la prueba del constructor parametrizado"<<endl;
	}
	if (a3->getNumSeg()!=200192){
		cout<<"Error en la prueba del constructor por copia"<<endl;
	}
	delete a1;
	delete a2;
	delete a3;
}

void pruebaGetYSetArtista(){
	Artista *a1;
	a1=new Artista();
	a1->setNombre("Malu");
	if (a1->getNombre()!="Malu"){
		cout<<"Error en la prueba set/get de nombre"<<endl;
	}
	a1->setPais("Espana");
	if(a1->getPais()!="Espana"){
		cout<<"Error en la prueba set/get de pais"<<endl;
	}
	a1->setNumSeg(200192);
	if(a1->getNumSeg()!= 200192){
		cout<<"Error en la prueba de set/get de numero de seguidores"<<endl;
	}
	delete a1;
}

void pruebaRestoArtista(){
	Artista *a1, *a2, *a3;
	a1= new Artista ("Rihanna", "Estados Unidos", 1029472);
	a2= new Artista("Malu", "Espana", 200192);
	a3= new Artista (*a2);

	if (*a1<*a2){
		cout<<"Error en la prueba del operador <"<<endl;
	}

	if (*a2==*a3){

	}else{
		cout <<"Error en la prueba del operador =="<<endl;
	}

	cout<<"Debe salir: Rihanna Estados Unidos 1029472 y sale: ";
	a1->mostrar();

}

void pruebaCancionesArtista() {
    Artista *a1 = new Artista("Malu", "Espana", 200192);

    // Lista vacía: numElementos debe ser 0
    if (a1->numElementos() != 0) {
        cout << "Error: numElementos en lista vacía" << endl;
    }

    // Inserción en lista vacía
    a1->insertar("Todas Mentiras", "Pop", 210);
    if (a1->numElementos() != 1) {
        cout << "Error: inserción en lista vacía" << endl;
    }

    // Inserción al final (alfabéticamente mayor)
    a1->insertar("Volver", "Pop", 195);
    if (a1->numElementos() != 2) {
        cout << "Error: inserción al final" << endl;
    }

    // Inserción al principio (alfabéticamente menor)
    a1->insertar("Asi es la Vida", "Pop", 180);
    if (a1->numElementos() != 3) {
        cout << "Error: inserción al principio" << endl;
    }

    // Inserción en posición intermedia
    a1->insertar("Por Ti", "Pop", 200);
    if (a1->numElementos() != 4) {
        cout << "Error: inserción en posición intermedia" << endl;
    }

    // Inserción de duplicado — no debe insertarse
    a1->insertar("Volver", "Pop", 195);
    if (a1->numElementos() != 4) {
        cout << "Error: el duplicado se insertó" << endl;
    }

    // buscarCancion — canción existente
    Cancion *c = nullptr;
    if (!a1->buscarCancion("Volver", c)) {
        cout << "Error: no encontró una canción existente" << endl;
    }

    // buscarCancion — canción no existente
    if (a1->buscarCancion("Cancion Inexistente", c)) {
        cout << "Error: encontró una canción que no existe" << endl;
    }

    // buscarCancion — lista vacía
    Artista *a2 = new Artista("Artista Vacio", "Espana", 0);
    if (a2->buscarCancion("Cualquier Cosa", c)) {
        cout << "Error: encontró canción en artista sin canciones" << endl;
    }

    // mostrarCanciones — debe mostrar 4 canciones en orden alfabético
    cout << "Canciones de Malu (deben salir en orden alfabetico):" << endl;
    a1->mostrarCanciones();

    delete a1;
    delete a2;
}

void todasPruebasArtista(){
	cout <<"\033[1;32mInicio pruebas Artista\033[0m"<<endl;
	pruebaConstructoresArtista();
	pruebaGetYSetArtista();
	pruebaRestoArtista();
	pruebaCancionesArtista();
	cout << "\033[1;31mFin pruebas Artista\033[0m"<<endl;
}
