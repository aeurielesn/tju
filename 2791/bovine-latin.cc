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
   freopen("in/2791.in","r",stdin);
   freopen("out/2791.out","w",stdout);
#endif

   int N;
   string str;

   cin >> N;
   while(N--)
   {
      cin >> str;
      if(str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' || str[0]=='u')
         cout << str << "cow" << endl;
      else
         cout << str.substr(1) << str[0] << "ow" << endl;
   }

   return 0;
}
