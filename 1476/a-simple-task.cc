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
   int d, N, k;

   scanf("%d",&d);
   FOR(i,d)
   {
      k=0;
      scanf("%d",&N);
      while(N%2==0) N/=2, k++;
      printf("%d %d\n",N,k);
   }

   return 0;
}
