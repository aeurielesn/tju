#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2005.in","r",stdin);
   freopen("out/2005.out","w",stdout);
#endif
   int n, m, k, x, y,casos=0;

   while(true)
   {
      ++casos;
      scanf("%d%d",&n,&m);
      if(n==0 && m==0) break;

      vector< vector<int> > board(n, vector<int>(m, 0));

      scanf("%d",&k);
      vector< pair<int,int> > queens(k);
      FOR(i,k)
         scanf("%d%d",&queens[i].first,&queens[i].second),
         board[--queens[i].first][--queens[i].second]=2;

      scanf("%d",&k);
      vector< pair<int,int> > knights(k);
      FOR(i,k)
         scanf("%d%d",&knights[i].first,&knights[i].second),
         board[--knights[i].first][--knights[i].second]=2;

      scanf("%d",&k);
      vector< pair<int,int> > pawns(k);
      FOR(i,k)
         scanf("%d%d",&pawns[i].first,&pawns[i].second),
         board[--pawns[i].first][--pawns[i].second]=2;

      FOR(i,SZ(queens))
      {
         int x = queens[i].first, y = queens[i].second, xx, yy;
         xx=x-1; yy=y; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;--xx) board[xx][yy]=1;
         xx=x-1; yy=y+1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;--xx,++yy) board[xx][yy]=1;
         xx=x; yy=y+1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;++yy) board[xx][yy]=1;
         xx=x+1; yy=y+1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;++yy,++xx) board[xx][yy]=1;
         xx=x+1; yy=y; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;++xx) board[xx][yy]=1;
         xx=x+1; yy=y-1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;++xx,--yy) board[xx][yy]=1;
         xx=x; yy=y-1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;--yy) board[xx][yy]=1;
         xx=x-1; yy=y-1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) for(; xx>=0 && xx<n && yy>=0 && yy<m && board[xx][yy]<2;--yy,--xx) board[xx][yy]=1;
      }

      FOR(i,SZ(knights))
      {
         int x = knights[i].first, y = knights[i].second, xx, yy;
         xx=x-2; yy=y-1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x-2; yy=y+1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x-1; yy=y+2; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x+1; yy=y+2; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x+2; yy=y-1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x+2; yy=y+1; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x-1; yy=y-2; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
         xx=x+1; yy=y-2; if(xx>=0 && yy>=0 && xx<n && yy<m && board[xx][yy]<2) board[xx][yy]=1;
      }

      int cnt=0;
      FOR(i,n)
      {
         FOR(j,m)
         {
            if(board[i][j]==0)
               cnt++;
         }
      }

      printf("Board %d has %d safe squares.\n",casos,cnt);
   }

   return 0;
}
