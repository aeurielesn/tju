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
#define INF 0x3F3F3F3F
#define MAX 100

using namespace std;

#define GETNUM(n) { \
  n=0; \
  while (*start>32) { \
    n*=10; n+=*start-'0'; \
    start++; \
  } \
  while (*start>0 && *start<=32) start++; \
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2418.in","r",stdin);
   freopen("out/2418.out","w",stdout);
#endif

   int n, x, y, d;
   int sX[MAX+1], sY[MAX+1];
   int bX, bY;
   int sum;
   char str[1000], *start;

   start = gets(str);
   GETNUM(n);
   while(n--)
   {
      memset(sX,0,sizeof(sX));
      memset(sY,0,sizeof(sY));

      start = gets(str);
      GETNUM(x); GETNUM(y);

      FOR(j,y)
      {
         start = gets(str);
         FOR(i,x)
         {
            GETNUM(d);
            sY[j] += d;
            sX[i] += d;
         }
      }

      bX = INF;
      FOR(i,x)
      {
         sum = 0;
         FOR(j,x)
         {
            if(i==j) continue;
            sum += abs(i-j) * sX[j];
         }
         if(sum<bX) bX = sum;
      }

      bY = INF;
      FOR(i,y)
      {
         sum = 0;
         FOR(j,y)
         {
            if(i==j) continue;
            sum += abs(i-j) * sY[j];
         }
         if(sum<bY) bY = sum;
      }

      printf("%d blocks\n",bX+bY);

   }

   return 0;
}
