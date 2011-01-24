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

int main()
{
   int dr[]={-1,0,1,0}, dc[]={0,-1,0,1};
   int W, H;
   int r, c;

   queue<int> man;

   while(true)
   {
      scanf("%d%d",&W,&H);
      if(W==0 && H==0) break;

      vector<string> map(H);

      FOR(i,H)
      {
         cin >> map[i];
         FOR(j,W)
            if(map[i][j]=='@') man.push(i), man.push(j);
      }

      int steps = 0;
      while(!man.empty())
      {
         ++steps;
         r = man.front(); man.pop();
         c = man.front(); man.pop();
         FOR(j,4)
         {
            if(r+dr[j]<0 || r+dr[j]>=H || c+dc[j]<0 || c+dc[j]>=W) continue;
            if(map[r+dr[j]][c+dc[j]]=='.')
            {
               map[r+dr[j]][c+dc[j]]='#';
               man.push(r+dr[j]), man.push(c+dc[j]);
            }
         }
      }

      printf("%d\n",steps);
   }


   return 0;
}
