#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-10
#define INF 0x3F3F3F3F
#define MAX 100

int main()
{
   int K, A, B, N, M;
   int x, y;
   string dir;
   int dy[] = {1,0,-1,0};
   int dx[] = {0,1,0,-1};


   cin >> K;

   while(K--)
   {
      cin >> A >> B;
      vector< vector<int> > T(A+1, vector<int>(B+1, 0));

      cin >> N >> M;
      vector< pair<int,int> > R(N);
      vector<int> F(N,0);

      FOR(i,N)
      {
         cin >> x >> y >> dir;
         R[i].first = x;
         R[i].second = y;
         if(dir=="N") F[i]=0;
         else if(dir=="E") F[i]=1;
         else if(dir=="S") F[i]=2;
         else if(dir=="W") F[i]=3;
         T[x][y]=i+1;
      }

      bool crash = false;
      int i;
      for(i=0;(i<M) && (!crash);++i)
      {
         cin >> x >> dir >> y;
         if(dir=="R")
         {
            F[x-1] = (F[x-1]+y)%4;
         }
         else if(dir=="L")
         {
            F[x-1] = F[x-1]-y;
            while(F[x-1]<0) F[x-1]+=4;
         }
         else if(dir=="F")
         {
            for(int j=0;(j<y) && (!crash);++j)
            {
               if(R[x-1].first+dx[F[x-1]]<1 || R[x-1].first+dx[F[x-1]]>A ||
                  R[x-1].second+dy[F[x-1]]<1 || R[x-1].second+dy[F[x-1]]>B)
               {
                  crash =  true;
                  printf("Robot %d crashes into the wall\n",x);
               }
               else if(T[R[x-1].first+dx[F[x-1]]][R[x-1].second+dy[F[x-1]]])
               {
                  crash = true;
                  printf("Robot %d crashes into robot %d\n",x,T[R[x-1].first+dx[F[x-1]]][R[x-1].second+dy[F[x-1]]]);
               }
               else
               {
                  T[R[x-1].first][R[x-1].second]=0;
                  R[x-1].first+=dx[F[x-1]];
                  R[x-1].second+=dy[F[x-1]];
                  T[R[x-1].first][R[x-1].second]=x;
               }
            }
         }
      }
      for(;i<M;++i) cin >> x >> dir >> y;
      if(!crash) printf("OK\n");
   }

   return 0;
}
