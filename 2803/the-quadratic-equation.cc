#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define EPS 1E-9

int main()
{
   int T;
   double a, b, c;

   cin >> T;

   FOR(i,T)
   {
      cin >> a >> b >> c;
      if((b * b - 4.0 * a * c) < 0)
         printf("No solution!\n");
      else
      {
         double x1 = (-1.0 * b + sqrt(b * b - 4.0 * a * c))/(2.0*a);
         double x2 = (-1.0 * b - sqrt(b * b - 4.0 * a * c))/(2.0*a);

         if(fabs(x1-x2)<=EPS)
            printf("%.3lf\n",x1);
         else if(x1<x2)
            printf("%.3lf %.3lf\n",x1,x2);
         else
            printf("%.3lf %.3lf\n",x2,x1);
      }
   }

   return 0;
}
