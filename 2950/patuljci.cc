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

int main()
{
   bool yes = false;
   int cnt, sum, t;
   vector<int> D(257,0);
   FOR(i,9) scanf("%d",&D[1<<i]);

   FORI(i,1,1<<9)
   {
      cnt = __builtin_popcount(i);
      if(cnt!=7) continue;
      sum = 0; t=i;
      while(t>0)
      {
         sum += D[(t & -t)];
         t -= (t & -t);
      }
      if(sum==100)
      {
         t=i;
         while(t>0)
         {
            printf("%d\n",D[(t & -t)]);
            t -= (t & -t);
         }
         yes = true;
      }
      if(yes) break;
   }

   return 0;
}
