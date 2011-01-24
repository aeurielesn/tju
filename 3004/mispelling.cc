#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>

#define MAX 100

using namespace std;

int main()
{
   int N, M, sz;
   char S[100];

   scanf("%d",&N);
   for(int i=1;i<=N;++i)
   {
      scanf("%d%s",&M,S);
      sz = strlen(S);
      printf("%d ",i);
      for(int j=0;j<sz;++j)
      {
         if(j==M-1) continue;
         printf("%c",S[j]);
      }
      printf("\n");
   }



   return 0;
}
