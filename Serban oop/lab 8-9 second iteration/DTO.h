#pragma once

#include <string>
#include <assert.h>


using std::string;


/*
* clasa DTO care primeste un odata transfer object folosit pentru a crea raportul cerut in clasa
* atributele dto-ului sunt modelul masinii si numarul de masini din fiecare model
*/
class DTO
{
private:
	string model;
	int count;
public:
	DTO() = default;
	DTO(const string model) :model{ model } {
		count = 1;
	}
	void increment() noexcept {
		count++;
	}
	string getModel() const {
		return model;
	}
	int getCount() const noexcept {
		return count;
	}
};

void testDTO();


