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

int addQueue(queue *bfs_queue, int input)
{
	queue *tmp_queue = bfs_queue;
	while(tmp_queue->next != NULL)
	{
		tmp_queue = tmp_queue->next;
	}
	tmp_queue->next = (queue *)malloc(sizeof(queue));
	tmp_queue->next->node_index = input;
	tmp_queue->next->next = NULL;
}

int bfs(node *nodes[], queue *bfs_queue, int start)
{
	int destination;
	queue *tmp_queue = NULL;
	while(bfs_queue != NULL)
	{
		while(nodes[start]->node_queue != NULL)
		{
			addQueue(bfs_queue, nodes[start]->node_queue->node_index);
			nodes[start]->node_queue = nodes[start]->node_queue->next;
		}

		tmp_queue = bfs_queue;

		while(tmp_queue != NULL)
		{
			destination = tmp_queue->node_index;
			if(!nodes[destination]->visit_flag)
			{
				printf("%d ", destination);
				nodes[destination]->visit_flag = 1;
				bfs(nodes, bfs_queue, destination);
			}
			bfs_queue = bfs_queue->next;
			tmp_queue = tmp_queue->next;
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
	//init bfs_queue
	queue *bfs_queue = (queue *)malloc(sizeof(queue));
	bfs_queue->node_index = 1;
	bfs_queue->next = NULL;
	//bfs
	bfs(nodes, bfs_queue, 1);
	return 0;
}
