// Lab2pb4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;

ifstream f("graf.txt");


void print_matrix(int** mat, int n, int m)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int** mat,vector<int>v[], int n, int start)
{
    queue <int> q;
    int* use = new int[n];
    int* d = new int[n];
    for (int i = 0;i < n;i++)
    {
        use[i] = 0;
    }
    use[start] = 1;
    d[start] = 0;
    cout << start << " ";
    q.push(start);
    while (!q.empty())
    {
        int curent = q.front();
        q.pop();
        for (auto next : v[curent])
        {
            if (use[next] == 0)
            {
                cout << next << " ";
                use[next] = 1;
                d[next] = d[curent] + 1;
                q.push(next);
            }
        }
    }
    cout << endl;
    for (int i = 0;i < n;i++)
    {
        cout << "Distanta de la nodul sursa " << start << " la nodul " << i << " este " << d[i] << endl;
    }
    cout << endl;
    delete[] use;
    delete[] d;
    cout << endl;

}





int main()
{
    int** mat, n, source,x,y;
    vector <int>v[10];
    f >> n;
     mat = new int* [n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }
    while (f >> x >> y)
    {
        cout << x << " " << y << "\n";
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    cout << "Nodul sursa este:";cin >> source;
    bfs(mat, v, n, source);
    return 0;
}


