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
#define MAX 100

bool isNecklace(string s)
{
   string r = s, t = s;
   int zeros = count(ALL(s),'0'), cnt=0;

   string::size_type loc = s.find("0",0);
   while((loc != string::npos) && (cnt<zeros))
   {
      rotate(s.begin(),s.begin()+loc,s.end());
      r = min(r,s);
      loc = s.find("1",0);
      cnt += loc;
      if(loc!=string::npos)
      {
         loc = s.find("0",loc);
      }
   }
   return (r==t);
}

int main()
{
   int N;
   scanf("%d",&N);
   while(N--)
   {
      string necklace;
      vector<int> best(102);
      vector<string> max(102);

      cin >> necklace;
      best[0]=-1;
      max[0]=necklace[0];

      FORI(i,1,SZ(necklace))
      {
         best[i]=-1;
         max[i]=necklace.substr(0,i+1);
         FOR(j,i)
         {
            string x = necklace.substr(j+1,i-j);
            if((x<max[j]) && (!isNecklace(max[j]+x)))
            {
               best[i]=j;
               max[i]=x;
            }
         }
      }
      int act = SZ(necklace)-1;
      string r("");
      while(act!=-1)
      {
         r = "(" + max[act] + ")" + r;
         act = best[act];
      }
      cout << r << endl;
   }

   return 0;
}
