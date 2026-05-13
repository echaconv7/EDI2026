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
	Cancion *c1, *c2, *c3;
	c1=new Cancion ("Beutiful things", "Pop", 165);
	c2=new Cancion ("Bohemiam Rhapsody", "Rock", 132);
	c3=new Cancion ("Eternal", "Pop", 187);
	u1= new Usuario ("2345", "Elena Chacon Viniegra", "echaconv@alumnos.unex.es", "echaconv", 20, 6, 1996);
	u1->mostrar ();
	u1->pasarACadena();
	delete u1;

	u1->crearPlayList("musiquita");
	u1->anadirCancionAPlayList("musiquita", c1);
	u1->anadirCancionAPlayList("musiquita", c2);
	u1->anadirCancionAPlayList("musiquita", c3);

	u1->reproducirPlayList();


}

void todasPruebasUsuario (){
	cout << "\033[1;32mInicio pruebas Usuario\033[0m" << endl;
	pruebasConstructores();
	pruebasSetYGet();
	restoMetodos();
	cout << "\033[1;31mFin pruebas Usuario\033[0m"<< endl;
}




