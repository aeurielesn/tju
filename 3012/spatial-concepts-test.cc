#include <cstdio>
#include <cstring>
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

vector< pair<char,int> > L(4), D(4), X(4);

// Clockwise
int cw(int e, int t)
{
   FOR(i,t) e = (e%4)+1;
   return e;
}

// Counter-clockwise
int ccw(int e, int t)
{
   FOR(i,t) e = (e==1)?4:(e-1);
   return e;
}

void doL()
{
   // Swap places
   swap(D[1],X[0]);
   swap(D[3],X[2]);
   swap(D[1],D[3]);

   // Face 1
   X[1].second = cw(X[1].second,1);
   D[0].second = cw(D[0].second,1);

   // Face 6
   X[3].second = ccw(X[3].second,1);
   D[2].second = ccw(D[2].second,1);

   // Rotate
   rotate(L.begin(),L.begin()+1,L.end());
}

void doD()
{
   // Swap places
   swap(L[1],X[1]);
   swap(L[3],X[3]);
   swap(X[1],X[3]);

   // Rotate
   FOR(i,4) D[i].second = cw(D[i].second,1);

   // Rotate
   L[1].second = cw(L[1].second,1);
   L[3].second = cw(L[3].second,1);
   X[1].second = cw(X[1].second,1);
   X[3].second = cw(X[3].second,1);

   // Face 3
   L[0].second = cw(L[0].second,1);
   X[0].second = cw(X[0].second,1);

   // Face 5
   L[2].second = ccw(L[2].second,1);
   X[2].second = ccw(X[2].second,1);

   // Rotate
   rotate(D.begin(),D.end()-1,D.end());
}

int main()
{
   int T;

   cin >> T;
   string str;
   vector<string> S(5);
   vector<bool> R(5,false);
   char x[7];

   FORI(c,1,T+1)
   {
      cin >> str;
      FOR(i,5) cin >> S[i], R[i] = false;

      L[0] = make_pair( str[4], str[5]-'0'); // face 3
      L[1] = make_pair( str[6], str[7]-'0'); // face 4
      L[2] = make_pair( str[8], str[9]-'0'); // face 5
      L[3] = make_pair( str[2], str[3]-'0'); // face 2

      D[0] = make_pair( str[0], str[1]-'0'); // face 1
      D[1] = L[1]; // face 4
      D[2] = make_pair( str[10], str[11]-'0'); // face 6
      D[3] = L[3]; // face 2

      X[0] = L[0]; // face 3
      X[1] = D[0]; // face 1
      X[2] = L[2]; // face 5
      X[3] = D[2]; // face 6

      // Faces 1,2,6,4 up!
      FOR(k,4) // D-rotates
      {
         FOR(i,4) // L-rotates
         {
            sprintf(x,"%c%d%c%d%c%d",D[0].first,cw(D[0].second,2),
                                     L[1].first,L[1].second,
                                     L[0].first,cw(L[0].second,3));
            FOR(j,5) // Answers
            {
               // Check
               if(strcmp(x,S[j].c_str())==0)
                  R[j]=true;
            }
            doL();
         }
         doD();
      }

      // Faces 3,5 up!
      doL(), doD();
      FOR(k,2) // D-rotates
      {
         FOR(i,4) // L-rotates
         {
            sprintf(x,"%c%d%c%d%c%d",D[0].first,cw(D[0].second,2),
                                     L[1].first,L[1].second,
                                     L[0].first,cw(L[0].second,3));
            FOR(j,5) // Answers
            {
               // Check
               if(strcmp(x,S[j].c_str())==0)
                  R[j]=true;
            }
            doL();
         }
         doD(); doD();
      }

      int sum=0;
      FOR(i,5) sum += R[i];
      printf("%d %d %c %c %c %c %c\n",c,sum,R[0]?'Y':'N',R[1]?'Y':'N',R[2]?'Y':'N',R[3]?'Y':'N',R[4]?'Y':'N');

   }

   return 0;
}
