#include <iostream>
using namespace std;

int sum(int * a, int size)
{
  int s = 0;
  for (int i = 0; i < size; i++)
  {
    s += *(a + i);
  }
  return s;
}

int main()
{
  int ar[10];
  for (int i = 0; i < 10; ++i)
  {
    ar[i] = i;
  }
  cout << sum(& ar[0], 10) << endl;
  return 0;
}
