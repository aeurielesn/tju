#include <iostream>

using namespace std;

const double pi = 3.141592653589793238462;

int main()
{
   double R;
   scanf("%lf\n",&R);
   printf("%.6lf\n",pi*R*R);
   printf("%.6lf\n",2*R*R);

   return 0;
}
