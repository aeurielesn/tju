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

#define PB push_back
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define MAX 100000

using namespace std;

typedef struct disjointSet
{
   int parent, rank;
   disjointSet(int p = 0, int r = 0): parent(p), rank(r) {};
};

disjointSet mySets[MAX+1];

void makeSet(int x)
{
   mySets[x].parent = x;
   mySets[x].rank = 0;
}

int findSet(int x)
{
   if(mySets[x].parent == x)
   {
      return x;
   }
   else
   {
      mySets[x].parent = findSet(mySets[x].parent);
      return mySets[x].parent;
   }
}

void unionSet(int x,int y)
{
   int xx = findSet(x), yy = findSet(y);
   if(mySets[xx].rank > mySets[yy].rank)
   {
      mySets[y].parent = xx;
//      cout << y << " -> " << x << " : " << mySets[y].parent << endl;
   }
   else if(mySets[xx].rank < mySets[yy].rank)
   {
      mySets[x].parent = yy;
//      cout << x << " -> " << y << " : " << mySets[x].parent << endl;
   }
   else if(xx != yy)
   {
      mySets[y].parent = xx;
      mySets[xx].rank++;
//      cout << y << " -> " << x << " : " << mySets[y].parent <<endl;
   }
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2190.in","r",stdin);
   freopen("out/2190.out","w",stdout);
#endif

   int N, M, K;
   int u, v, vv;

   while(scanf("%d%d%d",&N,&M,&K)==3)
   {
      FORI(i,1,N+1) makeSet(i);
      FOR(i,M)
      {
         scanf("%d%d",&u,&v);
         unionSet(u,v);
      }
      u = findSet(1);
      FOR(i,K)
      {
         scanf("%d",&v);
         vv = findSet(v);
         cout << ((u==vv)?"Yes":"No") << endl;
      }
   }

   return 0;
}
