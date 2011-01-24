#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char inp[MAX+10];

int main()
{
   int t, b, n, sz, r;

   scanf("%d\n",&t);

   for(int i=0;i<t;++i)
   {
      scanf("%d ",&b);
      gets(inp);

      int sz = strlen(inp);
      n = 0, r = 1;
      for(int i=sz-1;i>=0;--i)
      {
         n += ((inp[i]-'0')*r)%10007;
         r = (r*b)%10007;
      }

      printf("%d\n",n%10007);
   }

   return 0;
}
