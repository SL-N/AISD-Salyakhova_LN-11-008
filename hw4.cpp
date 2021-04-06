#include<iostream>
using namespace std;

struct Node
{
   int item;
   Node * Next, * Prev;
};

struct List
{
   Node * pHead, * pEnd;

   void add(int x)
 {
     Node *temp = new Node;
     temp->Next = NULL;
     temp->item = x;

     if (!pHead)
   {
      temp->Prev = temp->Next =NULL;
      pHead = pEnd = temp;
    }
     else
    {
      temp->Prev = pEnd;
      pEnd->Next = temp;
      pEnd = temp;
    }
  }

   int size()
    {
      int count = 0;
      Node * temp = pHead;
      while(temp)
      {
        temp = temp->Next;
        count++;
      }
      return count;
    }

    int get(int id)
    {
      Node * temp = pHead;
      for(int i = 1; i < id; ++i)
      {
        temp = temp->Next;
      }
      return temp->item;
    }

    void enqueue(int item)
    {
      Node * node = new Node;
      node->item = item;
      node->Next = pHead;
      pHead = node;
    }

    int dequeue()
    {
        if (!pEnd)
            throw 1;
        else
        {
          Node * temp = pEnd->Prev;
          int x = pEnd->item;
          delete pEnd;
          pEnd = temp;
          pEnd->Next = NULL;
          return x;
        }
    }

    void insertAt(int item, int id)
    {
      Node *temp = new Node;
      temp->item = item;

      if(!pHead)
      {
        temp->Prev = NULL;
        temp->Next = NULL;
        pHead = pEnd = temp;
      }
      else
      {
        if(id == 1)
        {
          pHead->Prev = temp;
          temp->Next = pHead;
          temp->Prev = NULL;
          pHead = temp;
        }
        else
        {
          Node *temp1 = pHead;
          for(int i = 1; i < id - 1; ++i) temp1 = temp1->Next;
          Node *temp2 = temp1->Next;
          temp1->Next = temp;
          temp2->Prev = temp;
          temp->Next = temp2;
          temp->Prev = temp1;
        }
      }
    }

    void removeAt(int id)
    {
      Node *temp = pHead;
      int count = 0;
      while(temp)
      {
        count++;
        if(count == id)
        {
          if(temp->Prev)
          {
            if(temp->Next)
            {
              Node *tempN = temp->Next;
              Node *tempP = temp->Prev;
              tempN->Prev = tempP;
              tempP->Next = tempN;
              delete temp;
            }
            else
            {
              pEnd = temp->Prev;
              pEnd->Next = NULL;
              delete temp;
            }
          }
          else
          {
            pHead = temp->Next;
            pHead->Prev = NULL;
            delete temp;
          }
          break;
        }
        else if(temp->Next)
        {
          temp = temp->Next;
        }
      }
    }

    void printAll()
    {
      if (!pHead)
          throw 1;

      Node * temp = pHead;
      while(temp)
      {
        int x = temp->item;
        cout << x << endl;
        temp = temp->Next;
      }
    }
};

int main()
{
  List * list = new List;
  list->add(10);
  list->add(50);
  list->add(20);
  list->add(70);
  list->add(90);
  // cout<<list->size()<<endl<<list->get(1)<<endl<<endl;
  // list->printAll();
  list->enqueue(30);
  // cout<<list->size()<<endl<<list->get(1)<<endl<<endl;
  // list->printAll();
  // list->dequeue();
  // cout<<list->size()<<endl<<list->get(1)<<endl<<endl;
  // list->printAll();
  // cout<<endl;
  // list->insertAt(40,2);
  // list->printAll();
  // cout<<list->size()<<endl<<list->get(1)<<endl;
  // list->removeAt(3);
  // cout<<list->dequeue();
  // cout<<endl;
  list->printAll();
  list->removeAt(3);
  cout<<endl;
  // cout<<list->size()<<endl<<list->get(1)<<endl<<endl;
  list->printAll();
  return 0;
}
