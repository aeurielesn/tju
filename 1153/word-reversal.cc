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
   freopen("in/1153.in","r",stdin);
   freopen("out/1153.out","w",stdout);
#endif

   int T;
   string str;
   scanf("%d\n",&T);
   while(T--)
   {
      getline(cin,str);
      string::size_type loc1 = 0;
      string::size_type loc2 = str.find(" ", 0);
      while(loc2 != string::npos)
      {
         reverse(str.begin()+loc1, str.begin()+loc2);
         loc1 = loc2+1;
         loc2 = str.find(" ", loc1+1);
      }
      reverse(str.begin()+loc1, str.end());
      cout << str << endl;
   }

   return 0;
}
