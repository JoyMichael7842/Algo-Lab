#include<stdio.h>
#include<stdlib.h>

#define maxNode 4
typedef struct node
{
      int vertexNum;
      struct node *next;
}Node;
//list stores header node
typedef struct List
{
  Node *head;
}List;
//array of header nodes
List *adjlist[maxNode] = {0};

void addNode(int s,int d)
{
  Node *dest,*tmp,*src;
  if(adjlist[s]->head==NULL)
  {
    src = (Node*)malloc(sizeof(Node));
    src->vertexNum = s;
    src->next = NULL;
    adjlist[s]->head = src;
  }
  dest = (Node*)malloc(sizeof(Node));
  dest->vertexNum = d;
  dest->next = NULL;
  tmp = adjlist[s]->head;
  while(tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp->next = dest;
}
void printlist()
{
  int i;
  for(i=0;i<maxNode;++i)
  {
    Node *p = adjlist[i]->head;
    printf("Adjacency list for vertex %d\n",i);

    while(p)
    {
      printf("%d",p->vertexNum);
      p = p->next;
    }
    printf("\n");
  }
}
void main()
{
  int i;
  //allocating memory for each header node
  for(i=0;i<maxNode;i++)
  {
      adjlist[i] = (List*)malloc(sizeof(List));
      adjlist[i]->head = NULL;
  }
  addNode(0,1);
  addNode(0,3);
  addNode(1,2);
  printlist();
}
