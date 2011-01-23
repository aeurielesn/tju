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
#define EPS 1E-9
#define MAX 100

long long len(long long n)
{
   long long fac = 1, cnt = 1;
   long long res = 0;
   if(n<10LL) return n;
   while(fac<=n/10)
   {
      res += 9 * fac * cnt;
      fac *= 10;
      cnt++;
   }
   res += (n-fac+1)*cnt;
   return res;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1259.in","r",stdin);
   freopen("out/1259.out","w",stdout);
#endif

   long long T, N, cnt;
   char s[100];

   scanf("%lld",&T);
   while(T--)
   {
      scanf("%lld",&N);
      cnt = 0;
      for(long long i=1; cnt+len(i)<N; ++i) { cnt += len(i); }
      long long j=1;
      for(;cnt+len(j)<N;++j);
      cnt += len(j-1);
      sprintf(s,"%lld",j);
      cout << s[N-cnt-1] << endl;
   }

   return 0;
}
