/*
 * Fecha.cpp
 *
 *  Created on: 23 feb 2026
 *      Author: elena
 */

#include "Fecha.h"

Fecha::Fecha(){
	dia=0;
	mes=0;
	ano=0;
}

Fecha::Fecha(int dia, int mes, int ano){
	this->dia=dia;
	this->mes = mes;
	this->ano = ano;
}

Fecha::Fecha (Fecha &otraFecha){
	dia=otraFecha.dia;
	mes=otraFecha.mes;
	ano=otraFecha.ano;
}

void Fecha::setDia(int dia){
	this->dia = dia;
}

void Fecha::setMes (int mes){
	this->mes=mes;
}

void Fecha::setAno (int ano){
	this->ano=ano;
}

int Fecha::getDia () const{
	return dia;
}

int Fecha::getMes () const {
	return mes;
}

int Fecha::getAno () const {
	return ano;
}

void Fecha::mostrarFecha (){
	cout << dia << "/" << mes << "/" << ano << endl;
}

Fecha::~Fecha(){

}

