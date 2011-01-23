#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
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
#define MAX 30

#define GETNUM(n) { \
  int sgn=1; \
  n=0; \
  if(*start=='-') { sgn=-1; start++; } \
  while (*start>='0' && *start<='9') { \
    n*=10; n+=*start-'0'; \
    start++; \
  } \
  n *= sgn; \
}

#define GETCHAR(c) { \
  c=*start; \
  start++; \
}

int main()
{
   int r=1, R, C, k, p;
   char s[50], t, *start;
   string res;

   while(true)
   {
      res = "";
      gets(s); start=s;
      GETCHAR(t); GETNUM(R);
      GETCHAR(t); GETNUM(C);
      if(R==0 && C==0) break;

      k=1; r=1; p=1;
      while(r + p*26<=C) r = r + p*26, p *= 26, k++;
      C -= r;

      FOR(i,k)
      {
         int c = C%26;
         res = (char)('A'+c) + res;
         C /= 26;
      }
      cout << res << R << endl;
   }

   return 0;
}
