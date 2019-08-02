#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
  int info;
  struct node *left,*right;
}Node;

Node *create(Node *bnode,int x)
{
  if(bnode==NULL)
  {
    bnode = (Node*)malloc(sizeof(Node));
    bnode->info = x;
    bnode->left=bnode->right=NULL;
  }
  else if(x>bnode->info)
  {
    bnode->right = create(bnode->right,x);
  }
  else if(x<bnode->info)
  {
    bnode->left = create(bnode->left,x);
  }
}

void inorder(Node *ptr)
{
  if(ptr!=NULL)
  {
    inorder(ptr->left);
    printf("%5d",ptr->info);
    inorder(ptr->right);
  }
}
int search(Node *bnode,int x)
{
  while(bnode!=NULL)
  {
    if(x>bnode->info)
    {
      return search(bnode->right,x);
    }
    else if(x<bnode->info)
    {
      return search(bnode->left,x);
    }
    else{
      return 1;
    }
  }
  return 0;

}

void main()
{
  int n,x,ch,i;
  Node *root;
  root = NULL;
  while(1)
  {
    printf("\n1.Insert\n2.traversals\n3.Serach\n4.exit\n");
    printf("enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("enter node(no dup)");
             scanf("%d",&x);
             root = create(root,x);
             break;
      case 2:inorder(root);
             break;
      case 3:printf("enter key to be searched");
             scanf("%d",&x);
             int y = search(root,x);
             if(y==1){
               printf("key found");
             }
             else if(y==0){
               printf("%d",x);
               create(root,x);
             }
             break;
      case 4:exit(0);
    }
  }
}
