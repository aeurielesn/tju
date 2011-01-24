#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define tr(c,i) for(__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9
#define INF 50000000

int main()
{
   int C, N, M, S, T, A, B, c;

   scanf("%d",&C);
   FOR(i,C)
   {
      scanf("%d%d",&N,&M);
      vector< vector< pair<int,int> > > G(N);
      scanf("%d%d",&S,&T);
      FOR(j,M)
      {
         scanf("%d%d%d",&A,&B,&c);
         G[A-1].push_back( make_pair( B-1, c ) );
         G[B-1].push_back( make_pair( A-1, c ) );
      }

      vi D(N, INF);

      priority_queue<ii,vector<ii>, greater<ii> > Q;
      D[S-1] = 0;
      Q.push(ii(0,S-1));

      while(!Q.empty()) {

            ii top = Q.top();
            Q.pop();

            int v = top.second, d = top.first;

            if(d <= D[v]) {
                  tr(G[v], it) {
                        int v2 = it->first, cost = it->second;
                        if(D[v2] > D[v] + cost) {
                              D[v2] = D[v] + cost;
                              Q.push(ii(D[v2], v2));

                        }
                  }
            }
      }

      if(D[T-1]==INF) printf("-1\n");
      else printf("%d\n",D[T-1]);
   }

   return 0;
}
