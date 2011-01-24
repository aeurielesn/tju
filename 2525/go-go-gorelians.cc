#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <valarray>

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x77359400
#define EPS 1E-10
#define MAX 1000

using namespace std;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;
typedef pair<int,ddd> iddd;

#define ID(a) a.first
#define X(a) a.second.first
#define Y(a) a.second.second.first
#define Z(a) a.second.second.second

int cmp(double x, double y = 0, double tol = EPS) {
   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

double dist(iddd a, iddd b)
{
   return (X(a)-X(b))*(X(a)-X(b)) + (Y(a)-Y(b))*(Y(a)-Y(b)) + (Z(a)-Z(b))*(Z(a)-Z(b));
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2525.in","r",stdin);
   freopen("out/2525.out","w",stdout);
#endif

   int N, id;
   double x, y, z;

   while(true)
   {
      scanf("%d",&N);

      if(N==0) break;

      vector<iddd> planets(N);
      vector< vector<int> > costs(N, vector<int>(N, 0));
      vector<int> sz(N,0);
      vector< vector<int> > adj(N, vector<int>(N, 0));
      vector<int> maxi(N,0);
      vector<int> out;

      FOR(i,N)
      {
         scanf("%d%lf%lf%lf",&id,&x,&y,&z);
         ID(planets[i]) = id;
         X(planets[i]) = x;
         Y(planets[i]) = y;
         Z(planets[i]) = z;

         if(i==0)
         {
            costs[i][sz[i]] = 0;
            adj[i][sz[i]] = i;
            sz[i]++;
         }
         else
         {
            int best = 0;
            double mydist = INF * 1.0;
            FOR(j,i)
            {
               if(cmp_lt(dist(planets[i],planets[j]),mydist))
               {
                  best = j;
                  mydist = dist(planets[i],planets[j]);
               }
            }
            int t = sz[best];
            FOR(j,t)
            {
               int v = adj[best][j];
               costs[i][sz[i]] = costs[best][j] + 1;
               adj[i][sz[i]] = v;
               maxi[i] >?= costs[i][sz[i]];

               costs[v][sz[v]] = costs[i][sz[i]];
               adj[v][sz[v]] = i;
               maxi[v] >?= costs[v][sz[v]];

               sz[i]++; sz[v]++;
            }
            costs[i][sz[i]] = 0;
            adj[i][sz[i]] = i;
            sz[i]++;
         }
      }
      int best = INF;
      FOR(i,N)
      {
         if(maxi[i]<best) out.clear(), best = maxi[i];
         if(maxi[i]==best) out.push_back(ID(planets[i]));
      }
      sort(ALL(out));
      printf("%d",out[0]);
      if(SZ(out)>1) printf(" %d",out[1]);
      printf("\n");
   }

   return 0;
}
