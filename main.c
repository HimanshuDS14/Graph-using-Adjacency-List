#include<stdio.h>


struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

//create a AdjListNode
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newnode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
} ;

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    int i;
    for(i=0;i<V;i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;



};

void addEdge(struct Graph* graph , int src , int dest)
{
    struct AdjListNode* newnode = newAdjListNode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head = newnode;


    newnode = newAdjListNode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;



}

void printGraph(struct Graph * graph)
{
    int v;
    for(v=0;v<graph->V;v++)
    {
        struct AdjListNode* temp = graph->array[v].head;
        printf("\n Adjacency List of Vertex %d\n head " , v);

        while(temp)
        {
            printf("-->%d" , temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int v=5;

    struct Graph * graph = createGraph(v);
    addEdge(graph , 0 ,1);
    addEdge(graph , 0 ,4);
    addEdge(graph , 1 ,2);
    addEdge(graph , 1 ,3);
    addEdge(graph , 1 ,4);
    addEdge(graph , 2 ,3);
    addEdge(graph , 3 ,4);

    printGraph(graph);


}















