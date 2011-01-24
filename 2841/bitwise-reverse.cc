#include <cstdio>
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

int main()
{
   unsigned int N, R, maxi;

   while(true)
   {
      scanf("%d",&N);
      if(N==0) break;
      R = 0;
      for(int i=0;i<20;i++)
      {
         int mask = 1<<i;
         int yes = (N&mask)?1:0;
         if(yes) maxi=i;
      }
      FOR(i,maxi+1)
      {
         int mask = 1<<i;
         int yes = (N&mask)?1:0;
         if(yes)
         {
            R += 1<<(maxi-i);
         }
      }
      printf("%d\n",R);
   }

   return 0;
}
