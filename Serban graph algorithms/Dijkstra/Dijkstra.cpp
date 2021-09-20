#include <iostream>
	#include <fstream>
	#include <queue>
	#include <vector>
	
	#define inf 2147483647
	#define MX 50001
	
	using namespace std;
	
	ifstream fin("dijkstra.in");
	ofstream fout("dijkstra.out");
	
	int n, m, d[MX];
	vector < pair<int,int> > v[MX];
	bool in[MX];
	struct comp
	{
	bool operator()(int x, int y)
	{
	return d[x]>d[y];
	}
	};
	priority_queue <int, vector<int>, comp> q;
	
	void citire()
	{
	fin>>n>>m;
	int x, y, cost;
	for(int i=1; i<=m; i++)
	{
	fin>>x>>y>>cost;
	v[x].push_back({y,cost});
	}
	fin.close();
	}
	
	void dijkstra(int sursa)
	{
	for(int i=1; i<=n; i++)
	d[i]=inf;
	d[sursa]=0;
	q.push(sursa);
	in[sursa]=true;
	int curent, vecin, cost;
	while(!q.empty())
	{
	curent=q.top();
	q.pop();
	in[curent]=false;
	for(int i=0; i<v[curent].size(); i++)
	{
	vecin=v[curent][i].first;
	cost=v[curent][i].second;
	if(d[curent]+cost<d[vecin])
	{
	d[vecin]=d[curent]+cost;
	if(in[vecin]==false)
	{
	q.push(vecin);
	in[vecin]=true;
	}
	}
	}
	}
	}
	
	void afisare()
	{
	for(int i=2; i<=n; i++)
	if(d[i]==inf)
	fout<<0<<' ';
	else
	fout<<d[i]<<' ';
	fout.close();
	}
	int main()
	{
	citire();
	dijkstra(1);
	afisare();
	return 0;
	}
