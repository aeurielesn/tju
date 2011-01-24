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
   int R, C;
   int r, c;

   queue<int> flood;
   queue<int> painter;

   scanf("%d%d",&R,&C);
   vector<string> map(R);
   vector< vector<bool> > used(R, vector<bool>(C, false));

   FOR(i,R)
   {
      cin >> map[i];
      FOR(j,C)
      {
         if(map[i][j]=='S') { painter.push(i); painter.push(j); map[i][j]='.'; used[i][j]=true; }
         else if(map[i][j]=='*') { flood.push(i); flood.push(j); }
      }
   }

   int time = 0;
   bool goal = false;
   while((!painter.empty()) && (!goal))
   {
      ++time;
      int sz = flood.size()/2;
      FOR(i,sz) // floods
      {
         r = flood.front(); flood.pop();
         c = flood.front(); flood.pop();
         FOR(j,4) // dirs
         {
            if(r+dr[j]<0 || r+dr[j]>=R || c+dc[j]<0 || c+dc[j]>=C) continue;
            if(map[r+dr[j]][c+dc[j]]=='.')
            {
               map[r+dr[j]][c+dc[j]]='*';
               flood.push(r+dr[j]), flood.push(c+dc[j]);
            }
         }
      }
      sz = painter.size()/2;
      FOR(i,sz) // painters
      {
         r = painter.front(); painter.pop();
         c = painter.front(); painter.pop();
         FOR(j,4) // dirs
         {

            if(r+dr[j]<0 || r+dr[j]>=R || c+dc[j]<0 || c+dc[j]>=C) continue;
            if(used[r+dr[j]][c+dc[j]]) continue;
            if(map[r+dr[j]][c+dc[j]]=='.')
            {
               painter.push(r+dr[j]), painter.push(c+dc[j]);
               used[r+dr[j]][c+dc[j]]=true;
            }
            if(map[r+dr[j]][c+dc[j]]=='D')
            {
               goal = true;
            }
         }
      }
   }

   if(goal) printf("%d\n",time);
   else printf("KAKTUS\n");


   return 0;
}
