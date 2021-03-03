#include<iostream>
using namespace std;

void sort(int * a, int size)
{
  int t = 0;
  for(int i = 0; i < size; i++)
  {

    for( int j = 0; j < size; j++)
    {

      if ((*(a + i)) > (*(a + j)))
      {

        t = *(a + i);
        *(a + i) = *(a + j);
        (*(a + j)) = t;

      }
    }
  }
}

 int main()
 {
   int ar[10];
   for(int i = 0; i < 10; ++i)
   {
     ar[i] = rand() % 10 + 1;
   }

   sort(& ar[0], 10);

   for(int i = 0; i < 10; ++i)
   {
     cout << ar[i] << endl;
   }

  return 0;
 }
