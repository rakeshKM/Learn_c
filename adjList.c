
#include <stdio.h>
#include <stdlib.h>
// A structure to represent an adjacency list node
struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency list
struct AdjList{
    struct AdjListNode* head;
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode*  newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    struct AdjListNode* newNode2 = newAdjListNode(src);
    newNode2->next = graph->array[dest].head;
    graph->array[dest].head = newNode2;
}

 
// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int v,i,V,E,x,y;
    scanf("%d %d",&V,&E);
    //scanf("%d",&E);
    struct Graph* graph = createGraph(V);
    for(i=0;i<E;i++){
    scanf("%d %d",&x,&y);    
    addEdge(graph,x,y);
    }
 
    // print the adjacency list representation of the above graph
    //printGraph(graph);
    
    int s;
    scanf("%d",&s);
    while(s!=-1){
        
        struct AdjListNode* temp = graph->array[s].head;
        while (temp)
        {
            printf("%d ",temp->dest);
            temp =temp->next;
        }
        printf("\n");
        
        scanf("%d",&s);
    }
    
    
    
 
    return 0;
}




/*
#include <stdio.h>
#include <ue101.h>
void insertvertex(int u);
struct vertex* findvertex(int u);
void createedge(int u,int v);
void query(int u);

struct vertex
{
    int data;
    struct vertex* nextvertex;
    struct edge* firstedge;
}*start=NULL;
struct edge
{
    struct edge* nextedge;
    struct vertex* destvertex;
};
int main()
{
    int m,n,u,v,i,d;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        insertvertex(u);
        insertvertex(v);
        createedge(u,v);
        createedge(v,u);
    }
    scanf("%d",&d);
    while(d!=-1)
    {
        if(d>=n)
        printf("none\n");
        else
        query(d);
        scanf("%d",&d);
    }// Your code goes here

//printf("%d",start->data);
    return 0;
}
void insertvertex(int u)
{
    int c=0;
    struct vertex  *temp,*ptr;
    temp=(struct vertex*)malloc(sizeof(struct vertex));
    
    if(start==NULL)
    {
        temp->data=u;
        temp->nextvertex=NULL;
        temp->firstedge=NULL;
        start=temp;
        return;
    }
    ptr=start;
    while(ptr->nextvertex!=NULL)
    {
        if(ptr->data==u)
        c++;
        ptr=ptr->nextvertex;
    }
    if(c==0)
    {
    ptr->nextvertex=temp;
    temp->data=u;
    temp->nextvertex=NULL;
    temp->firstedge=NULL;
    }
        
}
struct vertex* findvertex(int u)
{
    struct vertex* ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data==u)
        return ptr;
        ptr=ptr->nextvertex;
    }
}
void createedge(int u,int v)
{
    struct edge *ptr,*temp;
    struct vertex *sloc,*dloc;
    sloc=findvertex(u);
    dloc=findvertex(v);
    temp=(struct edge*)malloc(sizeof(struct edge));
    temp->destvertex=dloc;
    temp->nextedge=NULL;
    ptr=sloc->firstedge;
    if(ptr==NULL)
    {
        sloc->firstedge=temp;
        return;
    }
    
    while(ptr->nextedge!=NULL)
    {
        ptr=ptr->nextedge;
    }
    ptr->nextedge=temp;
}

void query(int u)
{
    struct vertex* ptr;
    struct edge* e;
    ptr=start;
    int c=0,i=0,j,t;
    int *a;
    while(ptr!=NULL)
    {
        if(ptr->data==u)
        {
            e=ptr->firstedge;
            if(e==NULL)
            {
                printf("none\n");
                return;
            }
            while(e!=NULL)
            {
                c++;
                e=e->nextedge;
            }
            e=ptr->firstedge;
            a=(int*)malloc(sizeof(int)*c);
            while(e!=NULL)
            {
                a[i]=e->destvertex->data;
                e=e->nextedge;
                i++;
            }
            //printf("%d\n",a[1]);
            for(i=0;i<c;i++)
            {
                for(j=0;j<c-i-1;j++)
                {
                    if(a[j]>a[j+1])
                    {
                       t=a[j];
                       a[j]=a[j+1];
                       a[j+1]=t;
                    }
                }
            }
            for(i=0;i<c;i++)
            {
                printf("%d ",a[i]);
            }
            
            printf("\n");
            return;
        }
        ptr=ptr->nextvertex;
        c=0;
    }
    if(ptr==NULL)
    printf("none\n");
}
*/

