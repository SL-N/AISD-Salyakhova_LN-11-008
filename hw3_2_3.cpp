#include<iostream>
using namespace std;


struct Node
{
   int item;
   Node * next;
};

struct List
{
    Node * pHead;

    void add(int item)
    {
      Node * node = new Node;
      node->item = item;


      if (!pHead)
      {
        pHead = node;
        node->next = NULL;
      }
      else
      {
        Node * p = pHead;
        while(p->next != NULL)
        {
          p = p->next;
        }
        p->next = node;
        node->next = NULL;

      }
    }

    int size()
    {
      int count = 0;
      Node * temp = pHead;
      while(temp)
      {
        temp = temp->next;
        count++;
      }
      return count;
    }


    void printAll()
    {
      Node * temp = pHead;
      do
      {
        cout << temp->item << endl;
        temp = temp->next;
      }
      while(temp->next != NULL);

      cout << temp->item << endl;
    }

    int get(int id)
    {
      Node * temp = pHead;
      for(int i = 1; i < id; ++i)
      {
        temp = temp->next;
      }
      return temp->item;
    }
};

int main()
{
  List * list = new List;
  list->add(10);
  list->add(20);
  list->add(30);
  list->printAll();
  cout << list->size() << endl << list->get(1) << endl;
  delete list;
  return 0;
}
