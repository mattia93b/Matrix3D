//
// Created by mattia93b on 19/05/18.
//

#ifndef MATRICE3D_H
#define MATRICE3D_H

#include <iostream>
#include <ostream>
#include <assert.h>
#include <cstddef>// ptrdiff_t
#include <iterator> // categorie degli iterator
using namespace std;

/**
@file Matrice3D.h 
@brief Dichiarazione della classe SortedArray
**/

/**
@brief Array di T

Classe che rappresenta un matrice 3D di tipo T. 
La dimensione puo' essere scelta in fase di costruzione.
**/
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///					MATRICE 2D	
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

template <typename T>
class Matrice2D {
typedef unsigned int size_type;

private:
	size_type dimX, dimY;
	int dim;
	T* array2D;

public:
	/**
		@brief Costruttore di default (METODO FONDAMENTALE)

		Costruttore di default per istanziare una Matrice 2D vuota. E' l'unico costruttore
		che puo' essere usato per create una Matrice di Matrice 2D!
	**/
	Matrice2D() : dimX(0), dimY(0), array2D(0) {

	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare una Matrice2D con una data dimensione.
		@param dimX Dimensione dell'asse X
		@param dimY Dimensione dell'asse Y   
	**/
	Matrice2D(size_type _dimY, size_type _dimX) : dimX(0), dimY(0), array2D(0) {
		try {
			this->dimX = _dimX;
			this->dimY = _dimY;
			dim = (int)(dimX * dimY);
			array2D = new T[dim];

			cout << "COSTRUTTORE DIM: " << dimX << ", " << dimY << "\n";
		} catch (...) {
			clear();
		}
	}

	/**
		@brief Copy Costructor 

		Copy Costructor. Permette di istanziare una Matrice2D uguale a quella passata come parametro.
		@param &other Matrice2D da copiare  
	**/
	Matrice2D(const Matrice2D<T> &other) : dimX(0), dimY(0), array2D(0) {
		cout << "------- copy costructor called -------" << endl;
		try {
			dimX = other.dimX;
			dimY = other.dimY;
			dim = (int)(dimX * dimY);

			array2D = new T[dim];

			for (size_t i = 0; i<(dimX*dimY); i++) {
				array2D[i] = other.array2D[i];
			}
		} catch (...) {
			clear();
		}

	}

	/**
		@brief Distruttore (METODO FONDAMENTALE)

		Distruttore. Rimuove la memoria allocata da Matrice 2D.
	**/
	~Matrice2D() {
		clear();
	}

	void clear() {
		delete[] array2D;
		dimX = 0;
		dimY = 0;
		dim = 0;
	}

	/**
		@brief Accesso ai dati in lettura (stile C++ con operatore)

		Metodo getter per leggere il valore index-esimo della Matrice. 

		@pre E' necessario che X_ < dimX
		@pre E' necessario che Y_ < dimY
		@param _X Indice X della cella della matrice da leggere
		@param _Y Indice Y della cella della matrice da leggere
	**/
	const T operator()(int _Y, int _X) const {
		assert(_X<=dimX);
		assert(_Y<=dimY);
		return array2D[_X*dimY + _Y];
	}

	/**
		@brief Accesso ai dati in scrittura (stile C++ con operatore)

		Metodo getter per scrivere il valore index-esimo della Matrice. 

		@pre E' necessario che X_ < dimX
		@pre E' necessario che Y_ < dimY
		@param _X Indice X della cella della matrice da scrivere
		@param _Y Indice Y della cella della matrice da scrivere
	**/
	T& operator()(int _Y, int _X) {
		assert(_X<=dimX);
		assert(_Y<=dimY);
		return array2D[_X*dimY + _Y];
	}




	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//							ITERATORI								 //
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	class const_iterator;
	class iterator;

	class iterator {
		T *ptr;

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef T*                        pointer;
		typedef T&                        reference;

		iterator() : ptr(0) {
		}

		iterator(const iterator &other) : ptr(other.ptr) {
		}

		iterator& operator=(const iterator &other) { ptr = other.ptr; return *this; }
		~iterator() {}
		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const { return *ptr; }
		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const { return ptr; }
		// Operatore di iterazione post-incremento
		iterator operator++(int) { iterator tmp(*this); ++ptr; return tmp; }
		// Operatore di iterazione pre-incremento
		iterator& operator++() { ++ptr; return *this; }
		// Operatore di iterazione post-incremento
		iterator operator--(int) { iterator tmp(*this); --ptr; return tmp; }
		// Operatore di iterazione pre-incremento
		iterator& operator--() { --ptr; return *this; }
		// Uguaglianza
		bool operator==(const iterator &other) const { return ptr == other.ptr; }
		// Diversita'
		bool operator!=(const iterator &other) const { return ptr != other.ptr; }
		// Solo se serve anche const_iterator aggiungere le seguenti definizioni
		friend class const_iterator;
		// Uguaglianza
		bool operator==(const const_iterator &other) const { return ptr == other.ptr; }
		// Diversita'
		bool operator!=(const const_iterator &other) const { return ptr != other.ptr; }
		// Solo se serve anche const_iterator aggiungere le precedenti definizioni
	private:
		friend class Matrice2D<T>; // !!! Da cambiare il nome!
		iterator(T *p) : ptr(p) {}
		// !!! Eventuali altri metodi privati
	}; // classe iterator
	   // Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() { return iterator(array2D); }
	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() { return iterator(array2D + dim); }



	//CONST ITERATOR
	class const_iterator {
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

		const_iterator() : ptr(0) {}
		const_iterator(const const_iterator &other) : ptr(other.ptr) {}
		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
			return *this;
		}
		~const_iterator() {}
		reference operator*() const { return *ptr; }
		pointer operator->() const { return ptr; }
		const_iterator operator++(int) { const_iterator tmp(ptr); ++ptr; return tmp; }
		const_iterator& operator++() { ++ptr; return *this; }
		const_iterator operator--(int) { const_iterator tmp(ptr); --ptr; return tmp; }
		const_iterator& operator--() { --ptr; return *this; }
		bool operator==(const const_iterator &other) const { return other.ptr == ptr; }
		bool operator!=(const const_iterator &other) const { return other.ptr != ptr; }
	private:
		const T *ptr;
		friend class Matrice2D<T>;
		const_iterator(const T*p) : ptr(p) {}
	};

	const_iterator cbegin() const { return const_iterator(array2D); }
	const_iterator cend() const { return const_iterator(array2D + dim); }



};

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///					MATRICE 3D	
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

template <typename T>
class Matrice3D {
typedef unsigned int size_type;

private:
	size_type dimX, dimY, dimZ;
	int dim;
	T* array3D;

public:

	/**
		@brief Costruttore di default (METODO FONDAMENTALE)

		Costruttore di default per istanziare una Matrice 3D vuota. E' l'unico costruttore
		che puo' essere usato per create una Matrice di Matrice 3D!
	**/
	Matrice3D() : dimX(0), dimY(0), dimZ(0), array3D(0) {

	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare una Matrice3D con una data dimensione.
		@param dimX Dimensione dell'asse X
		@param dimY Dimensione dell'asse Y 
		@param dimY Dimensione dell'asse Z   
	**/
	Matrice3D(size_type _dimZ, size_type _dimY, size_type _dimX) : dimX(0), dimY(0), dimZ(0), array3D(0) {
		try {
			this->dimX = _dimX;
			this->dimY = _dimY;
			this->dimZ = _dimZ;
			dim = (int)(dimX * dimY * dimZ);
			array3D = new T[dim];

			cout << "COSTRUTTORE DIM: " << dimX << ", " << dimY << ", " << dimZ << "\n";
		} catch (...) {
			clear();
		}
	}

	/**
		@brief Copy Costructor 

		Copy Costructor. Permette di istanziare una Matrice3D uguale a quella passata come parametro.
		@param &other Matrice3D da copiare  
	**/
	Matrice3D(const Matrice3D<T> &other) : dimX(0), dimY(0), dimZ(0), array3D(0) {
		cout << "------- copy costructor called -------" << endl;
		try {
			dimX = other.dimX;
			dimY = other.dimY;
			dimZ = other.dimZ;
			dim = (int)(dimX * dimY*dimZ);

			array3D = new T[dim];

			for (size_t i = 0; i<(dimX*dimY*dimZ); i++) {
				array3D[i] = other.array3D[i];
			}
		} catch (...) {
			clear();
		}

	}

	/**
		@brief Copy Costructor

		Copy Costructor. Permette di istanziare una Matrice3D uguale a quella 
		passata come parametro ma di un tipo diverso conversione da tipo Q a tipo T.
		@param &other Matrice3D da copiare  
	**/
	template<typename Q>
	Matrice3D(const Matrice3D<Q> &other) : dimX(0), dimY(0), dimZ(0), array3D(0) {
		cout << "------- copy costructor called 2 -------" << endl;
		try {
			dimX = other.getDimX();
			dimY = other.getDimY();
			dimZ = other.getDimZ();
			dim = (int)(dimX * dimY * dimZ);

			array3D = new T[dim];

			typename Matrice3D<Q>::const_iterator it;
			int i = 0;
			for (it = other.cbegin(); it != other.cend(); ++it) {				
				array3D[i] = static_cast<T> (*(it));
				i++;
			}

		} catch (...) {
			clear();
		}

	}


	/**
		@brief Distruttore (METODO FONDAMENTALE)

		Distruttore. Rimuove la memoria allocata da Matrice 3D.
	**/
	~Matrice3D() {
		clear();
	}

	/**
		@brief Estrazione piano bisdimensionale

		Metodo che una volta ricevuta la Z estrae l'intero piano 
		e lo inserisce in una matrice 2D

		@pre E' necessario che _Z < dimZ
		@return Matrice2D estartta dalla Matrice3D
	**/
	const Matrice2D<T> slice(int _Z) {

		Matrice2D<T>m1(dimX, dimY);
		for (unsigned x = 0; x<dimX; x++) {
			for (unsigned y = 0; y < dimY; ++y) {
				m1(x, y) = this->operator()(x, y, _Z);
			}
		}
		return m1;
	}



	void clear() {
		delete[] array3D;
		dimX = 0;
		dimY = 0;
		dimZ = 0;
		dim = 0;
	}

	/**
		@brief Accesso ai dati in lettura (stile C++ con operatore)

		Metodo getter per leggere il valore index-esimo della Matrice. 

		@pre E' necessario che X_ < dimX
		@pre E' necessario che Y_ < dimY
		@pre E' necessario che Z_ < dimZ
		@param _X Indice X della cella della matrice da leggere
		@param _Y Indice Y della cella della matrice da leggere
		@param _Z Indice Z della cella della matrice da leggere
	**/
	const T operator()(int _Z, int _Y, int _X) const {
		assert(_X<=dimX);
		assert(_Y<=dimY);
		assert(_Z<=dimZ);
		return array3D[_X*dimY*dimZ + _Y * dimZ + _Z];
	}

	/**
		@brief Accesso ai dati in scrittura (stile C++ con operatore)

		Metodo getter per scrivere il valore index-esimo della Matrice. 

		@pre E' necessario che X_ < dimX
		@pre E' necessario che Y_ < dimY
		@pre E' necessario che Z_ < dimZ
		@param _X Indice X della cella della matrice da scrivere
		@param _Y Indice Y della cella della matrice da scrivere
		@param _Z Indice Z della cella della matrice da scrivere
	**/
	T& operator()(int _Z, int _Y, int _X) {
		assert(_X<=dimX);
		assert(_Y<=dimY);
		assert(_Z<=dimZ);
		return array3D[_X*dimY*dimZ + _Y * dimZ + _Z];
	}

	/**
		@brief Restituisce dimensione X

		Metodo getter per leggere quanto vale dimX. 
	**/
	size_t getDimX() const {
		return dimX;
	}

	/**
		@brief Restituisce dimensione Y

		Metodo getter per leggere quanto vale dimY. 
	**/
	size_t getDimY() const {
		return dimY;
	}

	/**
		@brief Restituisce dimensione Y

		Metodo getter per leggere quanto vale dimY. 
	**/
	size_t getDimZ() const {
		return dimZ;
	}


	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	//							ITERATORI								 //
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	class const_iterator;
	class iterator;

	class iterator {
		T *ptr;

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef T*                        pointer;
		typedef T&                        reference;

		iterator() : ptr(0) {
		}

		iterator(const iterator &other) : ptr(other.ptr) {
		}

		iterator& operator=(const iterator &other) { ptr = other.ptr; return *this; }
		~iterator() {}
		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const { return *ptr; }
		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const { return ptr; }
		// Operatore di iterazione post-incremento
		iterator operator++(int) { iterator tmp(*this); ++ptr; return tmp; }
		// Operatore di iterazione pre-incremento
		iterator& operator++() { ++ptr; return *this; }
		// Operatore di iterazione post-incremento
		iterator operator--(int) { iterator tmp(*this); --ptr; return tmp; }
		// Operatore di iterazione pre-incremento
		iterator& operator--() { --ptr; return *this; }
		// Uguaglianza
		bool operator==(const iterator &other) const { return ptr == other.ptr; }
		// Diversita'
		bool operator!=(const iterator &other) const { return ptr != other.ptr; }
		// Solo se serve anche const_iterator aggiungere le seguenti definizioni
		friend class const_iterator;
		// Uguaglianza
		bool operator==(const const_iterator &other) const { return ptr == other.ptr; }
		// Diversita'
		bool operator!=(const const_iterator &other) const { return ptr != other.ptr; }
		// Solo se serve anche const_iterator aggiungere le precedenti definizioni
	private:
		friend class Matrice3D<T>; // !!! Da cambiare il nome!
		iterator(T *p) : ptr(p) {}
		// !!! Eventuali altri metodi privati
	}; // classe iterator
	   // Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() { return iterator(array3D); }
	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() { return iterator(array3D + dim); }



	//CONST ITERATOR
	class const_iterator {
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

		const_iterator() : ptr(0) {}
		const_iterator(const const_iterator &other) : ptr(other.ptr) {}
		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
			return *this;
		}
		~const_iterator() {}
		reference operator*() const { return *ptr; }
		pointer operator->() const { return ptr; }
		const_iterator operator++(int) { const_iterator tmp(ptr); ++ptr; return tmp; }
		const_iterator& operator++() { ++ptr; return *this; }
		const_iterator operator--(int) { const_iterator tmp(ptr); --ptr; return tmp; }
		const_iterator& operator--() { --ptr; return *this; }
		bool operator==(const const_iterator &other) const { return other.ptr == ptr; }
		bool operator!=(const const_iterator &other) const { return other.ptr != ptr; }
	private:
		const T *ptr;
		friend class Matrice3D<T>;
		const_iterator(const T*p) : ptr(p) {}
	};

	const_iterator cbegin() const { return const_iterator(array3D); }
	const_iterator cend() const { return const_iterator(array3D + dim); }


};

/**
	@brief Operatore Trasforma

	data una Matrice3D A (su tipi T) e un funtore F, 
	ritorna una nuova Matrice3D B (su tipi Q) i cui elementi 
	sono ottenuti applicando il funtore agli elementi di A
	
	@param func funzione
	@param A Matrice 3D
	@return Matrice trasformata
**/
template<typename T, typename Q>
Matrice3D<Q> trasforma(Matrice3D<T> &A, Q(*func)(const T&)) {

	Matrice3D<Q> B(A.getDimX(), A.getDimY(), A.getDimZ());

	typename Matrice3D<T>::iterator itA;
	typename Matrice3D<Q>::iterator itB = B.begin();

	for (itA = A.begin(); itA != A.end(); ++itA) {
		*(itB) = func(*(itA));
		++itB;
	}
	return B;
}


#endif //MATRICE3D_H