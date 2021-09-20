#include <stdlib.h>

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

string decode(string cod, nod* root) {
    string mesaj;
    nod* poz = root;
    for (auto c : cod) {
        if (c == '0') {
            poz = poz->stanga;
        }
        if (c == '1') {
            poz = poz->dreapta;
        }
        if (poz->dreapta == nullptr && poz->stanga == nullptr) {
            mesaj += poz->c;
            poz = root;
        }
    }
    return mesaj;
}

int main(char* argc, char* argv[]) {

    {
        //ifstream f(argv[1]);
        //ofstream g(argv[2]);

        unordered_map<char, string> tabela;
        vector<perechi> frecvente;
        string cod = "";
        perechi temp;
        char c;
        int nr, fr;
        f >> nr;
        for (int i = 0; i < nr; i++) {
            f >> noskipws >> c;
            f >> noskipws >> c;
            f >> skipws >> fr;
            temp.first = c;
            temp.second = fr;
            frecvente.push_back(temp);
        }

        f >> cod;
        nod* root = generare_arbore_huffman(frecvente);
        g << decode(cod, root);
        stergere_arbore_huffman(root);

        f.close();
        g.close();

    }

    std::cout << "Hello World!\n";

    return 0;
}
