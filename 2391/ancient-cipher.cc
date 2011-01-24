#include <vector>
#include <cstring>
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
   freopen("in/2391.in","r",stdin);
   freopen("out/2391.out","w",stdout);
#endif

   string a, b;
   int A[200], B[200];

   memset(A,0,sizeof(A));
   memset(B,0,sizeof(B));

   cin >> a >> b;

   sort(ALL(a));
   sort(ALL(b));

   a += "@";
   b += "@";

   int cnt = 1;
   FOR(i,SZ(a)-1)
   {
      if(a[i]==a[i+1])
      {
         cnt++;
      }
      else
      {
         A[cnt]++;
         cnt = 1;
      }
   }

   cnt = 1;
   FOR(i,SZ(b)-1)
   {
      if(b[i]==b[i+1])
      {
         cnt++;
      }
      else
      {
         B[cnt]++;
         cnt = 1;
      }
   }

   bool yes = true;
   FOR(i,101)
   {
      yes &= (A[i]==B[i]);
   }

   cout << ((yes)?"YES":"NO") << endl;

   return 0;
}
