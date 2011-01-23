#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9
#define INF 0x3F3F3F3F
#define MAX 100

int main()
{
   int N, M, S, T;
   int cost, from, exits, to;
   bool yes;

   while(true)
   {
      scanf("%d", &N);
      if(N==-1) break;

      vector< vector<bool> > W(MAX+2, vector<bool>(MAX+2, false));
      vi D(N+1, INF);
      vi L(N+1, 0);
      viii E(N*N);
      M = 0;
      yes=false;
      S=0;
      T=N;

      D[0] = -100;
      E[M++] = iii( 0, ii(1, 0));
      E[M++] = iii( 1, ii(0, 0));
      FORI(i,1,N+1)
      {
         scanf("%d%d", &cost, &exits);
         FOR(j,exits)
         {
            scanf("%d", &to);
            E[M++] = iii( i, ii(to, cost * -1));
         }
      }

      // Bellman-Ford
      FOR(i,N+1)
      {
         FOR(j,M)
         {
            int u = E[j].first, v = E[j].second.first, cost = E[j].second.second;
            if((D[u] + cost < D[v]) && (D[u] + cost < 0))
            {
               if(i<N) D[v] = D[u] + cost;
               L[v] = i;
            }
         }
      }

      if(D[T]<0)
      {
         yes |= true;
      }
      else
      {
         FOR(j,M)
         {
            int u = E[j].first, v = E[j].second.first, cost = E[j].second.second;
            W[u][v] = true;
         }

         // Floyd
         FOR(i,N+1)
         {
            FOR(j,N+1)
            {
               FOR(k,N+1)
               {
                  W[i][j] = W[i][j] | (W[i][k] && W[k][j]);
               }
            }
         }

         FORI(i,1,N+1)
         {
            if(W[0][i] && (L[i]==N) && W[i][N]) yes |= true;
         }
      }

      if(yes) cout << "winnable" << endl;
      else cout << "hopeless" << endl;
   }

   return 0;
}
