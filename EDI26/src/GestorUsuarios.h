/*
 * GestorUsuarios.h
 *
 *  Created on: 16 mar 2026
 *      Author: Marcos
 */

#ifndef GESTORUSUARIOS_H_
#define GESTORUSUARIOS_H_

#include "Usuario.h"
#include "ListaDPI.h"
#include "BSTree.h"
#include "KeyValue.h"

//#define LISTA_USUARIOS	// SI ESTA, SE EJECUTA EL GESTOR CON LA LISTA,
                 	 		// SI NO ESTA, SE EJECUTA EL ELSE, EL GESTOR CON EL ÁRBOL


#if defined(LISTA_USUARIOS)
class GestorUsuarios {
private:
	ListaDPI <Usuario*> *lUsuarios;
public:
	// PRE: ---
	// DESC: Constructor por defecto. Crea un GestorUsuarios con una lista vacía.
	// COMPLEJIDAD: O(1)
	GestorUsuarios();

	// PRE: otroGestorUsuarios debe estar correctamente inicializado.
	// DESC: Constructor por copia. Realiza una copia de la lista de usuarios.
	// COMPLEJIDAD: O(n)
	GestorUsuarios(const GestorUsuarios &otroGestorUsuarios);

	//otros métodos:

	// PRE: ---
	// DESC: Inserta un nuevo usuario en orden alfabético si no existe previamente.
	// COMPLEJIDAD: O(n)
	void insertar (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int year);

	// PRE: ---
	// DESC: Busca un usuario por sus apellidos y nombre. Devuelve true y modifica el puntero si lo encuentra.
	// COMPLEJIDAD: O(n)
	bool buscar (string apellidosNombre, Usuario *&u) const;

	// PRE: ---
	// DESC: Devuelve el número total de usuarios registrados en la lista.
	// COMPLEJIDAD: O(n)
	int numElementos () const;

	// PRE: ---
	// DESC: Muestra por pantalla los datos de todos los usuarios del gestor.
	// COMPLEJIDAD: O(n)
	void mostrar () const;

	// PRE: ---
	// DESC: Destructor. Libera la memoria de la lista y destruye todos los objetos Usuario.
	// COMPLEJIDAD: O(n)
	~GestorUsuarios();
};

#else

class GestorUsuarios  {
	BSTree<KeyValue<string,Usuario*>> *aUsuarios;

	// métodos privados:

	// PRE: arbol correctamente inicializado.
	// DESC: Busca recursivamente un usuario por clave. Devuelve true si lo encuentra.
	// COMPLEJIDAD: O(log n) en el caso medio del árbol.
	bool buscarRec (BSTree<KeyValue<string, Usuario*>> *arbol, string clave, Usuario *&u) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Recorre el árbol en in-orden mostrando los usuarios alfabéticamente.
	// COMPLEJIDAD: O(n)
	void mostrarRec (BSTree<KeyValue<string, Usuario*>> *arbol) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Cuenta recursivamente los nodos del árbol.
	// COMPLEJIDAD: O(n)
	int numElementosRec (BSTree<KeyValue<string, Usuario*>> *arbol) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Calcula recursivamente la profundidad máxima del árbol.
	// COMPLEJIDAD: O(n)
	int profundidadRec (BSTree<KeyValue<string, Usuario*>> *arbol) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Recorre el árbol en post-orden para liberar la memoria de los usuarios.
	// COMPLEJIDAD: O(n)
	void vaciarRec (BSTree<KeyValue<string, Usuario*>> *arbol);

	// PRE: otroArbol correctamente inicializado.
	// DESC: Recorre en pre-orden el árbol original insertando copias profundas en este árbol.
	// COMPLEJIDAD: O(n log n)
	void copiarArbol (BSTree<KeyValue<string, Usuario*>> *otroArbol);

public:

	// PRE: ---
	// DESC: Constructor por defecto. Crea un GestorUsuarios con un árbol vacío.
	// COMPLEJIDAD: O(1)
	GestorUsuarios();

	// PRE: otroGestor debe estar correctamente inicializado.
	// DESC: Constructor por copia. Realiza una copia del árbol de usuarios.
	// COMPLEJIDAD: O(n log n)
	GestorUsuarios(const GestorUsuarios &otroGestor);

	// PRE: ---
	// DESC: Inserta un nuevo usuario en el árbol binario si no existe ya.
	// COMPLEJIDAD: O(log n).
	void insertar (string idUsuario, string apellidosNombre, string email, string password, int dia, int mes, int year);

	// PRE: ---
	// DESC: Inicia la búsqueda recursiva de un usuario por apellidos y nombre.
	// COMPLEJIDAD: O(log n)
	bool buscar (string apellidosNombre, Usuario *&u) const;

	// PRE: ---
	// DESC: Inicia el conteo recursivo de los usuarios registrados.
	// COMPLEJIDAD: O(n)
	int numElementos () const;

	// PRE: ---
	// DESC: Inicia el recorrido recursivo para mostrar usuarios y la profundidad del árbol.
	// COMPLEJIDAD: O(n)
	void mostrar () const;

	// PRE: ---
	// DESC: Destructor. Vacía recursivamente los usuarios dinámicos y destruye el árbol.
	// COMPLEJIDAD: O(n)
	~GestorUsuarios();
};

#endif /* defined*/
#endif /* GESTORUSUARIOS_H_ */
