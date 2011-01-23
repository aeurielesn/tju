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

int cmp(double x, double y = 0, double tol = EPS) {
   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int main()
{
   int N;
   double x11, x12, y11, y12;
   double x21, x22, y21, y22;
   double m1, b1, m2, b2;

   scanf("%d",&N);
   printf("INTERSECTING LINES OUTPUT\n");
   FOR(i,N)
   {
      scanf("%lf%lf%lf%lf",&x11,&y11,&x12,&y12);
      scanf("%lf%lf%lf%lf",&x21,&y21,&x22,&y22);

      if(cmp_eq(x11,x12)) m1 = INF, b1 = x11;
      else m1 = (y11-y12) / (x11-x12), b1 = y11 - m1 * x11;

      if(cmp_eq(x21,x22)) m2 = INF, b2 = x21;
      else m2 = (y21-y22) / (x21-x22), b2 = y21 - m2 * x21;

      if(cmp_eq(m1,m2) && cmp_eq(b1,b2)) printf("LINE\n");
      else if(cmp_eq(m1,m2) && (!cmp_eq(b1,b2))) printf("NONE\n");
      else
      {
         double x, y;
         if(cmp_eq(m1,INF)) x =  b1, y = m2 * x + b2;
         else if(cmp_eq(m2,INF)) x =  b2, y = m1 * x + b1;
         else x = (b2 - b1) / (m1 - m2), y = m1 * x + b1;

         printf("POINT %.2lf %.2lf\n",x,y);
      }
   }
   printf("END OF OUTPUT\n");

   return 0;
}
