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
#define MAX 20

using namespace std;

int f91(int N)
{
   if(N<101) return f91(f91(N+11));
   else return N-10;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1257.in","r",stdin);
   freopen("out/1257.out","w",stdout);
#endif

   int N;
   while(true)
   {
      scanf("%d",&N);
      if(!N) break;
      printf("f91(%d) = %d\n",N,f91(N));
   }

   return 0;
}
