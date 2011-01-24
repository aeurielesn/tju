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
   int N, M, cnt;
   char str[10], s;
   vector<int> P(MAX+1);
   vector<int> S(MAX+1);

   scanf("%d",&N);
   FOR(i,N)
   {
      vector<int> O;
      cnt = 0;
      scanf("%d",&M);
      FOR(j,M)
      {
         scanf("%s",str);
         sscanf(str,"%c%d",&s,&P[j]);
         S[j] = (s=='+')?1:0;
      }

      for(int j=M;j>=2;--j)
      {
         FOR(k,M)
         {
            if(P[k]==j)
            {
               if(!S[k]) O.push_back(k+1), O.push_back(1), O.push_back(j);
               else if(k+1!=j) O.push_back(k+1), O.push_back(j);

               FOR(l,(k+1)/2) { swap(P[l],P[k-l]); S[l]=1-S[l]; S[k-l]=1-S[k-l]; swap(S[l],S[k-l]); }
               if((k+1)%2==1) S[(k+1)/2]=1-S[(k+1)/2];

               FOR(l,j/2) { swap(P[l],P[j-l-1]); S[l]=1-S[l]; S[j-l-1]=1-S[j-l-1]; swap(S[l],S[j-l-1]); }
               if(j%2==1) S[j/2]=1-S[j/2];

               S[j-1]=1;
               break;
            }
         }
      }
      if(!S[0]) O.push_back(1);

      printf("%d %d",i+1,O.size());
      if(O.size()>0) printf(" %d",O[0]);
      FORI(k,1,O.size())
      {
         printf(" %d",O[k]);
      }
      printf("\n");
   }

   return 0;
}
