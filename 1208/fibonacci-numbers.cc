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

using namespace std;

#define MAX 1000

char b[MAX+1];

void sum(char *s1, char *s2, char *s3)
{
   int car, p;
   int sz_b;
   int sz;
   int sz_s1 = strlen(s1);
   int sz_s2 = strlen(s2);

   reverse(&s1[0],&s1[0]+sz_s1);
   reverse(&s2[0],&s2[0]+sz_s2);
   sz = max(sz_s1,sz_s2);
   sz_b = 0 , car = 0;
   for(int j=0;j<sz;++j)
   {
      p = car;
      if(j<sz_s1) p += s1[j] - '0';
      if(j<sz_s2) p += s2[j] - '0';
      car = p/10;
      p %= 10;
      b[sz_b++] = p + '0';
   }
   if(car) b[sz_b++] = car + '0';
   b[sz_b] = '\0';

   while(sz_b>1 && b[sz_b-1]=='0')
      b[sz_b-1]='\0', sz_b--;
   reverse(&s1[0],&s1[0]+sz_s1);
   reverse(&s2[0],&s2[0]+sz_s2);
   reverse(&b[0],&b[0]+sz_b);
   strcpy(s3,b);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1208.in","r",stdin);
   freopen("out/1208.out","w",stdout);
#endif

   int N;
   char s1[MAX+1], s2[MAX+1], s3[MAX+1];
   scanf("%d",&N);
   if(N<2) printf("1\n");
   else
   {
      N -= 2;
      strcpy(s1,"1");
      strcpy(s2,"1");
      while(N--)
      {
         sum(s1, s2, s3);
         strcpy(s1,s2);
         strcpy(s2,s3);
      }
      printf("%s\n",s3);
   }

   return 0;
}
