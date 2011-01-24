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
#define MAX 4

int main()
{
   int x1, y1, x2, y2, k;
   int minx, maxx, miny, maxy;
   int L[MAX+1], C[MAX+1];
   bool M[1002][1002];

   scanf("%d%d%d%d%d",&x1, &y1, &x2, &y2, &k);
   minx = min(x1,x2);
   maxx = max(x1,x2);
   miny = min(y1,y2);
   maxy = max(y1,y2);

   FOR(i,1001) FOR(j,1001) M[i][j]=false;

   FOR(i,k)
      scanf("%d",&L[i]);

   FOR(i,k)
      scanf("%d",&C[i]);

   int mask = 0xF, cnt;
   int dx[]={1,0,-1,0};
   int dy[]={0,1,0,-1};
   bool yes = false;
   queue<int> Q;

   Q.push(x1);
   Q.push(y1);
   Q.push(0);

   while(!Q.empty())
   {
      int x = Q.front(); Q.pop();
      int y = Q.front(); Q.pop();
      int s = Q.front(); Q.pop();

      FOR(i,4) // dir
      {
         FOR(j,k) // tube
         {
            int n = (s>>(4*j))&mask;
            if(n==C[j]) continue;
            if(x+dx[i]*L[j]<minx || x+dx[i]*L[j]>1000 || y+dy[i]*L[j]<miny || y+dy[i]*L[j]>1000) continue;
            if(M[ x+dx[i]*L[j] ][ y+dy[i]*L[j] ]) continue;
            M[x+dx[i]*L[j]][y+dy[i]*L[j]] = true;
            int sx = s + (1<<(4*j));
            if(x+dx[i]*L[j]==x2 && y+dy[i]*L[j]==y2)
            {
               cnt = sx;
               yes = true;
            }
            Q.push(x+dx[i]*L[j]);
            Q.push(y+dy[i]*L[j]);
            Q.push(sx);
            if(yes) break;
         }
         if(yes) break;
      }
      if(yes) break;
   }

   if(yes)
   {
      int p=0;
      FOR(i,k) p += (cnt>>(4*i))&mask;
      printf("%d\n",p);
   }
   else printf("-1\n");

   return 0;
}
