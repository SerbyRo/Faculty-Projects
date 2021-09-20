#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 100000;
vector<int>lungime;

void Moore(vector<vector<int>> lista_adiacenta, int nr_varfuri, int varf_sursa, int varf_dest) {
    vector<int> parinti(nr_varfuri);
    vector<int> lungime_drum(nr_varfuri);

    lungime_drum[varf_sursa - 1] = 0;
    for (int i = 0; i < nr_varfuri; i++) {
        if (i != varf_sursa - 1) {
            lungime_drum[i] = INF;
        }
        parinti[i] = -1;
    }

    queue<int> q;
    q.push(varf_sursa);
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (auto y : lista_adiacenta[x - 1]) {
            if (lungime_drum[y - 1] == INF) {
                parinti[y - 1] = x;
                lungime_drum[y - 1] = lungime_drum[x - 1] + 1;
                q.push(y);
            }
        }
    }
    lungime.push_back(lungime_drum[varf_dest - 1]);
    if (lungime_drum[varf_dest - 1] == INF)
    {
        cout << "Nu exista!\n";
        return;
    }
    int i = varf_dest - 1;
    vector<int> solutie;
    while (parinti[i] != -1)
    {
        solutie.push_back(i + 1);
        i = parinti[i] - 1;
    }
    solutie.push_back(i + 1);
    for (i = lungime_drum[varf_dest - 1]; i >= 0; i--) 
        cout << solutie[i] << " ";
    cout << endl;
}

int main() {
    // citesc muchiile din fisier
    ifstream fin("graf.txt");
    int nr_varfuri;
    fin >> nr_varfuri;
    vector<vector<int>> lista_adiacenta;
    for (int i = 0; i < nr_varfuri; i++)
    {
        vector<int>tmp;
        lista_adiacenta.push_back(tmp);
    }
    // creare lista adiacenta
    int x, y;
    while (fin >> x >> y) {
        lista_adiacenta[x - 1].push_back(y);
    }
    fin.close();

    // afisare lista adiacenta
    cout << "\nLista de adiacenta: \n";
    for (int i = 0; i < nr_varfuri; i++)
    {
        cout << i + 1 << ": ";
        for (auto el : lista_adiacenta[i])
        {
            cout << el << " ";
        }
        cout << "\n";
    }
    int varf_sursa, varf_dest;
    cout << "\nIntroduceti varful sursa: ";
    cin >> varf_sursa;
    //cout << "\nIntroduceti varful destinatie: ";
    //cin >> varf_dest;
    for (int i = 1; i <= nr_varfuri; i++) {
        cout << varf_sursa <<"-"<< i << ": ";
        Moore(lista_adiacenta, nr_varfuri, varf_sursa, i);
    }
    cout << endl;
    cout << "Drumurile: ";
    for (int i = 0; i < nr_varfuri; i++)
    {
        if (lungime[i] == INF) {
            cout << "INF" << " ";
        }
        else {
            cout << lungime[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

