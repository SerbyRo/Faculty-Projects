#include <iostream>
#include <fstream>
using namespace std;

ifstream f("graf.txt");
int use[10], t[10], mat[10][10],n; 
void DFS(int x) {
	use[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (mat[x][i] == 1 && !use[i]) {
			DFS(i);
		}
	}
}

int conex() {
	DFS(1);
	for (int i = 1; i <= n; i++) {
		if (!use[i]) {
			return 0;
		}
	}
	return 1;
}


int main()
{
	f >> n;
	cout << "Numarul de noduri este: " << n << "\n";

	//citire si afisare matrice de adiacenta
	cout << "Matricea de adiacenta este:\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f >> mat[i][j];
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	if (conex() == 0) {
		cout << "Graful nu este conex\n";
	}
	else {
		cout << "Graful este conex\n";
	}

	return 0;
}