#include <vector>
#include <cstring>
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
#define MAX 1000

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen("in/1368.in","r",stdin);
   freopen("out/1368.out","w",stdout);
#endif

   string str;
   char A[MAX+1];
   memset(A,0,sizeof(A));
   A['1']='`';
   A['2']='1';
   A['3']='2';
   A['4']='3';
   A['5']='4';
   A['6']='5';
   A['7']='6';
   A['8']='7';
   A['9']='8';
   A['0']='9';
   A['-']='0';
   A['=']='-';
   A['W']='Q';
   A['E']='W';
   A['R']='E';
   A['T']='R';
   A['Y']='T';
   A['U']='Y';
   A['I']='U';
   A['O']='I';
   A['P']='O';
   A['[']='P';
   A[']']='[';
   A['\\']=']';
   A['S']='A';
   A['D']='S';
   A['F']='D';
   A['G']='F';
   A['H']='G';
   A['J']='H';
   A['K']='J';
   A['L']='K';
   A[';']='L';
   A['\'']=';';
   A['X']='Z';
   A['C']='X';
   A['V']='C';
   A['B']='V';
   A['N']='B';
   A['M']='N';
   A[',']='M';
   A['.']=',';
   A['/']='.';
   A[' ']=' ';

   while(getline(cin,str))
   {
      FOR(i,SZ(str))
      {
         printf("%c",A[str[i]]);
      }
      printf("\n");
   }

   return 0;
}
