#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define MAX 20

using namespace std;

int main()
{
   int N, R, C, sz;
   int x, y, u, d, l, r, n, m, xx, yy;
   int moves[][2]={{0,1},{1,0},{0,-1},{-1,0}};
   string S, O;
   cin >> N;
   for(int i=1;i<=N;i++)
   {
      cin >> R >> C >> S;
      vector<vector<bool> > V(R, vector<bool>(C, false) );

      for(int j=0;j<R;j++)
      {
         for(int k=0;k<C;k++)
         {
            V[j][k] = S[j*C+k]-'0';
         }
      }

      sz = (R*C)/5;
      x = y = 0;
      u = l = -1;
      d = R;
      r = C;
      m = 0;
      O = "";
      for(int j=0;j<sz;j++)
      {
         n=0;
         for(int k=16;k>0;k>>=1)
         {
            n +=  k * V[x][y];
            xx = x + moves[m][0];
            yy = y + moves[m][1];
            if( !((xx<d) && (xx>u) && (yy<r) && (yy>l)) )
            {
               if(m==0) u++;
               else if(m==1) r--;
               else if(m==2) d--;
               else if(m==3) l++;

               m = (m+1)%4;
               xx = x + moves[m][0];
               yy = y + moves[m][1];
            }
            x = xx; y = yy;
         }
         if(n==0) O += ' ';
         else if((n>0) && (n<=26))O += n - 1 + 'A';
      }

      while((sz>=1) && (O[sz-1]==' '))
      {
         O.erase( sz-1 );
         --sz;
      }

      cout << i << " " << O << endl;
   }

   return 0;
}
