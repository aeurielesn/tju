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

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/3108.in","r",stdin);
   freopen("out/3108.out","w",stdout);
#endif

   int T, m1, m2, x;

   cin >> T;
   FORI(caso,1,T+1)
   {
      vector<int> A1, A2;
      vector<int>::iterator result1, result2;
      cin >> m1 >> m2;
      FOR(i,m1)
      {
         cin >> x;
         result1 = find(ALL(A1), x);
         if(result1 == A1.end()) A1.push_back(x);
      }
      FOR(i,m2)
      {
         cin >> x;
         result1 = find(ALL(A1), x);
         result2 = find(ALL(A2), x);
         if(result1 != A1.end())
            if(result2 == A2.end())
               A2.push_back(x);
      }
      sort(ALL(A2));
      bool first = true;
      FOR(i,SZ(A2))
      {
         if(!first) cout << " ";
         cout << A2[i];
         first = false;
      }
      cout << endl;
   }

   return 0;
}
