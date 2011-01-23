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

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F
#define EPS 1E-10

using namespace std;

int cmp(double x, double y = 0, double tol = EPS) {
   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2008.in","r",stdin);
   freopen("out/2008.out","w",stdout);
#endif

   int N, casos=0;

   while(true)
   {
      ++casos;
      scanf("%d",&N);
      if(N==0) break;

      vector< pair<double,double> > P(N);
      vector< pair<double,double> > V;

      FOR(i,N) scanf("%lf%lf",&P[i].first,&P[i].second);

      FOR(i,N)
      {
         FORI(j,i+1,N)
         {
            double x1 = P[i].first, y1 = P[i].second, x2 = P[j].first, y2 = P[j].second, m, b;

            if(cmp_eq(x1,x2)) m = INF, b = x1;
            else m = (y1-y2)/(x1-x2), b = y1 - m * x1;

            V.push_back( pair<double,double>(m,b) );
         }
      }


      sort(ALL(V));

      int cnt = 1, maxi = -1;
      FOR(i,SZ(V)-1)
      {
         if(V[i]==V[i+1]) cnt++;
         else
         {
            maxi >?= cnt;
            cnt = 1;
         }
      }
      maxi >?= cnt;

      for(int i=1,sum=0;sum<=maxi;sum+=i,i++) cnt=i;

      if(cnt<4) cnt=0;
      printf("Photo %d: %d points eliminated\n",casos,cnt);

   }

   return 0;
}
