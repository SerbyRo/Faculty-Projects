#include <fstream>
	#include <vector>
	#include <queue>
	
	using namespace std;
	
	ifstream fin("bellmanford.in");
	ofstream fout("bellmanford.out");
	
	const int nmax=50000, inf=(1<<30)-1;
	
	int d[nmax+1], u[nmax+1];
	
	struct str{
	int x,y;
	};
	
	vector <str> g[nmax+1];
	
	queue <int> q;
	
	int main(){
	int n,m;
	fin>>n>>m;
	for(int i=1;i<=m;i++){
	int x,y,z;
	fin>>x>>y>>z;
	str aux;
	aux.x=y;
	aux.y=z;
	g[x].push_back(aux);
	}
	for(int i=1;i<=n;i++){
	d[i]=inf;
	}
	d[1]=0;
	q.push(1);
	int ok=0;
	while(q.empty()==0&&ok==0){
	int x=q.front();
	q.pop();
	for(int i=0;i<int(g[x].size());i++){
	int xn=g[x][i].x;
	int yn=g[x][i].y;
	if(d[x]+yn<d[xn]){
	u[xn]++;
	if(u[xn]==n){
	ok=1;
	}
	d[xn]=d[x]+yn;
	q.push(xn);
	}
	}
	}
	if(ok==1){
	fout<<"Ciclu negativ!";
	}else{
	for(int i=2;i<=n;i++){
	fout<<d[i]<<" ";
	}
	}
	return 0;
	}
