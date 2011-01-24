#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9

string str;

void del(int a, int b)
{
   int d = (b-a+1)/3;
   if(a==b)
      return;
   FORI(i,a+d,a+2*d)
      str[i]=' ';
   del(a,a+d-1);
   del(a+2*d,b);
}

int main()
{
   int T, sz;

   while(cin >> T)
   {
      str = "";
      int sz = (int)pow(3.0,T*1.0);
      FOR(i,sz) str += "@";
      del(0,sz-1);
      cout << str << endl;
   }
   return 0;
}
