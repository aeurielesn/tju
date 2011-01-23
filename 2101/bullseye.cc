#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9
#define MAX 30

int cmp(double x, double y = 0, double tol = EPS) {
   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

double dist(double a, double b)
{
   return sqrt( a * a + b * b );
}

int score(double d)
{
   if(cmp_eq(d,3.0) || cmp_lt(d,3.0)) return 100;
   if(cmp_eq(d,6.0) || cmp_lt(d,6.0)) return 80;
   if(cmp_eq(d,9.0) || cmp_lt(d,9.0)) return 60;
   if(cmp_eq(d,12.0) || cmp_lt(d,12.0)) return 40;
   if(cmp_eq(d,15.0) || cmp_lt(d,15.0)) return 20;
   return 0;
}

int main()
{
   double fire[13];

   while(true)
   {
      FOR(i,12) scanf("%lf",&fire[i]);
      if(cmp_eq(fire[0],-100.0)) break;

      int sum1=0, sum2=0;

      FOR(i,3) sum1 += score(dist(fire[2*i],fire[2*i+1]));
      FOR(i,3) sum2 += score(dist(fire[6+2*i],fire[6+2*i+1]));

      if(sum1>sum2) printf("SCORE: %d to %d, PLAYER %d WINS.\n",sum1,sum2,1);
      else if(sum1<sum2) printf("SCORE: %d to %d, PLAYER %d WINS.\n",sum1,sum2,2);
      else printf("SCORE: %d to %d, TIE.\n",sum1,sum2);
   }

   return 0;
}
