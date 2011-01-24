#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9

int M[2002][2002];

int main()
{
   memset(M,0,sizeof(M));
   int X, Y;

   X = 1000, Y = 1000;
   for(int i=0,j=0,m=0;i<=4004001;)
   {
      if(m==4) m=0;
      if(m==0 || m==2)
      {
         j++;
      }
      for(int k=0;k<j && i<=4004001;++k)
      {
         ++i;
         if(m==0) M[X++][Y]=i;
         if(m==1) M[X][Y++]=i;
         if(m==2) M[X--][Y]=i;
         if(m==3) M[X][Y--]=i;
      }
      m++;
   }

   while(cin >> X >> Y)
   {
      X += 1000, Y += 1000;
      printf("%d\n",M[X][Y]);
   }

   return 0;
}
