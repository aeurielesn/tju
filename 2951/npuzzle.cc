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
   char s[10];
   int X[17],Y[17];

   X[0]=0, Y[0]=0;
   X[1]=0, Y[1]=1;
   X[2]=0, Y[2]=2;
   X[3]=0, Y[3]=3;
   X[4]=1, Y[4]=0;
   X[5]=1, Y[5]=1;
   X[6]=1, Y[6]=2;
   X[7]=1, Y[7]=3;
   X[8]=2, Y[8]=0;
   X[9]=2, Y[9]=1;
   X[10]=2, Y[10]=2;
   X[11]=2, Y[11]=3;
   X[12]=3, Y[12]=0;
   X[13]=3, Y[13]=1;
   X[14]=3, Y[14]=2;

   int sum=0;
   FOR(i,4)
   {
      gets(s);
      FOR(j,4)
      {
         if(s[j]=='.') continue;
         int p=s[j]-'A';
         sum += (int)abs(i*1.0-X[p]*1.0) + (int)abs(j*1.0-Y[p]*1.0);
      }
   }
   printf("%d\n",sum);

   return 0;
}
