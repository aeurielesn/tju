#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/3232.in","r",stdin);
   freopen("out/3232.out","w",stdout);
#endif
   int l,m,r;

   cin >> l >> m >> r;
   cout << max(m-l-1,r-m-1) << endl;

   return 0;
}
