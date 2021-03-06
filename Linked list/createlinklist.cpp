#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
   struct Node *new_node,*last;
   head = new Node;
   head->data =A[0];
   head->next=NULL;
   last=head;

   for (int i=1;i<n;i++)
   {
       new_node= new Node();
       new_node->data=A[i];
       new_node->next=NULL;
       last->next=new_node;
       last=new_node;
   }
}

int count(struct Node *headref)
{ int i=0;
  while(headref!=NULL)
  {
      i++;
      headref=headref->next;
  }
  return i;
}

void display(struct Node *headref)
{   cout<<"created linked list is :";
    while(headref!=NULL)
   {
     cout<< headref->data<<"\t";
     headref= headref->next;
   }
}

void insert_(struct Node *headref,int index ,int value )
{
    if (index < 0 || index > count(headref))
    {
        return ;
    }
    struct Node *new_node = new Node();
    new_node->data = value;

    if (index==0)
    {
       new_node->next = head;
       head = new_node;
    }
    else
    { for (int i=0; i<index-1 ;i++)
       {
           headref=headref->next;
       }
       new_node->next = headref->next;
       headref->next =new_node;
    }
}


int main()
{
  int A[]={5,6,1,2,3};
  create(A,5);
   insert_(head,0,2);
   display(head);
   return 0;
}
