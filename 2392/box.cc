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

#define PB push_back
#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define MAX 100000

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2392.in","r",stdin);
   freopen("out/2392.out","w",stdout);
#endif

   int x, y;
   vector< pair<int,int> > A(6);

   FOR(i,6)
   {
      cin >> x >> y;
      A[i].first = min(x,y);
      A[i].second = max(x,y);
   }

   sort(ALL(A));

   bool yes = true;

   yes &= (A[0].first==A[1].first) && (A[1].first==A[2].first) && (A[2].first==A[3].first);
   yes &= (A[0].second==A[1].second);
   yes &= (A[2].second==A[3].second);
   yes &= (A[0].second==A[4].first) && (A[4].first==A[5].first);
   yes &= (A[2].second==A[4].second) && (A[4].second==A[5].second);

   cout << ((yes)?"POSSIBLE":"IMPOSSIBLE") << endl;

   return 0;
}
