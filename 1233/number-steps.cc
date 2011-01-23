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
#define MAX 1000

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1233.in","r",stdin);
   freopen("out/1233.out","w",stdout);
#endif

   int N, x, y;
   scanf("%d",&N);
   FOR(i,N)
   {
      scanf("%d%d",&x,&y);
      if((x==y) || (y==x-2)) printf("%d\n",(x%2==0)?(x+y):(x+y-1));
      else printf("No Number\n");
   }

   return 0;
}
