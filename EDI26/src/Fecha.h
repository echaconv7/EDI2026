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

	// PRE: ---
	// DESC: Constructor por defecto. Inicializa a una fecha base.
	// COMPLEJIDAD: O(1)
	Fecha ();

	// PRE: Los parámetros deben formar una fecha válida.
	// DESC: Constructor parametrizado. Asigna día, mes y año.
	// COMPLEJIDAD: O(1)
	Fecha (int dia, int mes, int ano);

	// PRE: otraFecha debe estar correctamente inicializada.
	// DESC: Constructor por copia.
	// COMPLEJIDAD: O(1)
	Fecha (const Fecha &otraFecha);


	// PRE: dia debe estar entre 1 y 31 (según el mes).
	// DESC: Modifica el día de la fecha.
	// COMPLEJIDAD: O(1)
	void setDia (int dia);

	// PRE: mes debe estar entre 1 y 12.
	// DESC: Modifica el mes de la fecha.
	// COMPLEJIDAD: O(1)
	void setMes(int mes);

	// PRE: ---
	// DESC: Modifica el año de la fecha.
	// COMPLEJIDAD: O(1)
	void setAno(int ano);


	// PRE: ---
	// DESC: Devuelve el día de la fecha.
	// COMPLEJIDAD: O(1)
	int getDia () const;

	// PRE: ---
	// DESC: Devuelve el mes de la fecha.
	// COMPLEJIDAD: O(1)
	int getMes () const;

	// PRE: ---
	// DESC: Devuelve el año de la fecha.
	// COMPLEJIDAD: O(1)
	int getAno () const;


	// PRE: ---
	// DESC: Muestra la fecha por consola en formato DD/MM/AAAA.
	// COMPLEJIDAD: O(1)
	void mostrarFecha() const;


	// PRE: ---
	// DESC: Destructor.
	// COMPLEJIDAD: O(1)
	~Fecha();
};



#endif /* FECHA_H_ */
