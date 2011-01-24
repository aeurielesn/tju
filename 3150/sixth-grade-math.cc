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

int GCD(int a, int b)
{
   if(b==0) return a;
   else return GCD(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/3150.in","r",stdin);
   freopen("out/3150.out","w",stdout);
#endif

   int T, a, b, gcd;

   cin >> T;
   FORI(caso,1,T+1)
   {
      cin >> a >> b;
      gcd = GCD(a,b);
      cout << caso << " " << ((a*b)/gcd) << " " << gcd << endl;
   }

   return 0;
}
