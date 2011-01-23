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

int sz;
string str;

bool next(int& idx, char c)
{
   if(idx<sz)
      if(str[idx]==c)
         { ++idx; return true; }
   return false;
}

bool slump(int &idx)
{
   if(!next(idx,'D'))
      if(!next(idx,'E'))
         return false;
   if(!next(idx,'F')) return false;
   while(next(idx,'F'));
   if(next(idx,'G')) return true;
   else return slump(idx);
}

bool slimp(int &idx)
{
   if(!next(idx,'A')) return false;
   if(next(idx,'H')) return true;
   if(next(idx,'B'))
   {
      if(!slimp(idx)) return false;
   }
   else if(!slump(idx)) return false;
   if(next(idx,'C')) return true;
   else return false;
}

bool slurpy(int& idx)
{
   if(!slimp(idx)) return false;
   if(!slump(idx)) return false;
   return true;
}

int main()
{
   int N, idx;

   getline(cin,str);
   sscanf(str.c_str(),"%d",&N);
   printf("SLURPYS OUTPUT\n");
   while(N--)
   {
      idx=0;
      getline(cin,str);
      sz = SZ(str);
      bool yes  = slurpy(idx);
      if(yes && (sz==idx)) printf("YES\n");
      else printf("NO\n");
   }
   printf("END OF OUTPUT\n");

   return 0;
}
