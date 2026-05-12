/*
 * Fecha.h
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */

#ifndef FECHA_H_
#define FECHA_H_

#include <iostream>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int ano;
public :
	Fecha ();
	Fecha (int dia, int mes, int ano);
	Fecha (Fecha &otraFecha);

	void setDia (int dia);
	void setMes(int mes);
	void setAno(int ano);

	int getDia () const;
	int getMes () const;
	int getAno () const;

	void mostrarFecha();

	~Fecha();
};



#endif /* FECHA_H_ */
