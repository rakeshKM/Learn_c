#include <stdio.h>
#include <ue101.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node{
    int n;
    struct node *next;
}node;

void insert(node* list[], int a, int b){
    
    node *temp=(node*)malloc(sizeof(node));
    temp->n=b;
    temp->next=NULL;
        
    if(list[a]==NULL){
        list[a]=temp;
    }
    else{
        node *p;
        p=list[a];
        while( p->next!=NULL ){
            p=p->next;
        }
        p->next=temp;
    }
}
node *front = NULL,*rear = NULL;
void push(int value)
{
   node *newNode=(node*)malloc(sizeof(node));
   newNode->n = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
}
void pop(){
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      node *temp = front;
      front = front -> next;
      //free(temp);
   }
}

void bfs(node* list[], int *dis,  int point)
{
    
    push(point);
    dis[point]=0;
    while(front!=NULL)
    {
        node *q=front;
        pop();
        node *p =list[q->n];
        for(;p!=NULL;p=p->next)
        {
            if(dis[p->n]==-1)
            {
                push(p->n);
                dis[p->n]=dis[q->n]+1;
            }
        }
        free(q);
    }
}

int main()
{
    int n, m, n1, n2,q;
    scanf("%d %d", &n, &m);
    node* list[n];
    int i;
    for(i=0;i<n;++i)
    {
        list[i]=NULL;
    }
    for(i=0;i<m;++i)
    {
        scanf("%d %d", &n1, &n2);
        insert(list, n1, n2);
        insert(list, n2, n1);
    }
    int dis[n];
    node* p;
    scanf("%d", &q);
    while(q!=-1){
        for(i=0;i<n;++i){
            dis[i]=-1;
        }
        bfs(list, dis, q);
        for(i=0;i<n;++i){
            printf("%d ", dis[i]);
        }
        printf("\n");
        scanf("%d", &q);
    }
    return 0;
}
