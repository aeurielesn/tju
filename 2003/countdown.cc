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
#define EPS 1E-10
#define MAX 1000

using namespace std;

map<string,int> persons;
vector< vector<string> > childs(MAX);

bool cmp(const pair<int, string> a, const pair<int, string> b)
{
   if(a.first==b.first) return a.second < b.second;
   else return a.first > b.first;
}

int go(string name, int depth, int seek)
{
   map<string,int>::iterator it = persons.find(name);
   if(it!=persons.end())
   {
      if(depth==seek) return SZ(childs[it->second]);
      int sum = 0;
      FOR(i,SZ(childs[it->second]))
      {
         sum += go(childs[it->second][i],depth+1,seek);
      }
      return sum;
   }
   else
   {
      return 0;
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2003.in","r",stdin);
   freopen("out/2003.out","w",stdout);
#endif

   int T, n, d, k;
   string name;
   vector< pair<int, string> > out;

   scanf("%d",&T);
   FORI(casos,1,T+1)
   {
      out.clear();
      persons.clear();
      FOR(i,1000) childs[i].clear();

      persons.clear();
      scanf("%d%d",&n,&d);
      FOR(i,n)
      {
         cin >> name;
         persons.insert( pair<string,int>(name,i) );
         cin >> k;
         FOR(j,k)
         {
            cin >> name;
            childs[i].push_back(name);
         }
      }

      FORE(it,persons)
      {
         int cnt = go(it->first,0,d-1);
         out.push_back( pair<int,string>(cnt, it->first) );
      }

      sort(out.begin(),out.end(),cmp);

      if(casos>1) printf("\n");
      printf("Tree %d:\n",casos);
      for(int i=0;i<3 && out[i].first>0;++i)
      {
         cout << out[i].second << " " << out[i].first << endl;
      }
      if(SZ(out)>3 && out[2].first>0)
      {
         int last = out[2].first;
         for(int i=3;i<SZ(out) && out[i].first>0 && out[i].first==last;++i)
         {
            cout << out[i].second << " " << out[i].first << endl;
         }
      }

   }

   return 0;
}
