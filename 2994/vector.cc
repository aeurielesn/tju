#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define tr(c,i) for(__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9

int main()
{
   int T, N;
   int A[11], B[11], C;

   scanf("%d",&T);

   FOR(i,T)
   {
      scanf("%d",&N);
      FOR(j,N)
         scanf("%d",&A[j]);
      FOR(j,N)
         scanf("%d",&B[j]);
            FOR(j,N)
      C = 0;
      FOR(j,N)
         C += A[j] * B[j];
      printf("%d\n",C);
   }


   return 0;
}
