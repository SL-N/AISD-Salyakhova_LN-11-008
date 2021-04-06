#include <iostream>
#include <cmath>
using namespace std;

struct MaxHeap
{
    int * array;
    int size;
    int maxSize;

    int Parent(int i) { return (i - 1) / 2; }
    int LeftChild(int i) { return 2 * i + 1; }
    int RightChild(int i) { return 2 * i + 2; }

    MaxHeap(int maxSize)
    {
      this->maxSize = maxSize;
      size = -1;
      array = new int [maxSize];
    }

    void SiftUp(int i)
    {
      while(array[i] > array[Parent(i)] && i > 0)
      {
        int temp = array[i];
        array[i] = array[Parent(i)];
        array[Parent(i)] = temp;
        i = Parent(i);
      }
    }

    void SiftDown(int i)
    {
      int maxI = array[i];
      if (LeftChild(i) < size && RightChild(i) < size)
      {
        if(array[LeftChild(i)] > maxI && array[LeftChild(i)] > array[RightChild(i)])
        {
          array[i] = array[LeftChild(i)];
          array[LeftChild(i)] = maxI;
          SiftDown(LeftChild(i));
        }
        else if(array[RightChild(i)] > maxI)
        {
          array[i] = array[RightChild(i)];
          array[RightChild(i)] = maxI;
          SiftDown(RightChild(i));
        }
      }
    }

    void Insert(int p)
    {
      if((size + 1) < maxSize)
      {
        size++;
        array[size] = p;
        SiftUp(size);
      }
      else
      {
        cout << "Массив переполнен" << endl;
      }
    }

    int ExtractMax()
    {
      int result = array[0];
      array[0] = array[size];
      array[size] = 0;
      size--;
      SiftDown(0);
      return result;
    }

    void printAll()
    {
      for (int i = 0;i <= size;i++)
      {
          cout << array[i] << endl;
      }
    }
};


int * HeapSort(int * array, int size)
{
  MaxHeap * heap = new MaxHeap(size);
  int * help_ar = new int[size];
  for(int i = 0; i < size; ++i)
  {
    heap->Insert(array[i]);
  }
  for(int i = 0; i < size; ++i)
  {
    help_ar[i] = heap->ExtractMax();
  }
  return help_ar;
};

int main()
{
  // MaxHeap * heap = new MaxHeap(4);
  //
  // heap->Insert(1);
  // heap->Insert(2);
  // heap->Insert(5);
  // heap->Insert(40);
  // heap->Insert(50);
  // heap->ExtractMax();
  int size = 6;
  int array[6] = {1,2,3,4,5,6};

  int * array_n = HeapSort(array,size);
  for(int i = 0; i < size; ++i)
  {
    cout<<array_n[i]<<endl;;
  }
  // heap->printAll();

  return 0;
}
