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
#include <valarray>

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define MAX 30

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1326.in","r",stdin);
   freopen("out/1326.out","w",stdout);
#endif

   char str[MAX+1];
   char A[27];
   memset(A,0,sizeof(A));
   A['B'-'A']=A['F'-'A']=A['P'-'A']=A['V'-'A']=1;
   A['C'-'A']=A['G'-'A']=A['J'-'A']=A['K'-'A']=A['Q'-'A']=A['S'-'A']=A['X'-'A']=A['Z'-'A']=2;
   A['D'-'A']=A['T'-'A']=3;
   A['L'-'A']=4;
   A['M'-'A']=A['N'-'A']=5;
   A['R'-'A']=6;

   while(scanf("%s",str)==1)
   {
      int last = 0, sz = strlen(str), next;
      FOR(i,sz)
      {
         next = A[str[i]-'A'];
         if(next!=last && next>0)
            printf("%d",next);
         last = A[str[i]-'A'];
      }
      printf("\n");
   }

   return 0;
}
