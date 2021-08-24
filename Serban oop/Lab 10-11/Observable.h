#pragma once
#include <vector>
#include "Observer.h"
#include <algorithm>
using std::vector;
class Observable
{
private:
	vector<Observer*> observers;
public:
	Observable() {};
	void addObserver(Observer* obs)
	{
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs)
	{
		observers.erase(std::remove(begin(observers), end(observers), obs), observers.end());
	}
	~Observable() {};
protected:
	void notifyObserver()
	{
		for (auto obs : observers)
		{
			obs->update();
		}
	}
};

