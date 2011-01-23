#include <cstdio>

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define MAX 1000
#define INF 0x3F3F3F3F

using namespace std;

#define GETNUM(n) { \
  n=0; \
  while (*start>32) { \
    n*=10; n+=*start-'0'; \
    start++; \
  } \
  while (*start>0 && *start<=32) start++; \
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2009.in","r",stdin);
   freopen("out/2009.out","w",stdout);
#endif

   int N, casos=0, maxim;
   int best[MAX][MAX];
   int cards[MAX];
   char *start, inp[8000];

   while(true)
   {
      casos++;
      start = gets(inp);
      GETNUM(N);
      if(N==0) break;

      FOR(i,N)
      {
         GETNUM(cards[i]);
         FOR(j,N) best[i][j] = -INF;
      }

      best[0][N-1]=0;
      bool player = 1;
      maxim = -INF;
      FORI(i,1,N)
      {
         FOR(j,i)
         {
            int x = j, y = N-i+j;
            if(player)
            {
               best[x][y-1] >?= best[x][y] + cards[y];
               best[x+1][y] >?= best[x][y] + cards[x];
            }
            else
            {
               if(cards[x]>=cards[y]) best[x+1][y] >?= best[x][y] - cards[x];
               else best[x][y-1] >?= best[x][y] - cards[y];
            }
         }
         player = 1 - player;
      }

      if(N%2==0) FOR(i,N) maxim >?= best[i][i] - cards[i];
      else FOR(i,N) maxim >?= best[i][i] + cards[i];
      printf("In game %d, the greedy strategy might lose by as many as %d points.\n",casos,maxim);
   }

   return 0;
}
