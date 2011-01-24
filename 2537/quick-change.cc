#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
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

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2537.in","r",stdin);
   freopen("out/2537.out","w",stdout);
#endif

   int T, N;

   cin >> T;
   FORI(caso,1,T+1)
   {
      cin >> N;
      int q = N/25, d = (N%25)/10, n = ((N%25)%10)/5, p = (((N%25)%10)%5);
      cout << caso << " " << q << " QUARTER(S), " << d << " DIME(S), " << n << " NICKEL(S), " << p << " PENNY(S)" << endl;
   }

   return 0;
}
