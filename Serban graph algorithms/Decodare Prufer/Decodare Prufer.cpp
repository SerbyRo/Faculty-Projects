#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

void afisare(vector<int>k, int n) {
    g << n << endl;
    for (int i = 0; i < n; i++)
        g << k.at(i) << " ";
    g << endl;
}

int celMaiMic(vector<int> k,int n,vector<int> frecventa,int x) {
    for (int i = x; i <= n; i++) {
        if (frecventa.at(i) == 0)
            return i;
    }
    cout << "da";
    return -11;
}

void DecodarePrufer(ostream& g, vector<int> noduri, vector<int> frunze, int n, vector<int> frecventa) {
    int x, y, zx = 0, zy = 0, ok = 1;
    for (int i = 0; i < n; ++i) {
        x = frunze.at(0); //primul nod din lista
        if(zx<zy && frecventa.at(zx)==0)
            y = celMaiMic(frunze, n, frecventa,zx);
        else
            y = celMaiMic(frunze, n, frecventa, zy);
        noduri.at(y) = x;
        //cout << x << " parintele lui " << y << endl;
        frunze.erase(frunze.begin() + 0);
        frunze.push_back(y);
        frunze.at(n - 1) = y;
        frecventa.at(x)--;
        frecventa.at(y)++;
        //afisare(frunze, n);
        zx = x; //retinem parintele precedent
        zy = y; //retinem fiul precedent
    }

    afisare(noduri, n + 1);
}

int main()
{
    string fisier1, fisier2;
    int n, nod;

    /*
    cout << "Dati fisierul pentru date de intrare: ";
    cin >> fisier1;
    cout << "Dati fisierul pentru date de iesire: ";
    cin >> fisier2;
    ifstream f(fisier1);
    ofstream g(fisier2);
    */

    vector<int> frunze;
    f >> n;
    vector<int> noduri(n + 1, -1);
    vector<int> frecventa(n + 1, 0);

    while (f >> nod) {
        frunze.push_back(nod);
        frecventa.at(nod)++;
    }

    DecodarePrufer(g, noduri, frunze, n,frecventa);

    std::cout << "Hello World!\n";
}
