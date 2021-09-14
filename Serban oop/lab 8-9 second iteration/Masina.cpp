#include "Masina.h"

bool cmpnrinmatriculare(const Masina& mas1, const Masina& mas2)
{
	return mas1.getnrinmatriculare() < mas2.getnrinmatriculare();
}

bool cmptip(const Masina& mas1, const Masina& mas2)
{
	return mas1.gettip() < mas2.gettip();
}
bool Masina::egal(const Masina& ot) const {
	return (this->nrinmatriculare == ot.getnrinmatriculare());
}

//void Masina::setproducator(const string prod)
//{
//	this->producator = prod;
//}
//
//void Masina::settip(const string tip1)
//{
//	this->tip = tip;
//}
//
//void Masina::setmodel(const string model1) {
//	this->model = model;
//}