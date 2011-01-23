#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-10
#define INF 0x3F3F3F3F

int cmp(double x, double y = 0, double tol = EPS) {
   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

char mapSum(char a, char b)
{
   if(a=='@') return b;
   if(b=='@') return a;

   if(a=='V' && b=='V') return 'V';
   if(a=='V' && b=='U') return 'U';
   if(a=='V' && b=='C') return 'C';
   if(a=='V' && b=='D') return 'D';

   if(a=='U' && b=='V') return 'U';
   if(a=='U' && b=='U') return 'C';
   if(a=='U' && b=='C') return 'D';
   if(a=='U' && b=='D') return 'V';

   if(a=='C' && b=='V') return 'C';
   if(a=='C' && b=='U') return 'D';
   if(a=='C' && b=='C') return 'V';
   if(a=='C' && b=='D') return 'U';

   if(a=='D' && b=='V') return 'D';
   if(a=='D' && b=='U') return 'V';
   if(a=='D' && b=='C') return 'U';
   if(a=='D' && b=='D') return 'C';
}

bool hasCarry(char a, char b)
{
   if(a=='U' && b=='D') return true;
   if(a=='C' && b=='C') return true;
   if(a=='C' && b=='D') return true;
   if(a=='D' && b=='U') return true;
   if(a=='D' && b=='C') return true;
   if(a=='D' && b=='D') return true;
   return false;
}

string suma(string s1, string s2)
{
   int sz1 = SZ(s1), sz2 = SZ(s2), sz = max(sz1,sz2);
   string r("");
   char a, b, c, d, carry = '@';
   reverse(ALL(s1));
   reverse(ALL(s2));
   FOR(i,sz)
   {
      a = '@', b = '@';
      if(i<sz1) a = s1[i];
      if(i<sz2) b = s2[i];

      c = mapSum(carry,a);
      d = mapSum(c,b);

      if(hasCarry(carry,a) || hasCarry(c,b)) carry = 'U';
      else carry = '@';

      r += d;
   }
   if(carry != '@') r += carry;
   reverse(ALL(r));
   return r;
}

int main()
{
   int N;
   string strin, num1, num2, num3, op;

   getline(cin,strin);
   sscanf(strin.c_str(),"%d",&N);

   printf("COWCULATIONS OUTPUT\n");
   while(N--)
   {
      getline(cin,num1);
      getline(cin,num2);
      FOR(i,3)
      {
         getline(cin,op);
         if(op=="A") num3 = suma(num1,num2), num2 = num3;
         else if(op=="L") num2 += "V";
         else if(op=="R") num2 = "V" + num2.substr(0,SZ(num2)-1);
      }
      getline(cin,num3);
      int sz = SZ(num2);
      FOR(i,8-sz) num2 = "V" + num2;
      if(num2==num3) printf("YES\n");
      else printf("NO\n");
   }
   printf("END OF OUTPUT\n");

   return 0;
}
