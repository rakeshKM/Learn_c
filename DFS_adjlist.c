#include <stdio.h>
#include <ue101.h>


typedef struct node{
    int val;
    struct node *next;
}node;

void addEdge(node *list[], int b, int c){
    node *temp=(node *)malloc(sizeof(node));
    temp->next=list[b];
    list[b]=temp;
    temp->val=c;
    
    node *temp2=(node *)malloc(sizeof(node));
    temp2->next=list[c];
    list[c]=temp2;
    temp2->val=b;
}

void insert(node *list[],int vi,int vj){
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->val=vj;
    q->next=NULL;
    if(list[vi]==NULL){
        list[vi]=q;
    }else{
        p=list[vi];
        while( p->next!=NULL ){
            p=p->next;
        }
        p->next=q;
    }
} 
void sort(node *head){
    if(head!=NULL){
        node *t=head;
        int swapped;
        do{
            swapped=0;
            while(t->next!=NULL){
                if(t->val > t->next->val){
                    int temp=t->val;
                    t->val=t->next->val;
                    t->next->val=temp;
                    swapped=1;
                }
                t=t->next;
            }
            t=head;
        }while(swapped);
    }
}
void dfs(node *list[],int *visited,int x, int n)
{
    visited[x]=1;
    node *temp=list[x];
    while(temp!=NULL){
        x=temp->val;
        if(visited[temp->val]==0)
        {
            printf("%d ",temp->val); 
            dfs(list,visited,(temp->val),n);
        }
        temp=temp->next;
        
    }
}
// Driver program to test above functions
int main()
{
    // create the graph
    int v,i,V,E,x,y;
    scanf("%d %d",&V,&E);
    node *list[V];
    for(i=0;i<V;i++) {
        list[i]=NULL;
    }
    for(i=0;i<E;i++){
        scanf("%d %d",&x,&y);    
        addEdge(list,x,y);
    }
 
    
    int *visited=malloc(V*sizeof(int));
    int a,s;
    for(a=0;a<V;a++) 
            sort(list[a]);
    scanf("%d",&s);
    while(s!=-1){
        for(a=0;a<V;a++) 
            visited[a]=0;
         if(s!=-1){
            //visited[x]=1;
            printf("%d ",s);
            dfs(list,visited,s,V);
        }
        printf("\n");
        scanf("%d ",&s);
        
    }
 
    return 0;
}
