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
   freopen("in/2002.in","r",stdin);
   freopen("out/2002.out","w",stdout);
#endif

   int n;
   string acronym, text, str, str2, real;
   set<string> insignificant;
   vector<string> words;

   while(true)
   {
      scanf("%d\n",&n);
      if(n==0) break;

      insignificant.clear();

      FOR(i,n)
      {
         getline(cin,str);
         insignificant.insert(str);
      }

      while(true)
      {
         int words=0;
         text = "";
         getline(cin,str);
         if(str=="LAST CASE") break;

         istringstream strin(str);
         strin >> acronym;

         real = acronym;

         while(strin>>str2)
         {
            if(insignificant.find(str2)==insignificant.end())
               text += "|" + str2,
               words++;
         }

         acronym = "@" + acronym;
         text = "@" + text;
         vector<int> freq(SZ(text),0);
         vector< vector<int> > levels(SZ(acronym), vector<int>(SZ(text), 0));
         levels[0][0]=1;
         FOR(i,SZ(acronym)) acronym[i] = tolower(acronym[i]);

         FOR(i,SZ(acronym)-1)
         {
            int deep=0, deep2, lo, hi, cnt = 0;
            char x = acronym[i];

            if(i==0) lo=hi=1;
            else if(i==SZ(acronym)-2) lo=hi=words;
            else lo=words-SZ(acronym)+i+2, hi=i+1;

            FOR(j,SZ(text))
            {
               if(text[j]=='|') ++deep;
               if(text[j]==acronym[i])
               {
                  deep2=deep;
                  FORI(k,j+1,SZ(text))
                  {

                     if(text[k]=='|') ++deep2;
                     if(deep2>deep+1) break;
                     if(deep2>=lo && deep2<=hi && text[k]==acronym[i+1])
                     {
                        levels[i+1][k] += levels[i][j];
                     }
                  }
               }
            }
         }

      int best = 0, deep = 0;
      FOR(j,SZ(text))
      {
         if(text[j]=='|') ++deep;
         if(deep==words) best += levels[SZ(acronym)-1][j];
      }

      if(best) cout << real << " can be formed in " << best << " ways" << endl;
      else cout << real << " is not a valid abbreviation" << endl;
      }

   }

   return 0;
}
