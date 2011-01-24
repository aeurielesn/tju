#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>

#define MAX 20
#define EPS 1E-9

using namespace std;

int main()
{
   int r, w, l, cnt=1;
   double rp=0.0;

   while(true)
   {
      scanf("%d",&r);
      if(r==0) break;
      scanf("%d%d",&w,&l);
      rp = sqrt( (w*1.0)*(w*1.0) + (l*1.0)*(l*1.0) ) / 2.0;
      if( rp <= r*1.0 )
         printf("Pizza %d fits on the table.\n",cnt);
      else
         printf("Pizza %d does not fit on the table.\n",cnt);
      cnt++;
   }

   return 0;
}
