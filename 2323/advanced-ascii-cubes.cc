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
#define MAX 50

int minx, maxx, miny, maxy;
vector< vector<char> > P(401, vector<char>(401,'.'));

void paint(int x, int y)
{
   vector<string> cube(6);
   cube[5]="**+---+";
   cube[4]="*/   /|";
   cube[3]="+---+ |";
   cube[2]="|   | +";
   cube[1]="|   |/*";
   cube[0]="+---+**";
   FOR(i,6)
   {
      FOR(j,7)
      {
         if(cube[i][j]!='*')
         {
            P[x-i][y+j] = cube[i][j];
            minx = min(x-i,minx);
            miny = min(y+j,miny);
            maxx = max(x-i,maxx);
            maxy = max(y+j,maxy);
         }
      }
   }
}

int main()
{
   int N, M, deep=-1;
   minx = miny = 10000;
   maxx = maxy = -1;

   scanf("%d%d",&N,&M);

   vector< vector<int> > A(N, vector<int>(M));


   FOR(i,N)
   {
      FOR(j,M)
      {
         scanf("%d",&A[i][j]);
         deep = max(deep, A[i][j]);
      }
   }

   FORI(d,1,deep+1)
   {
      FOR(i,N)
      {
         FOR(j,M)
         {
            if(A[i][j]>=d)
            {
               int u = N-i-1, r = j;
               int y = 4 * r + 1 + 2 * u;
               int x = 400 - 2 * u - 3 * (d-1);
               paint(x,y);
            }
         }
      }
   }
   FORI(i,minx,maxx+1)
   {
      FORI(j,miny,maxy+1)
      {
         printf("%c",P[i][j]);
      }
      printf("\n");
   }

   return 0;
}
