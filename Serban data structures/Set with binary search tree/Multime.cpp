#include "Multime.h"
#include "IteratorMultime.h"

#include <queue>
#include <iostream>

using namespace std;

Nod::Nod(TElem elem, PNod stanga, PNod dreapta) {
    this->elem = elem;
    this->stanga = stanga;
    this->dreapta = dreapta;
}

TElem Nod::getelement() const  {
    return elem;
}
PNod Nod::getstanga() const {
    return stanga;
}
PNod Nod::getdreapta() const {
    return dreapta;
}


bool rel(TElem e1, TElem e2) {
    if (e1 <= e2) {
        return true;
    }
    else {
        return false;
    }
}

Multime::Multime() {
    //complexitate theta(1)
    this->radacina = nullptr;
}
// Determina nodul minim
PNod Multime::nod_minim(PNod nod) {
    //complexitate O(h)
    while (nod->getstanga() != nullptr) {
        nod = nod->stanga;
    }
    return nod;
}

// adaugare recursiva(nu o folosesc)
PNod Multime::adauga_recursiv(PNod pnod, TElem elem)
{
    //complexitate O(h)
    // daca avem multimea goala, doar cream radacina 
    if (pnod == nullptr) {
        pnod= new Nod(elem, nullptr, nullptr);
        return pnod;
    }
    // daca elementul pe care dorim sa il adaugam este < elem curent, adaugam in stanga
    else {
        if (elem < pnod->elem)
            pnod->stanga = adauga_recursiv(pnod->stanga, elem);
        // daca elementul pe care dorim sa il adaugam este > elem curent, adaugam in dreapta
        else pnod->dreapta = adauga_recursiv(pnod->dreapta, elem);
    }
    return pnod;
}

PNod Multime::sterge_recursiv(PNod pnod, TElem elem) {
    //complexitatea O(h)
   
    if (pnod == nullptr)
        return pnod;
    else {
        // am gasit elementul
        if (elem == pnod->elem) {
            // 2. nodul are 2 copii
            if (pnod->stanga != nullptr && pnod->dreapta != nullptr) {
                PNod nodminim = nod_minim(pnod->dreapta);
               
                pnod->elem = nodminim->elem;
                pnod->dreapta = sterge_recursiv(pnod->dreapta, pnod->elem);
            }
            else {  // 3. nodul are un copil
                PNod sters = pnod;
                PNod returnat;
                
                if (pnod->stanga == nullptr) {
                    returnat = pnod->dreapta;
                }
                else {
                    returnat = pnod->stanga;
                }
                delete sters;
                return returnat;
            }

        }   // daca nu am gasit elementul la nodul actual
        
        else if (rel(elem, pnod->elem)) {
            pnod->stanga = sterge_recursiv(pnod->stanga, elem);
            return pnod;
        }
        else {
            pnod->dreapta = sterge_recursiv(pnod->dreapta, elem);
            return pnod;
        }
    }
}

PNod Multime::cauta_recursiv(PNod pnod, TElem elem) const {
    // suntem deja la nodul respectiv
    //complexitate O(h)
    if (pnod == nullptr || pnod->elem == elem)
        return pnod;
   
    if (rel(elem, pnod->elem)) {
        return cauta_recursiv(pnod->stanga, elem);
    }
    return cauta_recursiv(pnod->dreapta, elem);
}


bool Multime::adauga(TElem elem) {
    //complexitate O(h)
    PNod nou = new Nod(elem, nullptr, nullptr);
    if (radacina == nullptr) {
        radacina = nou;
        return true;
    }
    else {
        PNod curent = radacina;
        PNod parinte = nullptr;

        while (1) {
            parinte = curent;
            // incepem cu radacina, daca exista deja elementul nu mai adaugam si stergem nodul
            if (elem == parinte->elem) {
                delete nou;
                return false;
            }

            if (elem <= parinte->elem) { // incercam adaugarea in stanga conform relatiei
                curent = curent->stanga;
                if (curent == nullptr) {
                    parinte->stanga = nou;
                    return true;
                }
            }
            else { // incercam adaugarea in dreapta conform relatiei
                curent = curent->dreapta;

                if (curent == nullptr) {
                    parinte->dreapta = nou;
                    return true;
                }
            }
        }
    }
}


bool Multime::sterge(TElem elem) {
    //complexitate O(h)
    if (cauta(elem)) {
        radacina = sterge_recursiv(radacina, elem);
        return true;
    }
    else {
        return false;
    }
}


bool Multime::cauta(TElem elem) const {
    //complexitate O(h)
    if (cauta_recursiv(radacina, elem) == nullptr) {
        return false;
    }
    return true;
}


int Multime::dim() const {
    //complexitate O(n) unde n e numarul de noduri
    int lungime = 0;
    IteratorMultime it = iterator();
    while (it.valid()) {
        lungime++;
        it.urmator();
    }
    return lungime;
}


bool Multime::vida() const {
    //complexitate theta(1)
    if (radacina == nullptr)
        return true;
    return false;
}

// nu o mai folosesc
void Multime::distrug_recursiv(PNod pnod) {
    //complexitate O(h)
    if (pnod != nullptr) {
        distrug_recursiv(pnod->getstanga());
        distrug_recursiv(pnod->getdreapta());
        delete pnod;
    }
}

// Implementam o coada care sa retina tot arborele
Multime::~Multime() {
    queue<PNod> q;
    if (radacina) {
        q.push(radacina);
    }
    while (!q.empty()) {
        PNod newnod = q.front();
        q.pop();
        if (newnod->stanga != nullptr) {
            q.push(newnod->stanga);
        }
        if (newnod->dreapta != nullptr) {
            q.push(newnod->dreapta);
        }
        delete newnod;
    }
}

IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}

/*
* complexitate 
* n- numarul de noduri ai arborelui
* h- inaltimea arborelui
* caz defavorabil theta(n)
* caz favorabil theta(n)
* caz mediu theta(n)
* caz overall theta(n)
*/
void Multime::intersectie(const Multime& mul)
{
    IteratorMultime iter = iterator();
    iter.prim();
    while (iter.valid())
    {
        TElem element = iter.element();
        PNod cautat1 = mul.cauta_recursiv(mul.radacina, element);
        PNod cautat2 = cauta_recursiv(radacina, element);
        if (cautat1 == nullptr &&cautat2 != nullptr)
        {
            if (sterge(element))
            {
                PNod sters = sterge_recursiv(radacina, element);
                //sterge(sters->getelement());
            }
        }
        iter.urmator();
    }
}

/*
* Pseudocod :
* pre m-multime
*     mul-multime
* post m'=m de tip multime unde m' are proprietatea ceruta 
* m' intersectat cu mul
* 
* Subalgoritm intersectie(m,mul)
*   IteratorMultime iter=iterator(m)
*   iter.prim
*   cat timp iter.valid executa
*     TElem element=iter.element
*     PNod cautat1 = mul.cauta_recursiv(mul.radacina,element)
*     PNod cautat2 = m.cauta_recursiv(m.radacina, element);
*     daca cautat1 != nullptr si cautat2 != nullptr atunci
*          daca m.sterge(element) atunci
*            PNod sters =m.sterge_recursiv(radacina,element)
*            sterge(sters->getelement())
*     sfDaca
*   iter.urmator
*   sfCatTimp
* sfSubalgoritm
*/

