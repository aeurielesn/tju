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
#ifndef ONLINE_JUDGE
   freopen("in/2943.in","r",stdin);
   freopen("out/2943.out","w",stdout);
#endif

   int N;
   map<string,string> dict;
   string str, w;

   getline(cin,str);
   sscanf(str.c_str(),"%d",&N);
   FOR(i,N)
   {
      getline(cin,w);
      str=w;
      if(SZ(str)>2) sort(str.begin()+1,str.end()-1);
      dict.insert(pair<string,string>(str,w));
   }

   while(getline(cin,str))
   {
      bool first = true;
      istringstream sstr(str);
      while(sstr >> str)
      {
         if(SZ(str)>2) sort(str.begin()+1,str.end()-1);
         if(!first) cout << " ";
         cout << dict[str];
         first = false;
      }
      cout << endl;
   }

   return 0;
}
