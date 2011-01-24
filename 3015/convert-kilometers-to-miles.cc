#include <queue>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define MAX 80

using namespace std;

int fibs[]={1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711};

int main()
{
   int t, x, y;
   scanf("%d",&t);

   while(t--)
   {
      scanf("%d",&x);
      int n = 0;
      for(int i=20;i>=0;--i)
      {
         if(fibs[i]<=x)
         {
            x -= fibs[i];
            n += 1<<i;
         }
      }
      n = n>>1;
      y = 0;
      for(int i=0;i<21;i++)
      {
         y += fibs[i]*((n&1)>0);
         n>>=1;
      }
      printf("%d\n",y);
   }

   return 0;
}
