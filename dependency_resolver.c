#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node* adjList[MAX];
} Graph;

int visited[MAX];
int stack[MAX];
int top = -1;

Node* createNode(int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* node = createNode(dest);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;
}

int dfs(Graph* graph, int v) {
    visited[v] = 1;
    Node* temp = graph->adjList[v];
    while (temp) {
        int adj = temp->vertex;
        if (visited[adj] == 1)
            return 1;
        if (visited[adj] == 0) {
            if (dfs(graph, adj))
                return 1;
        }
        temp = temp->next;
    }
    visited[v] = 2;
    stack[++top] = v;
    return 0;
}

void topologicalSort(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        if (visited[i] == 0) {
            if (dfs(graph, i)) {
                printf("Cycle detected\n");
                return;
            }
        }
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 1);
    addEdge(graph, 5, 0);

    topologicalSort(graph);

    return 0;
}
