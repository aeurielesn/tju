#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F
#define MAX 100000

// Algorithm Explanation from Algorithmist.com
int lis(vector<long long> &seq)
{
	vector<int> lis;
	int u, v;

	if (seq.size() < 1) return 0;

	lis.push_back(0);

	for (int i = 1; i < seq.size(); i++) {
		if (seq[lis.back()] < seq[i]) {
			lis.push_back(i);
			continue;
		}

        // Binary Search
		for (u = 0, v = lis.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (seq[lis[c]] < seq[i]) u=c+1; else v=c;
		}

		if (seq[i] < seq[lis[u]]) {
			lis[u] = i;
		}
	}

	return lis.size();
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/3120.in","r",stdin);
   freopen("out/3120.out","w",stdout);
#endif

   int N, cnt, maxi;

   while(scanf("%d",&N)==1)
   {
      vector<long long> V(N);

      FOR(i,N)
      {
         scanf("%lld",&V[i]);
      }

      printf("%d\n",lis(V));
   }

   return 0;
}
