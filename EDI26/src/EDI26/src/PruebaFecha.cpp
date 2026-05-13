/*
 * PruebaFecha.cpp
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */
#include "PruebaFecha.h"
#include "Fecha.h"

void pruebaConstructoresFecha(){
	Fecha f1, f2, f3;
	f1=Fecha();
	if (f1.getDia() != 0){
		cout << "Error en la prueba del constructor pordefecto"<< endl;
	}

	f2=Fecha(20, 06, 1996);
	if (f2.getMes() != 6){
		cout<<"Error en la prueba del constructor parametrizado"<<endl;
	}

	f3=Fecha(f2);
	if (f3.getAno() != 1996){
		cout << "Error en la prueba del constructor por copia" << endl;
	}

}

void pruebaMetodosFecha(){

	Fecha f1;
	f1=Fecha();

	f1.setDia (20);
	if (f1.getDia()!= 20){
		cout << "Error en la prueba de set/get de dia"<<endl;
	}
	f1.setMes(06);
	if (f1.getMes()!=6){
		cout<<"Error en la prueba de set/get de mes" << endl;
	}

	f1.setAno(1996);
	if (f1.getAno()!=1996){
		cout<<"Error en la prueba de set/get de ano"<<endl;
	}

	cout << "Debe salir 20/6/1996 y lo que sale es: ";
	f1.mostrarFecha();
}

void todasPruebasFecha(){
	cout<< "\033[1;32mInicio pruebas Fecha\033[0m"<< endl;
	pruebaConstructoresFecha();
	pruebaMetodosFecha();
	cout << "\033[1;31mFin pruebas Fecha\033[0m"<< endl;
}


