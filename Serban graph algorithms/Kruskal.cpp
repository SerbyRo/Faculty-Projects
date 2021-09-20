#include <bits/stdc++.h>

using namespace std;

#define nmax 100001

ifstream fin("kruskal.in");
ofstream fout("kruskal.out");

vector < tuple < int , int , int  > > muchie;
vector < pair < int , int > > sol;

int n,m,cost,k;


int nivel[nmax],tata[nmax];

bool cmp(tuple < int , int , int  > st, tuple < int , int , int  > dr)
{
      return (get<2>(st)<get<2>(dr));

}

void Read()
{
    fin>>n>>m;

    int x,y,c;

    for(int i=1;i<=m;i++)
    {
        fin>>x>>y>>c;
        muchie.push_back(make_tuple(x,y,c));
    }

    sort(muchie.begin(),muchie.end(),cmp);




     for(int i=1;i<=n;i++)
     {
         tata[i]=i;
         nivel[i]=1;
     }

}


int Find(int x)
{
    while(tata[x]!=x)
        x=tata[x];

    return x;
}

void Unite(int x,int y )
{
    if(nivel[x]>nivel[y])
    {
        tata[y]=x;
    }
    else if(nivel[x]<nivel[y])
    {
        tata[x]=y;
    }
    else
    {
        nivel[y]++;
        tata[x]=y;

    }

}


void Solve()
{

   for(vector < tuple < int , int , int  > > :: iterator it = muchie.begin();it!=muchie.end();it++)
    {
        int A=Find( get<0>(*it) );
        int B=Find( get<1>(*it) );
        if( A != B )
        {

            Unite(A,B);
            cost+=get<2>(*it);

            sol.push_back(make_pair(get<0>(*it), get<1>(*it)));

        }

    }

}


int main()
{
    Read();

    Solve();

    fout<<cost<<"\n";


    for(vector < pair < int , int > > :: iterator it = sol.begin();it!=sol.end();it++)
         fout<<it->first<<" "<<it->second<<"\n";




    return 0;
}
