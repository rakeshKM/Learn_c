#include <stdio.h>
#include <ue101.h>
#include <math.h>

typedef struct node
{
    int n;
    float dis;
    struct node *next;
}node;

void insert(node* list[], int a, int b, float dis){
    
    node *temp=(node*)malloc(sizeof(node));
    temp->n=b;
    temp->next=NULL;
    temp->dis=dis;
        
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

int main()
{
    // make graph
    int n, m, n1, n2;
    scanf("%d %d", &n, &m);
    node* list[n];
    int i;
    for(i=0;i<n;++i)
    {
        list[i]=NULL;
    }
    float dis;
    for(i=0;i<m;++i)
    {
        scanf("%d %d %f", &n1, &n2, &dis);
        insert(list, n1, n2, dis);
        insert(list, n2, n1, dis);
    }
    
    
    //do prims MST
    node* p;
    float cost[n];
    int visited[n];
    for(i=0;i<n;++i){
        visited[i]=0;
        cost[i]=INFINITY;
    }
    int start, no_elem=0;
    start=0;
    cost[start]=0;
    int j;
    while(no_elem<n)
    {
        visited[start]=1;
        ++no_elem;
        for(p=list[start];p!=NULL;p=p->next)
        {
            if(p->dis < cost[p->n]&& !visited[p->n])
            {
                cost[p->n]=p->dis;
            }
        }
        float min=INFINITY;
        for(j=0;j<n;++j)
        {
            if(!visited[j])
            {
                if(min>cost[j])
                {
                    min=cost[j];
                    start=j;
                }
            }
        }
    }
    
    float tot=0;
    for(i=0;i<n;++i){
        tot+=cost[i];
    }
    
    printf("%g", tot);
    
    return 0;
}


/*

4 6
0 1 5
0 2 3
3 0 6
1 3 7
2 1 4
2 3 5

output:12
*/
