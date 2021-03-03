#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  int a, b, c, d;
  cin>>a>>b>>c;
  d = pow(b,2) - 4 * a * c;
  //cout<<d<<endl;
  if (d < 0)
  {
    cout<<"No solution"<<endl;
  }
  else if (d == 0)
  {
    cout<<(-b / (2 * a))<<endl;
  }
  else cout<<((-b - sqrt(d)) / (2 * a))<<endl<<((-b + sqrt(d)) / (2 * a))<<endl;
  return 0;
}
