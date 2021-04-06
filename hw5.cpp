#include <iostream>
#include <math.h>

using namespace std;

struct Node
{
   int item;
   Node * Next, * Prev;
};

struct SortedList
{
  Node * pHead, * pEnd;

  void add(int x)
  {

    Node *temp = new Node;
    temp->item = x;

    if(!pHead)
    {
      temp->Prev = temp->Next = NULL;
      pHead = pEnd = temp;
    }
    else if(temp->item < pHead->item)
    {
      pHead->Prev = temp;
      temp->Next = pHead;
      pHead = temp;
      pHead->Prev = NULL;
    }
    else if(temp->item < pEnd->item)
    {
      Node *t = pHead;
      while(t)
      {
        if(temp->item == t->item) break;
        else if(temp->item > t->item)
        {
          temp->Next = t->Next;
          t->Next = temp;
          temp->Prev = t;
        }
        else t = t->Next;
      }
    }
    else
    {
      pEnd->Next = temp;
      temp->Prev = pEnd;
      pEnd = temp;
      pEnd->Next = NULL;
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

  int get(int id)
  {
    Node * temp = pHead;
    for(int i = 1; i < id; ++i)
    {
      temp = temp->Next;
    }
    return temp->item;
  }
  void printAll()
  {
    if (!pHead)
        throw 1;

    Node * temp = pHead;
    while(temp)
    {
      cout << temp->item << endl;
      temp = temp->Next;
    }
  }
  bool ifHave(int x)
  {
    Node *temp = new Node;
    temp->item = x;
    Node *temp1 = pHead;
    while(temp1)
    {
      if(temp1->item == temp->item) return true;
      temp1 = temp1->Next;
    }
    return false;
  }
};

SortedList * Union(SortedList * a, SortedList * b)
{
  SortedList * c  = new SortedList;
  int s_a = a->size();
  int s_b = b->size();
  int el_c;
  for (int i = 1; i <= s_a; i++){
      el_c = a->get(i);
      if (!c->ifHave(el_c)) c->add(el_c);
  }
  for (int i = 1; i <= s_b; i++){
      el_c = b->get(i);
      if (!c->ifHave(el_c)) c->add(el_c);
      }

  return c;
};

SortedList * Intersect(SortedList * a, SortedList * b)
{
  SortedList * c  = new SortedList;
  int s_a = a->size();
  int el_c;

  for(int i = 1; i <= s_a; i++)
  {
    el_c = a->get(i);
    if(b->ifHave(el_c) && !c->ifHave(el_c)) c->add(el_c);
  }
  return c;
};

SortedList * Difference(SortedList * a, SortedList * b)
{
  SortedList * c  = new SortedList;
  int s_a = a->size();
  int el_c;
  for(int i = 1; i <= s_a; i++)
  {
    el_c = a->get(i);
    if(!b->ifHave(el_c)) c->add(el_c);
  }
  return c;
};

int main()
{
  SortedList * list = new SortedList;
  SortedList * l = new SortedList;
  l->add(80);
  l->add(50);
  l->add(30);

  list->add(20);
  list->add(10);
  list->add(30);
  // list->printAll();
  // cout << list->get(1);
  SortedList * c = Intersect(list,l);
  c->printAll();

  return 0;
}
