#include <stdio.h>
#include <ue101.h>
#include <math.h>

typedef struct node
{
    int n;
    float dis;
    struct node *next;
}node;

void insert(node** head, int val, float dis);

void constgraph(node** arr, int a, int b, float dis)
{
    insert(&arr[a], b, dis);
    insert(&arr[b], a, dis);
}
int main()
{
    // Your code goes here
    int n, m, n1, n2;
    scanf("%d %d", &n, &m);
    node* points[n];
    int i;
    for(i=0;i<n;++i)
    {
        points[i]=NULL;
    }
    float dis;
    for(i=0;i<m;++i)
    {
        scanf("%d %d %f", &n1, &n2, &dis);
        constgraph(points, n1, n2, dis);
    }
    node* p;
    float c[n];
    int q[n], noelem=0;
    for(i=0;i<n;++i)
    {
        q[i]=1;
        c[i]=INFINITY;
    }
    c[0]=0;
    i=0;
    int j;
    while(noelem<n)
    {
        q[i]=0;
        ++noelem;
        for(p=points[i];p!=NULL;p=p->next)
        {
            if(p->dis<c[p->n]&& q[p->n])
            {
                c[p->n]=p->dis;
            }
        }
        float min=INFINITY;
        for(j=0;j<n;++j)
        {
            if(q[j])
            {
                if(min>c[j])
                {
                    min=c[j];
                    i=j;
                }
            }
        }
    }
    float tot=0;
    for(i=0;i<n;++i)
    {
        tot+=c[i];
    }
    printf("%g", tot);
    return 0;
}

void insert(node** head, int val, float dis)
{
    if(*head==NULL)
    {
        *head=(node*)malloc(sizeof(node));
        (*head)->n=val;
        (*head)->next=NULL;
        (*head)->dis=dis;
    }
    else if((*head)->n>val)
    {
        node* ptr=*head;
        *head=(node*)malloc(sizeof(node));
        (*head)->n=val;
        (*head)->next=ptr;
        (*head)->dis=dis;
    }
    else
    {
        insert(&((*head)->next), val, dis);
    }
}





