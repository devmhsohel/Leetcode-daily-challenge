/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char **result = (char **)malloc(sizeof(char *) * (2 * n));
    *returnSize = 0;
    int i = 1, j = 0;
    while (i <= n && j < targetSize) {
        result[*returnSize] = (char *)malloc(sizeof(char) * 5);
        if (i == target[j]) {
            strcpy(result[*returnSize], "Push");
            (*returnSize)++;
            j++;
        } else {
            strcpy(result[*returnSize], "Push");
            (*returnSize)++;
            result[*returnSize] = (char *)malloc(sizeof(char) * 4);
            strcpy(result[*returnSize], "Pop");
            (*returnSize)++;
        }
        i++;
    }
    return result;
}