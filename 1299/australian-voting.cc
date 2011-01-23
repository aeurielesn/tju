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

#define PB push_back
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F
#define MAX 20

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1299.in","r",stdin);
   freopen("out/1299.out","w",stdout);
#endif

   int n, temp;
   int M[1001][MAX+1];
   string str;
   vector<string> names(MAX+2);
   vector<bool> del(MAX+2);
   int C[MAX+1], P[1001];

   memset(C,0,sizeof(C));
   memset(P,0,sizeof(P));

   getline(cin,str);
   sscanf(str.c_str(),"%d",&n);
   FOR(i,n)
   {
      del[i] = false;
      getline(cin,names[i]);
   }

   int cnt = 0;
   while(getline(cin,str))
   {
      istringstream strin(str);
      FOR(i,n)
      {
         strin >> temp;
         M[cnt][i] = temp - 1;
      }
      cnt++;
   }

   int mini, maxi;
   while(true)
   {
      // freq
      FOR(i,cnt)
      {
         C[M[i][P[i]]]++;
      }
      // min & max & winner
      bool winner = false, tie = false;
      int who;
      mini = INF, maxi = -1;
      FOR(i,n)
      {
         if(del[i]) continue;
         mini <?= C[i];
         maxi >?= C[i];
         if(2*C[i]>cnt) winner = true, who = i;
      }
      tie = (mini == maxi);
      if(winner)
      {
         cout << names[who] << endl;
         break;
      }
      else if(tie)
      {
         FOR(i,n)
         {
            if(C[i]==maxi)
            {
               cout << names[i] << endl;
            }
         }
         break;
      }
      else
      {
         FOR(i,n)
         {
            if(C[i]==mini) del[i]=true;
            C[i]=0;
         }
         FOR(i,cnt)
         {
            while(del[M[i][P[i]]])
               P[i]++;
         }
      }
   }

   return 0;
}
