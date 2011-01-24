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

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2577.in","r",stdin);
   freopen("out/2577.out","w",stdout);
#endif

   int N, n;

   scanf("%d",&N);
   while(N--)
   {
      scanf("%d",&n);
      if(n<=10) printf("%d\n",n);
      else
      {
         int k, factor = 10, nn = n;
         while(factor<nn)
         {
            k = nn%factor;
            nn -= k;
            if(k>=factor/2) nn += factor;
            factor *= 10;
         }
         printf("%d\n",nn);
      }
   }

   return 0;
}
