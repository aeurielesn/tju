#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define tr(c,i) for(__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9
#define INF 2000000

int main()
{
   int x[4],y[4];
   int xmax=-1, xmin=INF, ymin=INF, ymax=-1;
   int cxmax=0, cxmin=0, cymin=0, cymax=0;

   FOR(i,3)
   {
      scanf("%d%d",&x[i],&y[i]);
      xmax = max(xmax,x[i]);
      xmin = min(xmin,x[i]);
      ymax = max(ymax,y[i]);
      ymin = min(ymin,y[i]);
   }
   FOR(i,3)
   {
      if(x[i]==xmin) cxmin++;
      if(x[i]==xmax) cxmax++;
      if(y[i]==ymin) cymin++;
      if(y[i]==ymax) cymax++;
   }
   if(cxmin<2) printf("%d ",xmin);
   if(cxmax<2) printf("%d ",xmax);
   if(cymin<2) printf("%d\n",ymin);
   if(cymax<2) printf("%d\n",ymax);

   return 0;
}
