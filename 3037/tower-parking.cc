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
#define EPS 1E-9
#define MAX 50

int main()
{
   int T, h, l, t;
   int H[MAX*MAX+2], L[MAX*MAX+2], O[MAX+2];
   int cnt, cost;

   scanf("%d",&T);
   while(T--)
   {
      cnt = 0;
      cost = 0;
      scanf("%d%d",&h,&l);
      FOR(i,h)
      {
         O[i]=0;
         FOR(j,l)
         {
            scanf("%d",&t);
            if(t!=-1)
            {
               H[t-1] = i;
               L[t-1] = j;
               cnt = max(cnt,t);
            }
         }
      }

      FOR(i,cnt)
      {
         int lx = (L[i]+O[H[i]])%l;
         cost += H[i] * 20;
         cost += min(lx, l-lx) * 5;
         O[H[i]] += l-lx;
      }
      printf("%d\n",cost);
   }

   return 0;
}
