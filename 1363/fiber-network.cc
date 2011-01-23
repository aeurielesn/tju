#include <vector>
#include <cstring>
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
#define MAX 200

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1363.in","r",stdin);
   freopen("out/1363.out","w",stdout);
#endif

   int n, a, b, sz;
   string str;
   bool yes = false;
   int M[MAX+2][MAX+2];

   while(true)
   {
      cin >> n;
      if(n==0) break;

      memset(M,0,sizeof(M));

      while(true)
      {
         cin >> a >> b;
         if(a==0 && b==0) break;
         cin >> str;
         FOR(i,SZ(str))
         {
            M[a][b] |= (1<<(str[i]-'a'));
         }
      }

      FORI(k,1,n+1)
         FORI(i,1,n+1)
            FORI(j,1,n+1)
               M[i][j] |= (M[i][k] & M[k][j]);

      while(true)
      {
         cin >> a >> b;
         if(a==0 && b==0) break;
         yes = false;
         FOR(i,26)
         {
            if(M[a][b]&(1<<i))
            {
               yes = true;
               printf("%c",'a'+i);
            }
         }
         if(!yes) printf("-");
         printf("\n");
      }
      printf("\n");
   }

   return 0;
}
