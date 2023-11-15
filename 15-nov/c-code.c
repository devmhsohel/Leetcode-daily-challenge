int compare(const void *a, const void *b) {return (*(int *)a - *(int *)b);}
int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);
    int maxElement = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > maxElement + 1) {
            maxElement = maxElement + 1;
        } else {
            maxElement = arr[i];
        }
    }
    return maxElement;
}