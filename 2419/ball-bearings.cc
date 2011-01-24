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
#define INF 0x3F3F3F3F
#define MAX 100
#define PI 3.141592653589

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2419.in","r",stdin);
   freopen("out/2419.out","w",stdout);
#endif

   int N;
   double D, d, s;

   scanf("%d",&N);
   while(N--)
   {
      scanf("%lf%lf%lf",&D,&d,&s);

      double a = (s+d)/(D-d);
      double b = asin(a);
      double c = PI/b;

      printf("%d\n",(int)floor(c));
   }

   return 0;
}
