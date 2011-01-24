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
#define MAX 1000
#define INSERT(q,x) q.push(x);

int main()
{
   int x, y, xx, yy, T, N, X, Y, xr, yr, s;
   int bx, by;

   scanf("%d",&T);

   while(T--)
   {
      queue<int> Q;

      scanf("%d%d%d",&N,&X,&Y);

      vector< vector<int> > F(X, vector<int>(Y, -1));

      scanf("%d%d%d%d",&xx,&yy,&xr,&yr);
      FOR(i,N)
      {
         scanf("%d%d",&bx,&by);
         INSERT(Q,bx);
         INSERT(Q,by);
         F[bx][by]=0;
      }

      while(!Q.empty())
      {
         x = Q.front(); Q.pop();
         y = Q.front(); Q.pop();
         s = F[x][y];
         if(x+1<X && F[x+1][y]==-1) { F[x+1][y] = s+1; INSERT(Q,x+1); INSERT(Q,y);  }
         if(y+1<Y && F[x][y+1]==-1) { F[x][y+1] = s+1; INSERT(Q,x); INSERT(Q,y+1); }
         if(x-1>=0 && F[x-1][y]==-1) { F[x-1][y] = s+1; INSERT(Q,x-1); INSERT(Q,y); }
         if(y-1>=0 && F[x][y-1]==-1) { F[x][y-1] = s+1; INSERT(Q,x); INSERT(Q,y-1); }
      }

      int d[][2] = {{1,0},{0,1},{-1,0},{0,-1}};

      int lo = -1, hi = min(F[xx][yy], F[xr][yr]), m;
      int lim;

      while(lo!=hi)
      {
         vector< vector<int> > r(X, vector<int>(Y, INF));
         m=(lo+hi+1)/2;

         INSERT(Q,xx); INSERT(Q,yy);
         r[xx][yy]=0;
         while(!Q.empty())
         {
            x = Q.front(); Q.pop();
            y = Q.front(); Q.pop();

            FOR(i,4)
            {
               if(x+d[i][0]>=X || x+d[i][0]<0 || y+d[i][1]>=Y || y+d[i][1]<0) continue;
               if(m<=F[x+d[i][0]][y+d[i][1]] && r[x][y]+1<r[x+d[i][0]][y+d[i][1]])
               {
                  r[x+d[i][0]][y+d[i][1]]=r[x][y]+1;
                  INSERT(Q,x+d[i][0]);
                  INSERT(Q,y+d[i][1]);
               }
            }
         }

         if(r[xr][yr]!=INF) lim=m, lo=m, s=r[xr][yr];
         else hi=m-1;
      }

      printf("%d %d\n",lim,s);

   }

   return 0;
}
