#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i, a, x) for (int i = a; i < x; i++)

int prec[1000001];

inline int Squeeze(int &n, int p) {
   int C = 0;
   for (; n % p == 0; n /= p) ++C;
   return C;
}

inline int Factors(int n) {
   if(prec[n]) return prec[n];
   int cnt = 1;
   if (n < 2) return 1;
   cnt *= (Squeeze(n,2)+1);
   if(prec[n]) return cnt * prec[n];
   cnt *= (Squeeze(n,3)+1);
   if(prec[n]) return cnt * prec[n];
   int p = 5;
   while (n > 1) {
      cnt *= (Squeeze(n,p)+1);
      if(prec[n]) return cnt * prec[n];
      cnt *=  (Squeeze(n,p+2)+1);
      if(prec[n]) return cnt * prec[n];
      p += 6;
      if (p * p > n) p = n;
   }
   return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/3259.in","r",stdin);
   freopen("out/3259.out","w",stdout);
#endif
   memset(prec,0,sizeof(prec));
   vector<bool> V(1000001, false);

   int low, high, cnt;

   FORI(i,1,1000001)
   {
      int d = Factors(i);
      prec[i] = d;
      if(i%d==0) V[i]=true;
   }

   while(cin >> low >> high)
   {
      cnt = 0;
      FORI(i,low,high+1)
         cnt += V[i];
      cout << cnt << endl;
   }

   return 0;
}
