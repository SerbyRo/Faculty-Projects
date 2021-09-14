#pragma once
#include "Masina.h"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ostream;

class ValidateException {
private:
	vector<string>message;
public:
	ValidateException(const vector<string>& erori) :message{ erori } {}
	friend ostream& operator<<(ostream& out, const ValidateException& exceptie);
};

ostream& operator<<(ostream& out, const ValidateException& exceptie);

class ValidateMasina {
public:
	void valideazamasina(const Masina& mas);
};
