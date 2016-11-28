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
//http://btechsmartclass.com/DS/U2_T9.html
//http://www.sanfoundry.com/c-program-queue-using-linked-list/
node *front = NULL,*rear = NULL;
void push(int value){
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

void bfs(node* list[], int *visited,  int point){
    push(point);
    visited[point]=1;
    while(front!=NULL)
    {
        node *q=front;
        //printf("%d ",q->n);
        pop();
        node *p =list[q->n];
        for(;p!=NULL;p=p->next)
        {
            if(visited[p->n]==0)
            {
                push(p->n);
                visited[p->n]=1;
            }
        }
        printf("%d ", q->n);
        //free(q);
    }
}

int main(){
    int n, m, n1, n2,q;
    scanf("%d %d", &n, &m);
    node* list[n];
    int i;
    for(i=0;i<n;++i)
    {
        list[i]=NULL;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d", &n1, &n2);
        insert(list, n1, n2);
        insert(list, n2, n1);
    }
    int *visited=malloc(n*sizeof(int));
    node* p;
    scanf("%d", &q);
    while(q!=-1){
        for(i=0;i<n;++i){
            visited[i]=0;
        }
        bfs(list, visited, q);
        printf("\n");
        scanf("%d", &q);
    }
    return 0;
}
