#include <queue>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define MAX 100

using namespace std;

int main()
{
   int N, K;
   long long maxi;
   long long M[MAX+2][MAX+2];
   long long A[MAX+1];

   while(true)
   {
      memset(M,0,sizeof(M));
      memset(A,0,sizeof(A));

      scanf("%d%d",&N,&K);
      if(N==0 && K==0) break;

      for(int i=0;i<N;++i)
         scanf("%lld",&A[i]);

      for(int i=0;i<N;++i) M[i][1] = 1LL;

      maxi = 0;
      for(int i=0;i<N;++i)
      {
         for(int j=i+1;j<N;++j)
            if(A[i]<A[j])
            {
              for(int k=2;k<=K;++k)
                  M[j][k] += M[i][k-1];
            }
         maxi += M[i][K];
      }

      printf("%lld\n",maxi);
   }

   return 0;
}
