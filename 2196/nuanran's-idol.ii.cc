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

#define PB push_back
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define MAX 100000

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2196.in","r",stdin);
   freopen("out/2196.out","w",stdout);
#endif

   int n, v;
   char c[200], letter[100];

   while(true)
   {
      multiset<int> S;

      gets(c);
      sscanf(c,"%d",&n);
      if(n==0) break;

      FOR(i,n)
      {
         gets(c);
         sscanf(c,"%s%d",letter,&v);
         if(letter[0]=='G')
         {
            cout << (*S.begin()) << endl;
            S.erase(S.begin());
         }
         else if(letter[0]=='B')
         {
            S.insert(v);
         }
      }
   }

   return 0;
}
