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
#define MAX 30

int main()
{
   int T;
   int M,N,P,s,cnt;
   string s1, s2;
   int D[MAX+1][MAX+1];

   scanf("%d",&T);
   printf("SHIPPING ROUTES OUTPUT\n");
   FORI(c,1,T+1)
   {
      printf("\nDATA SET %d\n\n",c);
      map<string, int> warehouses;
      scanf("%d%d%d",&M,&N,&P);

      FOR(i,M) FOR(j,M) D[i][j] = (i==j)?0:INF;

      FOR(i,M)
      {
         cin >> s1;
         warehouses.insert( make_pair(s1, i) );
      }

      FOR(i,N)
      {
         cin >> s1 >> s2;
         int w1 = warehouses[s1], w2 = warehouses[s2];
         D[w1][w2] = 1;
         D[w2][w1] = 1;
      }

      FOR(i,M)
         FOR(j,M)
            FOR(k,M)
               if(D[i][k] + D[k][j] < D[i][j])
                  D[i][j] = D[i][k] + D[k][j];

      cnt = 0;
      FOR(i,P)
      {
         cin >> s >> s1 >> s2;
         int d = D[warehouses[s1]][warehouses[s2]];
         if(d!=INF) printf("$%d\n",s*d*100);
         else printf("NO SHIPMENT POSSIBLE\n");
      }

   }
   printf("\nEND OF OUTPUT\n");

   return 0;
}
