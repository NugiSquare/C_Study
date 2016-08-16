#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int node_index;
    struct queue* next;
} queue;

typedef struct node
{
    int visit_flag;
    queue* node_queue;
} node;

int addEdge(node *nodes[], int node1, int node2)
{
    queue *tmp_queue = NULL;
    if(nodes[node1]->node_queue == NULL)
    {
        nodes[node1]->node_queue = (queue *)malloc(sizeof(queue));
        nodes[node1]->node_queue->node_index = node2;
        nodes[node1]->node_queue->next = NULL;
    }
    else
    {
        tmp_queue = nodes[node1]->node_queue;
        while(tmp_queue->next != NULL)
        {
            tmp_queue = tmp_queue->next;
        }
        tmp_queue->next = (queue *)malloc(sizeof(queue));
        tmp_queue->next->node_index = node2;
        tmp_queue->next->next = NULL;
    }
    return 0;
}

int dfs(node *nodes[], int start)
{
    int destination;
    printf("%d ", start);
    nodes[start]->visit_flag = 1;
    while(1)
    {
        if(nodes[start]->node_queue == NULL)
        {
            return 0;
        }
        else
        {
            destination = nodes[start]->node_queue->node_index;
            if(nodes[destination]->visit_flag == 1)
            {
                nodes[start]->node_queue = nodes[start]->node_queue->next;
            }
            else
            {
                nodes[start]->node_queue = nodes[start]->node_queue->next;
                dfs(nodes, destination);
            }
        }
    }
    return 0;
}

int main(void)
{
    int i, node_count, edge_count, node1, node2;
    scanf("%d %d", &node_count, &edge_count);
    node *nodes[node_count+1];
    //init nodes
    for(i=1; i<=node_count; i++)
    {
        nodes[i] = (node *)malloc(sizeof(node));
        nodes[i]->visit_flag = 0;
        nodes[i]->node_queue = NULL;
    }
    //init edges
    for(i=0; i<edge_count; i++)
    {
        scanf("%d %d", &node1, &node2);
        addEdge(nodes, node1, node2);
        addEdge(nodes, node2, node1);
    }
    //dfs
    dfs(nodes, 1);
    return 0;
}
