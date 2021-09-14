#pragma once
#include "Masina.h"
#include "RepoMasina.h"
class ActiuneUndo
{
private:

public:
	virtual void doUndo() = 0;
	//destructorul e virtual 
	virtual ~ActiuneUndo() {};
};

class UndoAdauga :public ActiuneUndo {
private:
	Masina masinaadaugata;
	RepoMasina& repomasini;
public:
	UndoAdauga(RepoMasina& repomasini, Masina& mas) :repomasini{ repomasini }, masinaadaugata{ mas }{

	}
	void doUndo() override {
		repomasini.deleterepo(masinaadaugata);
	}
};

class UndoModifica :public ActiuneUndo {
private:
	Masina masinamodificata;
	RepoMasina& repomasini;
public:
	UndoModifica(RepoMasina& repomasini, Masina& mas) :repomasini{ repomasini }, masinamodificata{ mas }{

	}
	void doUndo() override {
		repomasini.updaterepo(masinamodificata);
	}
};

class UndoSterge :public ActiuneUndo {
private:
	Masina masinastearsa;
	RepoMasina& repomasini;
public:
	UndoSterge(RepoMasina& repomasini, Masina& mas) :repomasini{ repomasini }, masinastearsa{ mas }{

	}
	void doUndo() override{
		repomasini.store(masinastearsa);
	}
};
