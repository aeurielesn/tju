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

#define PB push_back
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F
#define MAX 30

using namespace std;

string level;
vector<bool> exist(27);
vector<int> L(MAX+1, INF), R(MAX+1, 0), U(MAX+1, INF), D(MAX+1, 0);
vector<string> M(MAX+1);
vector<string> output;

void go(int lev, string out)
{
   if(lev == SZ(level))
   {
      reverse(ALL(out));
      output.PB(out);
      return;
   }
   bool full;
   string myout;
   FOR(k,SZ(level))
   {
      full = true;
      int i = level[k]-'A';
      if(!exist[i]) continue;
      FORI(j,L[i],R[i]+1) if((M[U[i]][j]!=level[k]) && (exist[M[U[i]][j]-'A'])) full = false;
      FORI(j,L[i],R[i]+1) if((M[D[i]][j]!=level[k]) && (exist[M[D[i]][j]-'A'])) full = false;
      FORI(j,U[i],D[i]+1) if((M[j][L[i]]!=level[k]) && (exist[M[j][L[i]]-'A'])) full = false;
      FORI(j,U[i],D[i]+1) if((M[j][R[i]]!=level[k]) && (exist[M[j][R[i]]-'A'])) full = false;
      if(full)
      {
         exist[i] = false;
         myout = out;
         myout += level[k];

         go(lev+1,myout);

         exist[i] = true;
      }
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1076.in","r",stdin);
   freopen("out/1076.out","w",stdout);
#endif

   int h, w;
   string str, ans = "";

   while(getline(cin,str))
   {
      ans = "";
      level = "";
      M = vector<string>(MAX+1);
      output.clear();
      exist = vector<bool>(27, false);
      L = vector<int>(MAX+1, INF);
      R = vector<int>(MAX+1, 0);
      U = vector<int>(MAX+1, INF);
      D = vector<int>(MAX+1, 0);

      sscanf(str.c_str(),"%d",&h);

      getline(cin,str);
      sscanf(str.c_str(),"%d",&w);

      FOR(i,h)
      {
         getline(cin,M[i]);
         FOR(j,w)
         {
            if(M[i][j]=='.') continue;
            L[M[i][j]-'A'] <?= j;
            R[M[i][j]-'A'] >?= j;
            U[M[i][j]-'A'] <?= i;
            D[M[i][j]-'A'] >?= i;
            if(!exist[M[i][j]-'A']) level += M[i][j]; //cnt++;
            exist[M[i][j]-'A'] = true;
         }
      }
      sort(ALL(level));
      go(0,"");
      sort(ALL(output));
      FOR(i,SZ(output))
      {
         cout << output[i] << endl;
      }
   }

   return 0;
}
