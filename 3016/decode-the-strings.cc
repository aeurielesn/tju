#include <queue>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define MAX 80

using namespace std;

int main()
{
   while(true)
   {
      int n, m;
      vector< vector<int> > o(MAX+3, vector<int>(MAX+1));
      vector<int> p(MAX+1);
      vector<int> sz(MAX+1, 0);
      vector<bool> found(MAX+1);
      vector< pair<int,char> > O(MAX+1);
      string S, strin;

      getline(cin,strin);
      sscanf(strin.c_str(),"%d%d",&n,&m);
      if(n==0 && m==0) break;

      getline(cin,strin);
      istringstream ss(strin);
      for(int i=0;i<n;++i)
      {
         ss >> p[i];
         --p[i];
         found[i]=false;
      }
      getline(cin,S);

      for(int i=0;i<n;i++) o[0][i]=i;

      for(int SZ=1, cnt=0; cnt<n; ++SZ)
      {
         for(int j=0;j<n;j++)
         {
            if(found[j]) continue;
            o[SZ][j]=o[SZ-1][ p[j] ];
            if(o[SZ][j]==o[0][j])
            {
               cnt++;
               sz[j] = SZ;
               found[j]=true;
            }
         }
      }

      for(int i=0;i<n;i++)
      {
         int k = m%sz[i];
         O[i] = make_pair(o[k][i], i);
      }

      sort(O.begin(),O.begin()+n);

      for(int i=0;i<n;i++)
      {
         printf("%c",S[O[i].second]);
      }
      printf("\n");

   }


   return 0;
}
