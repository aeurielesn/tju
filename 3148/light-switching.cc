#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 262144

int A[MAX+1], C[MAX+1];
int O[100001], S[100001], E[100001];

int query(int node, int b, int e, int i, int j, int flip)
{
   int p1=0, p2=0, left=2*node;
   if ((b >= i) && (e <= j))
   {
      if(flip) return e - b - A[node] + 1;
      else return A[node];
   }
   int f = (flip+C[node])&1, k = (b + e) / 2;
   if(i <= k) p1 = query(left, b, k, i, j, f);
   if(j >= k+1) p2 = query(left+1, k+1, e, i, j, f);
   return p1 + p2;
}

void flip(int node, int b, int e, int i, int j)
{
   int left=2*node;
   if ((b >= i) && (e <= j))
   {
      C[node]=1-C[node];
   }
   else
   {
      int k = (b + e)/2;
      if(i <= k) flip(left, b, k, i, j);
      if(j >= k+1) flip(left+1, k + 1, e, i, j);
   }
   if(b==e) A[node]=C[node];
   else
   {
      if(C[node]) A[node] = e - b - A[left] - A[left+1] + 1;
      else A[node] = A[left] + A[left+ 1];
   }
}

int main()
{
   int N, M;
   memset(C,0,sizeof(C));
   memset(A,0,sizeof(A));

   scanf("%d%d",&N,&M);
   for(int i=0;i<M;++i) scanf("%d%d%d",&O[i],&S[i],&E[i]);

   for(int i=0,j;i<M;++i)
   {
      if(O[i])
      {
         j = query(1, 0, N-1, S[i]-1, E[i]-1, 0);
         printf("%d\n",j);
      }
      else flip(1,0,N-1,S[i]-1,E[i]-1);
   }
   return 0;
}
