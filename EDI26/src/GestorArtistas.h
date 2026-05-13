/*
 * GestorArtistas.h
 *
 *  Created on: 12 may 2026
 *      Author: bychi
 */

#ifndef GESTORARTISTAS_H_
#define GESTORARTISTAS_H_

#include "Artista.h"
#include "ListaDPI.h"
#include "BSTree.h"
#include "KeyValue.h"

//#define LISTA_ARTISTAS	// SI ESTA, SE EJECUTA EL GESTOR CON LA LISTA,
                 	 		// SI NO ESTA, SE EJECUTA EL ELSE, EL GESTOR CON EL ÁRBOL

#if defined(LISTA_ARTISTAS)

class GestorArtistas {
private:

	ListaDPI<Artista*> *lArtistas;

public:

	// PRE: ---
	// DESC: Constructor por defecto. Crea un GestorArtistas con una lista vacía.
	// COMPLEJIDAD: O(1)
	GestorArtistas();

	// PRE: otroGestorArtistas debe estar correctamente inicializado.
	// DESC: Constructor por copia. Realiza una copia de la lista de artistas.
	// COMPLEJIDAD: O(n)
	GestorArtistas(const GestorArtistas &otroGestorArtistas);

	// PRE: ---
	// DESC: Inserta un nuevo artista de forma ordenada alfabéticamente si no existe.
	// COMPLEJIDAD: O(n)
	void insertar (string nombre, string pais, int numSeguidores);

	// PRE: ---
	// DESC: Busca un artista por su nombre. Devuelve true y modifica el puntero si lo encuentra.
	// COMPLEJIDAD: O(n)
	bool buscar (string nombre, Artista *&a) const;

	// PRE: ---
	// DESC: Devuelve el número total de artistas registrados en la lista.
	// COMPLEJIDAD: O(n)
	int numElementos () const;

	// PRE: ---
	// DESC: Muestra por pantalla los datos de todos los artistas.
	// COMPLEJIDAD: O(n)
	void mostrar () const;

	// PRE: ---
	// DESC: Busca e imprime los datos del artista que tiene mayor número de seguidores.
	// COMPLEJIDAD: O(n)
	void mostrarMasSeguidores() const;

	// PRE: ---
	// DESC: Destructor. Libera la memoria de la lista y destruye todos los objetos Artista.
	// COMPLEJIDAD: O(n)
	~GestorArtistas();
};

#else

class GestorArtistas  {
	BSTree <KeyValue<string, Artista*> > *aArtistas;

	// métodos privados:

	// PRE: arbol correctamente inicializado.
	// DESC: Busca recursivamente un artista por nombre. Devuelve true si lo encuentra.
	// COMPLEJIDAD: O(log n)
	bool buscarRec (BSTree<KeyValue<string, Artista*>> *arbol, string clave, Artista *&a) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Recorre el árbol en in-orden mostrando los artistas alfabéticamente.
	// COMPLEJIDAD: O(n)
	void mostrarRec (BSTree<KeyValue<string, Artista*>> *arbol) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Cuenta recursivamente los nodos del árbol.
	// COMPLEJIDAD: O(n)
	int numElementosRec (BSTree<KeyValue<string, Artista*>> *arbol) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Calcula recursivamente la profundidad máxima del árbol.
	// COMPLEJIDAD: O(n)
	int profundidadRec (BSTree<KeyValue<string, Artista*>> *arbol) const;

	// PRE: arbol correctamente inicializado.
	// DESC: Recorre el árbol en post-orden para liberar la memoria de los artistas.
	// COMPLEJIDAD: O(n)
	void vaciarRec (BSTree<KeyValue<string, Artista*>> *arbol);

	// PRE: arbol correctamente inicializado.
	// DESC: Busca recursivamente el artista con mayor número de seguidores.
	// COMPLEJIDAD: O(n)
	void masSeguidoresRec (BSTree<KeyValue<string, Artista*>> *arbol, Artista *&maxArtista, int &maxSeguidores) const;

	// PRE: otroArbol correctamente inicializado.
	// DESC: Recorre en pre-orden el árbol original insertando copias.
	// COMPLEJIDAD: O(n log n)
	void copiarArbol (BSTree<KeyValue<string, Artista*>> *otroArbol);

public:

	// PRE: ---
	// DESC: Constructor por defecto. Crea un GestorArtistas con un árbol binario vacío.
	// COMPLEJIDAD: O(1)
	GestorArtistas();

	// PRE: otroGestor debe estar correctamente inicializado.
	// DESC: Constructor por copia. Realiza una copia del árbol de artistas.
	// COMPLEJIDAD: O(n log n)
	GestorArtistas(const GestorArtistas &otroGestor);

	// PRE: ---
	// DESC: Inserta un nuevo artista en el árbol binario evitando duplicados.
	// COMPLEJIDAD: O(log n)
	void insertar (string nombre, string pais, int numSeguidores);

	// PRE: ---
	// DESC: Inicia la búsqueda recursiva de un artista por nombre.
	// COMPLEJIDAD: O(log n)
	bool buscar (string nombre, Artista *&a) const;

	// PRE: ---
	// DESC: Inicia el conteo recursivo de los artistas registrados.
	// COMPLEJIDAD: O(n)
	int numElementos () const;

	// PRE: ---
	// DESC: Inicia el recorrido recursivo para mostrar artistas y la profundidad del árbol.
	// COMPLEJIDAD: O(n)
	void mostrar () const;

	// PRE: ---
	// DESC: Inicia la búsqueda recursiva e imprime el artista con más seguidores.
	// COMPLEJIDAD: O(n)
	void mostrarMasSeguidores () const;

	// PRE: ---
	// DESC: Destructor. Vacía recursivamente los artistas dinámicos y destruye el árbol.
	// COMPLEJIDAD: O(n)
	~GestorArtistas();
};

#endif /* defined*/
#endif /* GESTORARTISTAS_H_ */

