#include <iostream>
#include <cstdlib>
#include <cstdio>

#define FOR(i,a) for(int i=0;i<(a);++i)
#define MAX 100000

using namespace std;

int M[MAX+1];

int main()
{
   int N,sum=0;
	bool debt=false;

   cin >> N;
   FOR(i,N)
	{
		cin >> M[i];
		debt = debt||(M[i]<0);
	}

	int first=-1, steps=0;
	if (debt)
	{
		FOR(i,N)
		{
			steps++;
			sum += M[i];
			if((sum<0) && (first==-1))
			{
				first=i;
			}
			else if((sum>=0) && (first!=-1))
			{
				steps+=(i-first)*2;
				first=-1;
			}
		}
	}
	cout << steps << endl;

   return 0;
}
