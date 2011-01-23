#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

#define FOR(i, x) for (int i = 0; i < x; i++)
#define FORI(i,a, x) for (int i = a; i < x; i++)
#define ALL(x) (x).begin(), (x).end()
#define FORE(i, x) for (__typeof__((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define EPS 1E-9
#define MAX 30

int main()
{
   int T, dayTzolkin, dayHaab;
   string nameTzolkin, nameHaab;
   int mTzolkin, mHaab;
   bool yes;

   char tz[][10] = { "Imix", "Ik", "Akbal", "Kan", "Chikchan", "Kimi", "Manik", "Lamat", "Muluk", "Ok", "Chuen", "Eb", "Ben", "Ix", "Men", "Kib", "Kaban", "Etznab", "Kawak", "Ajaw"};
   char ha[][10] = {  "Pohp", "Wo", "Sip", "Zotz", "Sek", "Xul", "Yaxkin", "Mol", "Chen", "Yax", "Sak", "Keh", "Mak", "Kankin", "Muan", "Pax", "Kayab", "Kumku", "Wayeb"};

   map<string,int> tzolkin, haab;

   FOR(i,20) tzolkin[tz[i]]=i;
   FOR(i,19) haab[ha[i]]=i;

   cin >> T;


   FOR(i,T)
   {
      yes = false;
      cin >> dayTzolkin >> nameTzolkin >> dayHaab >> nameHaab;
      mTzolkin=tzolkin[nameTzolkin];
      mHaab=haab[nameHaab];

      int dT=9, dH=3, nT=19, nH=2, cnt=-1;

      while((!yes) && (cnt<18980))
      {
         cnt++;

         if((dT==dayTzolkin) && (nT==mTzolkin) && (dH==dayHaab) && (nH==mHaab))
            yes = true;

         dT=(dT%13)+1;
         dH++;
         nT=(nT+1)%20;
         if((dH==21) || (dH==6 && nH==18)) nH = (nH+1)%19, dH=1;
      }

      if(yes)
      {
         printf("%d\n",(306980-cnt)/18980);
         for(int i=1152000+cnt; i<1440000; i+=18980)
         {
            printf("%d.%d.%d.%d.%d\n",i/144000,(i%144000)/7200,(i%14400%7200)/360,(i%14400%7200%360)/20,(i%14400%7200%360%20));
         }
      }
      else printf("0\n");

   }

   return 0;
}
