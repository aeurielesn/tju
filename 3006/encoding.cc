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
   string S, O, strin;
   getline(cin,strin);
   sscanf(strin.c_str(),"%d",&N);
   for(int i=1;i<=N;i++)
   {
      getline(cin,strin);
      sscanf(strin.c_str(),"%d%d",&R,&C);
      string::size_type loc1 = strin.find( " ", 0 );
      string::size_type loc2 = strin.find( " ", loc1+1 );
      S = strin.substr(loc2+1);
      vector<vector<bool> > V(R, vector<bool>(C, false) );
      sz = S.size();
      x = y = 0;
      u = l = -1;
      d = R;
      r = C;
      m = 0;
      for(int j=0;j<sz;j++)
      {
         if(S[j]==' ') n=0;
         else n=S[j]-'A'+1;

         for(int k=16;k>0;k>>=1)
         {
            V[x][y] = (n&k)>0;
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
      }
      O="";
      for(int j=0;j<R;j++)
      {
         for(int k=0;k<C;k++)
         {
            O += V[j][k]+'0';
         }
      }
      cout << i << " " << O << endl;
   }

   return 0;
}
