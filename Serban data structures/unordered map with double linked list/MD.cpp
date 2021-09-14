#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

Nod::Nod(TElem e, PNod urm, PNod prec) {
	//complexitate theta(1)
	this->e = e;
	this->urm = urm;
	this->prec = prec;
}

TElem Nod::element() {
	//complexitate theta(1)
	return e;
}

PNod Nod::urmator() {
	//complexitate theta(1)
	return urm;
}

PNod Nod::precedent() {
	//complexitate theta(1)
	return prec;
}

MD::MD() {
	//complexitate theta(1)
	prim = nullptr;
	ultim = nullptr;
}


void MD::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	//complexitate O(n)
	TElem e;
	e.first = c;
	e.second = v;
	PNod q = new Nod(e, nullptr, nullptr);
	if (vid() == true) {
		
		q->urm = prim;
		q->prec = ultim;
		ultim = q;
		prim = q;
	
	}
	else {
		ultim->urm = q;
		q->prec = ultim;
		ultim = q;
		ultim->urm = nullptr;
	}

	size++;
}


bool MD::sterge(TCheie c, TValoare v) {
	/* de adaugat */
	//complexitate theta (n)
	PNod p= prim;
	if (p == nullptr)
		return false;
	if (p->e.first == c && p->e.second == v && size == 1) {
		delete p;
		prim = nullptr;
		ultim = nullptr;
		size--;
		return true;
	}
	if(p->e.first == c && p->e.second == v && size > 1){
		p->urm->prec = nullptr;
		prim = p->urm;
		delete p;
		size--;
		return true;
	}
	p = p->urm;
	while (p != nullptr) {
		if (p->e.first == c && p->e.second == v && p->urm != nullptr) {
			PNod c = p->prec;
			p = p->urm;
			
			c->urm = p;

			delete p->prec;

			p->prec = c;

			
			size--;
			return true;
		}
		if (p->e.first == c && p->e.second == v && p->urm == nullptr) {
			
			PNod c = p->prec;
			c->urm = nullptr;

			ultim = c;
			delete p;
			size--;
			return true;
		}
		p = p->urm;
	}

	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	/* de adaugat */
	//complexitate theta O(n)
	vector<TValoare> valori;
	PNod p = prim;
	while (p != nullptr) {
		if (p->e.first == c) {
			valori.push_back(p->e.second);
		}
		p = p->urm;
	}
	return valori;
}


int MD::dim() const {
	/* de adaugat */
	//complexitate theta(1)
	return size;
}


bool MD::vid() const {
	/* de adaugat */
	//complexitate theta(1)
	//complex
	if( prim == nullptr)
		return true;
	return false;
}

IteratorMD MD::iterator() const {
	//complexitate theta(1)
	return IteratorMD(*this);
}


MD::~MD() {
	
	/* de adaugat */
	//complexitate theta(1)
}

