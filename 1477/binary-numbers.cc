#include <cstdio>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)

int main()
{
   int d, k, N;

   scanf("%d",&d);
   int O[22];

   FOR(i,d)
   {
      k=0;
      scanf("%d",&N);
      FOR(i,21) if(N&(1<<i)) O[k++]=i;
      printf("%d",O[0]);
      FORI(i,1,k) printf(" %d",O[i]);
      printf("\n");
   }

   return 0;
}
