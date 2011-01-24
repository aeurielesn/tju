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
   freopen("in/3152.in","r",stdin);
   freopen("out/3152.out","w",stdout);
#endif

   int T, d[3];
   string V, H;

   cin >> T;
   FORI(caso,1,T+1)
   {
      V = H = "";
      scanf("%d%*c%d%*c%d",&d[0],&d[1],&d[2]);

      FOR(j,3)
      {
         for(int i=5;i>=0;--i)
         {
            if(d[j]&(1<<i)) H += "1";
            else H += "0";
         }
      }

      for(int i=5;i>=0;--i)
      {
         FOR(j,3)
         {
            if(d[j]&(1<<i)) V += "1";
            else V += "0";
         }
      }

      cout << caso << " " << V << " " << H << endl;
   }

   return 0;
}
