//#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <fstream>

#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

#include <algorithm>

using namespace std;

typedef pair<char, int> perechi;
ifstream f("date.in");
ofstream g("date.out");

struct nod {
    char c;
    int freq = 0;
    nod* stanga = nullptr, * dreapta = nullptr;

};

nod* generare_arbore_huffman(const vector<perechi>& f) {

    auto comp = [](nod* a, nod* b) {if (a->freq == b->freq) { return int(a->c) > int(b->c); } return a->freq > b->freq; };

    priority_queue<nod*, vector<nod*>, decltype(comp)> q(comp);
    nod* n, * a, * b;

    for (auto elem : f) {
        n = new nod;
        n->c = elem.first;
        n->freq = elem.second;
        q.push(n);
    }

    while (q.size() > 1) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();

        n = new nod;
        n->c = min(a->c, b->c);
        n->freq = a->freq + b->freq;
        n->stanga = a;
        n->dreapta = b;
        q.push(n);

    }

    n = q.top();
    return n;
}

void stergere_arbore_huffman(nod* n) {

    if (n->stanga != nullptr) {
        stergere_arbore_huffman(n->stanga);
    }
    if (n->dreapta != nullptr) {
        stergere_arbore_huffman(n->dreapta);
    }
    delete n;
}

void parcurgere_arbore(nod* n, string code, unordered_map<char, string>& t) {

    if (n->stanga == nullptr && n->dreapta == nullptr) {
        t[n->c] = code;
    }
    if (n->stanga != nullptr) {
        parcurgere_arbore(n->stanga, code + "0", t);
    }
    if (n->dreapta != nullptr) {
        parcurgere_arbore(n->dreapta, code + "1", t);
    }
}

void generare_cod(const vector<perechi>& f, unordered_map<char, string>& t) {

    nod* tree = generare_arbore_huffman(f);
    parcurgere_arbore(tree, "", t);
    stergere_arbore_huffman(tree);
}

string encode(string m, unordered_map<char, string>& t) {
    string codat = "";
    for (auto elem : m) {
        codat += t[elem];
    }
    return codat;
}

int main(char* argc, char* argv[]) {

    {
        //ifstream f(argv[1]);
        //ofstream g(argv[2]);

        unordered_map<char, string> tabela;
        vector<perechi> frecvente;
        string mesaj = "";
        perechi temp;
        char c;

        auto fnc_cauta = [&c](perechi x) {return c == x.first; };
        auto fnc_comp = [](perechi a, perechi b) {return a.first < b.first; };

        while (f >> noskipws >> c) { //parcurgem si spatiile

            mesaj += c;
            auto poz = find_if(frecvente.begin(), frecvente.end(), fnc_cauta);
            if (poz == frecvente.end()) {
                temp.first = c;
                temp.second = 1;
                frecvente.push_back(temp);
            }
            else
            {
                (*poz).second++;
            }

        }

        sort(frecvente.begin(), frecvente.end(), fnc_comp);

        g << frecvente.size() << '\n';
        for (auto x : frecvente) {
            g << x.first << " " << x.second << '\n';
        }

        generare_cod(frecvente, tabela);
        g << encode(mesaj, tabela);

        g.close();
        f.close();

    }

    cout << "Hello World!\n";

    //_CrtDumpMemoryLeaks();
    return 0;
}
