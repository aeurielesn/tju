#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

#define FOR(i,a) for(int i=0;i<(a);++i)
#define test(i,j) if((i>=0) && (i<R) && (j>=0) && (j<C))
#define MAX 50

using namespace std;

int M[MAX+1][MAX+1];

int main()
{
	int R, C, maxi=-1;
	cin >> R >> C;
	FOR(i,R) FOR(j,C) cin >> M[i][j];
	FOR(i,R)
	{
		FOR(j,C)
		{
			test(i-1,j) if((M[i-1][j]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i-1,j+1) if((M[i-1][j+1]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i,j+1) if((M[i][j+1]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i+1,j+1) if((M[i+1][j+1]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i+1,j) if((M[i+1][j]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i+1,j-1) if((M[i+1][j-1]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i,j-1) if((M[i][j-1]==M[i][j])) maxi=max(maxi,M[i][j]);
			test(i-1,j-1) if((M[i-1][j-1]==M[i][j])) maxi=max(maxi,M[i][j]);
		}
	}
	cout << maxi << endl;
	return 0;
}
