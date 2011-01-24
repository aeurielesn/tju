#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-10
#define INF 0x3F3F3F3F

int main()
{
   int N, len=0;

   scanf("%d",&N);
   vector<string> S(N+1);

   FOR(i,N) cin >> S[i];

   len += SZ(S[0]);
   FOR(i,N-1)
   {
      int sz = min(SZ(S[i]),SZ(S[i+1])), j = 0;
      for(j=0;(j<sz) && (S[i][j]==S[i+1][j]);++j);
      if(!j) len += SZ(S[i+1]) + 1;
      else len += SZ(S[i+1]) - j + 1;
   }
   printf("%d\n",len);

   return 0;
}
