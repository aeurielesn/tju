#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-10
#define INF 0x3F3F3F3F
#define MAX 200

int x, y;

int dist(pair<int,int> a)
{
   return  (int)abs(a.first-x) + (int)abs(a.second-y);
}

bool cmp(pair<int,int> a, pair<int,int> b)
{
   return dist(a)<dist(b);
}

int main()
{
   int N, k, sz;
   scanf("%d",&N);
   vector< pair<int,int> > V(N*N+1);
   vector< vector<int> >  M(N+1, vector<int>(N+1, 0));
   sz = 0;
   FOR(i,N)
   {
      FOR(j,N)
      {
         scanf("%d",&k);
         if(k!=0)
         {
            M[i][j] = k;
            V[sz].first = i;
            V[sz].second = j;
            ++sz;
         }
      }
   }

   FOR(i,N)
   {
      FOR(j,N)
      {
         if(!M[i][j])
         {
            x = i, y = j;
            sort(V.begin(),V.begin()+sz,cmp);
            if(V.size()==1) M[i][j] = M[V[0].first][V[0].second];
            else if(dist(V[0])!=dist(V[1])) M[i][j] = M[V[0].first][V[0].second];
         }
      }
   }

   FOR(i,N)
   {
      printf("%d",M[i][0]);
      FORI(j,1,N)
      {
         printf(" %d",M[i][j]);
      }
      printf("\n");
   }

   return 0;
}
