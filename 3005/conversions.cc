#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
   int N, sz;
   double D;
   string M;
   scanf("%d",&N);
   for(int i=1;i<=N;++i)
   {
      cin >> D >> M;
      printf("%d ",i);
      if(M=="kg") printf("%.4lf lb\n",D*2.2046);
      if(M=="lb") printf("%.4lf kg\n",D*0.4536);
      if(M=="l") printf("%.4lf g\n",D*0.2642);
      if(M=="g") printf("%.4lf l\n",D*3.7854);
   }

   return 0;
}
