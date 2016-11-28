#include <stdio.h>
#include <ue101.h>

typedef struct node
{
    int n;
    struct node *next, *prev;
}node;
void insert(node** head, int val)
{
    if(*head==NULL)
    {
        *head=(node*)malloc(sizeof(node));
        (*head)->n=val;
        (*head)->next=NULL;
    }
    else if((*head)->n>val)
    {
        node* ptr=*head;
        *head=(node*)malloc(sizeof(node));
        (*head)->n=val;
        (*head)->next=ptr;
    }
    else
    {
        insert(&((*head)->next), val);
    }
}
void push(node **first, node **last, int t)
{
    node *ptr= (node*)malloc(sizeof(node));
    ptr->n=t;
    ptr->next=NULL;
    if(*last==NULL)//empty list
    {
        *first=*last=ptr;
        (*last)->prev=(*last)->next=NULL;
        return;
    }
    ptr->prev=*last;
    (*last)->next=ptr;
    *last=ptr;
}
void pop(node **first, node **last)
{
    node *ptr=(*first)->next;
    if(ptr==NULL)
    {
        *last=*first=NULL;
        return;
    }
    ptr->prev=NULL;
    *first=ptr;
}
void bfs(node** arr, int *dis,  int point)
{
    node *head=NULL, *tail=NULL;
    push(&head, &tail, point);
    dis[point]=0;
    while(head!=NULL)
    {
        node *q=head;
        pop(&head, &tail);
        node *p =arr[q->n];
        for(;p!=NULL;p=p->next)
        {
            if(dis[p->n]==-1)
            {
                push(&head, &tail, p->n);
                dis[p->n]=dis[q->n]+1;
            }
        }
        free(q);
    }
}
void constgraph(node** arr, int a, int b)
{
    insert(&arr[a], b);
    insert(&arr[b], a);
}
int main()
{
    // Your code goes here
    int n, m, n1, n2, q;
    scanf("%d %d", &n, &m);
    int dis[n];
    node* points[n];
    int i;
    for(i=0;i<n;++i)
    {
        points[i]=NULL;
    }
    for(i=0;i<m;++i)
    {
        scanf("%d %d", &n1, &n2);
        constgraph(points, n1, n2);
    }
    node* p;
    scanf("%d", &q);
    while(q!=-1)
    {
        for(i=0;i<n;++i)
        {
            dis[i]=-1;
        }
        bfs(points, dis, q);
        for(i=0;i<n;++i)
        {
            printf("%d ", dis[i]);
        }
        printf("\n");
        scanf("%d", &q);
    }
    return 0;
}
