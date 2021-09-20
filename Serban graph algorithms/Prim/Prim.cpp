ifstream fin("apm.in");
	ofstream fout("apm.out");
	struct muchie
	{
	int x, y, cost;
	} aux;
	int N, M;
	int total;
	int tata[Nmax];
	int rang[Nmax];
	struct rezultate
	{
	int x, y;
	} keep;
	vector<rezultate>rez;
	int cmp(muchie a, muchie b)
	{
	return a.cost < b.cost;
	}
	vector<muchie>v;
	int father(int nod)
	{
	while(tata[nod] != nod)
	nod = tata[nod];
	return nod;
	}
	void unire(int x, int y)
	{
	if(rang[x] < rang[y])
	tata[x] = y;
	if(rang[y] < rang[x])
	tata[y] = x;
	if(rang[x] == rang[y])
	{
	tata[x] = y;
	rang[y]++;
	}
	}
	void afisare()
	{
	fout<<total<<"\n";
	fout<<rez.size()<<"\n";
	for(auto i=0; i<rez.size(); i++)
	{
	fout<<rez[i].x<<" "<<rez[i].y<<"\n";
	}
	}
	void rezolvare()
	{
	int contor = 0;
	int tatal_x, tatal_y;
	for(int i=0; i<M; i++)
	{
	tatal_x = father(v[i].x);
	tatal_y = father(v[i].y);
	
	if(tatal_x != tatal_y)
	{
	unire(tatal_x, tatal_y);
	
	++contor;
	keep.x = v[i].x;
	keep.y = v[i].y;
	
	rez.push_back(keep);
	
	total += v[i].cost;
	if(contor == N - 1)
	{
	break;
	}
	
	}
	}
	afisare();
	}
	void initializare()
	{
	for(int i=1; i<=N; i++)
	{
	tata[i] = i;
	rang[i] = 1;
	}
	}
	void citire()
	{
	fin>>N>>M;
	int a, b, c;
	for(int i=1; i<=M; i++)
	{
	fin>>a>>b>>c;
	aux.x = a;
	aux.y = b;
	aux.cost = c;
	v.push_back(aux);
	}
	sort(v.begin(), v.end(), cmp);
	
	initializare();
	rezolvare();
	}
	int main()
	{
	citire();
	return 0;
	}
