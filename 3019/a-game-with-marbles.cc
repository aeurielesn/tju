#include <queue>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define MAX 50

using namespace std;

int main()
{
   int N;
   long long M[MAX+1], off=0;

   while(true)
   {
      off = 0;
      scanf("%d",&N);
      if(N==0) break;

      for(int i=0;i<N;++i)
      {
         scanf("%lld",&M[i]);
      }

      for(int i=N-1;i>=0;--i)
      {
         off += M[i]+off;
      }
      printf("%lld\n",off);
   }

   return 0;
}
