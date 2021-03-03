#include<iostream>
using namespace std;

int main()
{
  int * a1 = new int[10];
  int * a2 = new int[10];
  for (int i = 0; i < 10; ++i)
  {
     a1[i] = rand() % 10 + 1;
     a2[i] = rand() % 10 + 1;
  }

  int * a3 = new int[20];
  for(int i = 0; i < 10; ++i)
  {
     a3[i] =  a1[i];
     a3[19 - i] =  a2[9 - i];
  }

  delete[]a2;
  delete[]a1;
  for(int i = 0; i < 20; ++i)
  {
    cout <<  a3[i] << endl;
  }
  return 0;
}
