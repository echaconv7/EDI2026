/*
 * PruebaCancion.cpp
 *
 *  Created on: 2 mar 2026
 *      Author: elena
 */
#include "PruebaCancion.h"

void pruebaConstructoresCancion(){
		Cancion *c1, *c2, *c3;
		c1=new Cancion ();
		c2=new Cancion("Beautiful things", "Pop", 193);
		c3=new Cancion (*c2);

		if (c1->getTitulo()!=" "){
			cout<<"Error en la prueba del constructor por defecto"<<endl;
		}
		if(c2->getGenero()!="Pop"){
			cout<<"Error en la prueba del constructor parametrizado"<<endl;
		}
		if (c3->getDuracion()!=193){
			cout<<"Error en la prueba del constructor por copia"<<endl;
		}
		delete c1;
		delete c2;
		delete c3;
}

void pruebaGetYSetCancion(){
		Cancion *c1;
		c1=new Cancion();
		c1->setTitulo("Beautiful things");
		if (c1->getTitulo()!="Beautiful things"){
			cout<<"Error en la prueba set/get de nombre"<<endl;
		}
		c1->setGenero("Pop");
		if(c1->getGenero()!="Pop"){
			cout<<"Error en la prueba set/get de pais"<<endl;
		}
		c1->setDuracion(193);
		if(c1->getDuracion()!= 193){
			cout<<"Error en la prueba de set/get de numero de seguidores"<<endl;
		}
		delete c1;

}

void pruebaRestoCancion(){
		Cancion *c1, *c2, *c3;
		c1= new Cancion ("Beautiful things", "Pop", 193);
		c2= new Cancion("Bohemian Rhapsody", "Rock", 218);
		c3= new Cancion (*c2);

		if (*c2<*c1){
			cout<<"Error en la prueba del operador <"<<endl;
		}

		if (*c2==*c3){

		}else{
			cout <<"Error en la prueba del operador =="<<endl;
		}

		cout<<"Debe salir: Beautiful things Pop 193 y sale: ";
		c1->mostrar();
}

void todasPruebasCancion(){
	cout<<"\033[1;32mInicio de las pruebas de Cancion\033[0m"<<endl;
	pruebaConstructoresCancion();
	pruebaGetYSetCancion();
	pruebaRestoCancion();
	cout<<"\033[1;31mFin de las pruebas de Cancion\033[0m"<< endl;

}

