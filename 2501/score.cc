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
   freopen("in/2501.in","r",stdin);
   freopen("out/2501.out","w",stdout);
#endif

   int N, cnt = 0, score = 0;
   string str;

   cin >> N;
   while(N--)
   {
      cnt = score = 0;
      cin >> str;
      FOR(i,SZ(str))
      {
         if(str[i]=='O') cnt++;
         else cnt = 0;
         score += cnt;
      }
      cout << score << endl;
   }

   return 0;
}
