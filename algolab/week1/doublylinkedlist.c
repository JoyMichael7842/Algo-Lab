#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int info;
  struct node *left,*right;
}Node;
Node *head = NULL;
Node *last = NULL;
bool isempty(){
  return head = NULL
}
Node *create(Node *bnode,int x)
{
  bnode = (Node*)malloc(sizeof(struct(Node)))
  bnode->info = x;
  bnode->left=bnode->right = NULL;
  if(isempty())
  {
    last = bnode
  }
  else
  {
    last->right = bnode
    bnode->left = last
  }
  last = bnode
}
void insertnode(Node *bnode)
{
  Node *temp,*newnode;
  temp = bnode;
  int key;
  printf("enter key value");
  scanf("%d",&key);
  newnode = (Node*)malloc(sizeof(struct(Node)))
  newnode->info = key;
  newnode->left=newnode->right = NULL;

  while(temp->info!=key){
    temp = temp->right;
  }
  newnode->right = temp;
  newnode->left = temp->left;
  temp->left = newnode
  newnode->left->rigth = newnode
}
