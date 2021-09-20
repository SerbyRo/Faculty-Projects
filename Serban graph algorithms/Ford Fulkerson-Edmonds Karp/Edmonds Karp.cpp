bool DFS(int edges, int start, int finish, int** matrix, int* tree, int* use)
{
	if (start == finish)
	{
		return true;
	}
	use[start] = true;
	for (int i = 0;i < edges;i++)
	{
		if (use[i] == 0 && matrix[start][i])
		{
			tree[i] = start;
			if (DFS(edges, i, finish, matrix, tree, use))
			{
				return true;
			}
		}
	}
	return false;
}

#include <string.h>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>& graf, int sursa, int destinatie, vector<int>& tree, int Vertices) {

    vector<bool> use(Vertices, 0);

    queue<int> coada;
    coada.push(sursa);
    use[sursa] = true;
    tree[sursa] = -1;

    while (!coada.empty()) {
        int nod = coada.front();
        coada.pop();

        for (int i = 0; i < Vertices; i++) {
            if (use[i] == false && graf[nod][i] > 0) {
                coada.push(i);
                tree[i] = nod;
                use[i] = true;
            }
        }
    }

    return (use[destinatie] == true);
}


int edmondsKarp(vector<vector<int>>& graf, int sursa, int destinatie, int Vertices) {
    int u, v;

    vector<vector<int>> grafrezidual(Vertices);

    for (int i = 0; i < Vertices; i++) {
        for (int j = 0; j < Vertices; j++) {
            grafrezidual[i].push_back(0);
        }
    }

    for (u = 0; u < Vertices; u++)
        for (v = 0; v < Vertices; v++)
            grafrezidual[u][v] = graf[u][v];

    vector<int> tree(Vertices);

    int flux_maxim = 0;

    
    while (bfs(grafrezidual, sursa, destinatie, tree, Vertices)) {
        int flux = 99999;
        for (v = destinatie; v != sursa; v = tree[v]) {
            u = tree[v];
            flux = min(flux, grafrezidual[u][v]);
        }

        for (v = destinatie; v != sursa; v = tree[v]) {
            u = tree[v];
            grafrezidual[u][v] -= flux;
            grafrezidual[v][u] += flux;
        }
        flux_maxim += flux;

    }

    return flux_maxim;
}
ifstream fin("graf.txt");
ofstream fout("graf.out");
int main() {
    int Ncladiri, Camine, Drumuri, nodi, node, cost;
    fin >> Ncladiri;
    fin >> Camine;
    fin >> Drumuri;
    vector<vector<int>> graf(Ncladiri);
    for (int i = 0; i < Ncladiri; i++) {
        for (int j = 0; j < Ncladiri; j++) {
            graf[i].push_back(0);
        }
    }
    for (int i = 0; i < Drumuri; i++) {
        fin >> nodi>> node >> cost;
        graf[nodi][node] = cost;
    }
    int suma = 0;
    for (int i = 0; i < Camine; i++) {
        suma = suma + edmondsKarp(graf, i, Ncladiri - 1, Ncladiri);
    }
    fout << suma << endl;
    for (int i = 0; i < Camine; i++) {
        fout << edmondsKarp(graf, i, Ncladiri - 1, Ncladiri) << " ";
    }
}
