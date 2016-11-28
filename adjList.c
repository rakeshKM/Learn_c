#include <stdio.h>
#include <stdlib.h>

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
        //insert(list,x,y);
        //insert(list,y,x);
    }
 
    // print the adjacency list representation of the above graph
    int s;
    scanf("%d",&s);
    while(s!=-1){
        
        node* temp = list[s];
        if(temp==NULL){
            printf("none");
        }else{
            
            while(temp->next!=NULL){
                printf("%d ",temp->val);
                temp=temp->next;
            }
            printf("%d",temp->val);
            
        }
        printf("\n");
        scanf("%d ",&s);
        
    }
