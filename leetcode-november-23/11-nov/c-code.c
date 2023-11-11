


// Runtime 166 ms Beats 100% Memory 15.5 MB Beats 100%
typedef struct {
    int numNodes;  // number of vertices
    int numEdges;  // number of edges
    int matrix[100][100];  // adjacency matrix
    int table[100][100];   // shortest path table
} Graph;

inline long long int min(long long int a, long long int b) {
    return (a < b) ? a : b;
}
void graphAddEdge(Graph* obj, int* edge, int edgeSize) {
    const int numNodes = obj->numNodes;
    const int u = edge[0], v = edge[1], weight = edge[2];

    obj->matrix[u][v] = weight;  // update the adjacency matrix
    obj->numEdges++;             // update the number of edges

    if (weight >= obj->table[u][v]) {
        return;  // no need to update the paths
    }
    // update all paths that went through the edge
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            obj->table[i][j] = min((long long int)obj->table[i][j], 
                                   (long long int)obj->table[i][u] + weight + obj->table[v][j]);
        }
    }
}
Graph* graphCreate(int numNodes, int** edges, int edgesSize, int* edgesColSize) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) return NULL;

    graph->numNodes = numNodes; 
    graph->numEdges = 0; 

    // initialize the adjacency matrix 
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            if (i == j) {
                graph->matrix[i][j] = 0; // since there are no repeated edges nor self-loops
            }
            else graph->matrix[i][j] = INT_MAX;  // indicates no path between i and j
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        graphAddEdge(graph, edges[i], edgesColSize[i]);
    }
    // initialize the shortest path table using the adjacency matrix
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->table[i][j] = graph->matrix[i][j];
        }
    }

    // Floyd-Warshall algorithm

    // Time complexity: O(n^3)
    // Space complexity: O(n^2)

    for (int k = 0; k < numNodes; k++) { 
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (i == k || j == k) continue;
                graph->table[i][j] = min((long long int)graph->table[i][j], 
                                         (long long int)graph->table[i][k] + graph->table[k][j]);
            }
        }
    }
    return graph;
}
int graphShortestPath(Graph* obj, int node1, int node2) {
    if (obj->table[node1][node2] == INT_MAX) {
        return -1;  // no such edge exists, return -1
    }
    return obj->table[node1][node2]; // return the shortest path from the table
}
void graphFree(Graph* obj) {
    free(obj);
}

/**
 * Your Graph struct will be instantiated and called as such:
 * Graph* obj = graphCreate(n, edges, edgesSize, edgesColSize);
 * graphAddEdge(obj, edge, edgeSize);
 
 * int param_2 = graphShortestPath(obj, node1, node2);
 
 * graphFree(obj);
*/