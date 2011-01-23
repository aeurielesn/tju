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
   int N, K, O, cnt;

   scanf("%d",&N);

   while(N--)
   {
      cnt = 0;
      scanf("%d",&K);
      scanf("%d",&cnt);
      FOR(i,K-1)
      {
         scanf("%d",&O);
         cnt += O - 1;
      }
      printf("%d\n",cnt);
   }

   return 0;
}
