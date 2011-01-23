#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9
#define MAX 30

int main()
{
   int N, K;
   vector<int> pancakes(MAX);
   vector<int> O(2*MAX);

   while(true)
   {
      scanf("%d",&N);
      if(!N) break;

      FOR(i,N) scanf("%d",&pancakes[i]);

      K=0;
      for(int i=N;i>0;--i)
      {
         int j;
         for(j=1;(pancakes[j-1]!=i) && (j<=N);++j);
         if(i==j) continue;
         if(j>1)
         {
            FOR(k,j/2) swap(pancakes[k],pancakes[j-k-1]);
            O[K++]=j;
         }
         FOR(k,i/2) swap(pancakes[k],pancakes[i-k-1]);
         O[K++]=i;
      }
      printf("%d",K);
      FOR(i,K) printf(" %d",O[i]);
      printf("\n");
   }



   return 0;
}
