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

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define INF 0x3F3F3F3F

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/2520.in","r",stdin);
   freopen("out/2520.out","w",stdout);
#endif
   int sum;
   string str;

   while(true)
   {
      getline(cin,str);
      if(str[0]=='#') break;
      sum = 0;
      FORI(i,1,str.size()+1) sum += i * (str[i-1]==' '?0:(str[i-1]-'A'+1));
      cout << sum << endl;
   }

   return 0;
}
