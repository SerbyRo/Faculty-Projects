#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void codarePrufer(vector<int> tati, vector<int>& fii, vector<int>& prufer, int noduri)
{

    bool gasit = false;
    while (!gasit)
    {
        for (int i = 0; i < noduri; i++)
        {
            gasit = true;
            if (fii[i] == 0 && tati[i] != -1)
            {
                gasit = false;
                fii[i]--;
                fii[tati[i]]--;
                prufer.push_back(tati[i]);
                break;
            }
        }
    }

}

int main(int argc, char* argv[])
{
    int noduri, i, x;
    vector<int>tati;
    vector<int>prufer;
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    fin >> noduri;
    for (i = 0; i < noduri; i++)
    {
        fin >> x;
        tati.push_back(x);
    }
    vector<int>fii(noduri, 0);
    for (i = 0; i < noduri; i++)
    {
        if (tati[i] != -1)
            fii[tati[i]]++;
    }
    // frunzele vor avea la fii[i] valoarea 0
    codarePrufer(tati, fii, prufer, noduri);
    fout << prufer.size() << "\n";
    for (auto el : prufer)
        fout << el << " ";
    return 0;
}
