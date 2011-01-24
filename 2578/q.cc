#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <valarray>

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define MAX 20

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2578.in","r",stdin);
   freopen("out/2578.out","w",stdout);
#endif

   int T, m, n, a, b;

   cin >> T;
   while(T--)
   {
      vector<int> Q;

      cin >> m >> n;

      vector<string> V(m);
      vector<bool> P(m, true);
      vector< pair<int,int> > X(n);

      FOR(i,m) cin >> V[i];
      FOR(i,n)
      {
         cin >> a >> b;
         X[i].first = b-1;
         X[i].second = a-1;
         P[a-1] = false;
      }
      FOR(i,m)
      {
         if(P[i]) Q.push_back(i);
      }
      sort(ALL(X));
      FOR(i,n)
      {
         Q.insert(Q.begin()+X[i].first,X[i].second);
      }
      cout << V[Q[0]];
      FORI(i,1,m) cout << " " << V[Q[i]];
      cout << endl;
   }

   return 0;
}
