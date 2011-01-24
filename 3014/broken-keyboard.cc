#include <queue>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define INSERT(m,c,v) m.insert(make_pair(c, v));

using namespace std;

int main()
{
   int m;
   string strin, txt;
   map<char,int> M;

   while(true)
   {
      M.clear();

      getline(cin,strin);
      sscanf(strin.c_str(),"%d",&m);
      if(m==0) break;
      getline(cin,txt);

      int cnt=0, sz=txt.size(), sum=0, maxi=0, last=0;

      //first char
      if(sz>0)
      {
         INSERT(M,txt[0],1);
         last=0;
         cnt=1;
         sum=1;
         maxi=1;
      }

      for(int i=1;i<sz;++i)
      {
         map<char,int>::iterator it = M.find(txt[i]);
         if( it != M.end() )
         {
            //found!
            it->second++;
            ++sum;
         }
         else
         {
            //not found!
            if(cnt<m)
            {
               INSERT(M,txt[i],1);
               ++sum;
               ++cnt;
            }
            else
            {
               do
               {
                  it = M.find(txt[last]);
                  it->second--;
                  sum--;
                  last++;
               }while(it->second!=0);
               last--;
               M.erase(txt[last]);
               last++;
               INSERT(M,txt[i],1);
               sum++;
            }
         }
         maxi = max(maxi,sum);
      }
      printf("%d\n",maxi);
   }

   return 0;
}
