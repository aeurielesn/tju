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



int main()
{
   vector<string> W(5),P(5);
   string str, r;

   P[0]="..#..";
   P[1]=".#.#.";
   P[2]="#.@.#";
   P[3]=".#.#.";
   P[4]="..#..";

   W[0]="..*..";
   W[1]=".*.*.";
   W[2]="*.@.*";
   W[3]=".*.*.";
   W[4]="..*..";

   getline(cin,str);

   FOR(j,2)
   {
      FORI(i,1,SZ(str)+1)
         if(i%3==0) cout << W[j].substr(0, (i==SZ(str))?5:4 );
         else cout << P[j].substr(0, (i==SZ(str))?5:4 );
      cout << endl;
   }

   FORI(i,1,SZ(str)+1)
   {
      if(i%3==0) cout << "*." << str[i-1] << ".*";
      else if((i>1) && ((i-1)%3==0)) cout << "." << str[i-1] << ".";
      else cout << "#." << str[i-1] << ".";
   }
   if(SZ(str)%3!=0) cout << "#";
   cout << endl;

   FORI(j,3,5)
   {
      FORI(i,1,SZ(str)+1)
         if(i%3==0) cout << W[j].substr(0, (i==SZ(str))?5:4 );
         else cout << P[j].substr(0, (i==SZ(str))?5:4 );
      cout << endl;
   }

   return 0;
}
