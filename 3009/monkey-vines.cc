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
   int N;
   string strin;
   getline(cin,strin);
   sscanf(strin.c_str(),"%d",&N);

   for(int i=1;i<=N;++i)
   {
      string S;
      getline(cin,S);

      int maxi = 0;
      int sz = S.size();
      for(int j=0,k=0;j<sz;++j)
      {
         if(S[j]=='[') ++k;
         else if(S[j]==']') --k;
         maxi = max(maxi,k);
      }

      printf("%d %d\n",i,1<<maxi);
   }

   return 0;
}
