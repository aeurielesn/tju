#include <vector>
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

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F

using namespace std;

bool cmp(pair<int, char> a, pair<int, char> b)
{
   if(a.first==b.first) return a.second < b.second;
   else return a.first > b.first;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2468.in","r",stdin);
   freopen("out/2468.out","w",stdout);
#endif

   string str;
   int T;

   scanf("%d\n",&T);
   while(T--)
   {
      vector< pair<int, char> > V(26);
      FOR(i,26) V[i].first=0, V[i].second='a'+i;
      getline(cin,str);
      FOR(i,SZ(str))
      {
         V[str[i]-'a'].first++;
      }
      sort(V.begin(), V.end(), cmp);
      int maxi = V[0].first;
      for(int i=0;i<26 && V[i].first==maxi;++i) printf("%c",V[i].second);
      printf("\n");
   }

   return 0;
}
