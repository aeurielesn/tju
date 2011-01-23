#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <sstream>

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
   int T, N, M, A, B;

   scanf("%d",&T);
   FOR(i,T)
   {
      scanf("%d%d",&N,&M);

      A = N - M;
      B = (M-1)/2;

      if(A&B) printf("0\n");
      else printf("1\n");
   }

   return 0;
}
