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

void todasPruebasArtista(){
	cout <<"\033[1;32mInicio pruebas Artista\033[0m"<<endl;
	pruebaConstructoresArtista();
	pruebaGetYSetArtista();
	pruebaRestoArtista();
	cout << "\033[1;31mFin pruebas Artista\033[0m"<<endl;
}
