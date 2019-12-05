#include<iostream>
#include <stdlib.h>
using namespace std;
struct node
{ public:
  int data;
  node* prev;
  node* next;
};

node* head;

void insert(int data)
{
  node* temp = (node*)malloc(sizeof(node));
  temp->data=data;
  temp->next=NULL;
  node* current = head;
  if(head==NULL)
  {
    temp->next=head;
    temp->prev=NULL;
    head=temp;
  }
  else
  {
    current=head;
    while(current->next!=NULL)
    {
      current=current->next;
    }
    current->next=temp;
    temp->prev=current;
  }
}

void delete_node(int value)
{
  node* temp=head;
  node* temp2=head;
  temp=temp->next;

  if(temp2->data==value)
  {
    head=temp;
    temp2->next=NULL;
    temp2->prev=NULL;
    free(temp2);
  }
  else
  {
    while(temp->next!=NULL)
    {
      if(temp->data!=value)
      {
        temp=temp->next;
        temp2=temp2->next;
      }
      else
        break;
    }
    temp2->next=temp->next;
    if(temp->next!=NULL)
      temp->next->prev=temp2;
    temp->next=temp->prev=NULL;
    free(temp);
  }

}

void display()
{ node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<endl;
    temp=temp->next;
  }   
}

int main()
{
  int choice;
  do
  {
    cout<<"1.Insert \n2.Delete \n3.Display \n4.Exit "<<endl;
    cout<<"Enter choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:
        int data;
        cout<<"Enter value to be added: "<<endl;
        cin>>data;
        insert(data);
        break;

      case 2:
        int value;
        cout<<"Enter value to be deleted: "<<endl;
        cin>>value;
        delete_node(value);
        break;

      case 3:
        display();
        break;
    }
  }
  while(choice!=4);

  return 0;

}
