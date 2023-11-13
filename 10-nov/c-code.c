/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* restoreArray(int** adjacentPairs, int adjacentPairsSize, int* adjacentPairsColSize, int* returnSize) {
        const int range = 100000;
    const int n = range - (-range) + 5;

    int* indegree = (int*)malloc(sizeof(int) * n);
    memset(indegree, 0, sizeof(int) * n);

    int (*graph)[2] = (int(*)[2])malloc(sizeof(int) * n * 2);
    memset(graph, n, sizeof(int) * n * 2);

    for (int i = 0; i < adjacentPairsSize; i++) {
        int u = adjacentPairs[i][0] + range;
        int v = adjacentPairs[i][1] + range;
        graph[u][indegree[u]] = v;
        graph[v][indegree[v]] = u;
        indegree[u]++;
        indegree[v]++;
    }

    int* nums = (int*)malloc(sizeof(int) * n);
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 1) {
            nums[index++] = i - range;
            break;
        }
    }

    for (int i = 0; i < adjacentPairsSize; i++) {
        int curr = nums[index - 1] + range;
        indegree[curr] = 0;

        for (int j = 0; j < 2; j++) {
            int neighbour = graph[curr][j];
            if (neighbour < n && indegree[neighbour]) {
                nums[index++] = neighbour - range;
            }
        }
    }

    free(indegree);
    free(graph);

    *returnSize = index;
    return nums;
}