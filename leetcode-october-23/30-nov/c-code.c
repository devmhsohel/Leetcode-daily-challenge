/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    int count1 = countBits(num1);
    int count2 = countBits(num2);
    if (count1 != count2) {
        return count1 - count2;
    }
    return num1 - num2;
}
int* sortByBits(int* arr, int arrSize, int* returnSize){
    qsort(arr, arrSize, sizeof(int), compare);
    *returnSize = arrSize;
    return arr;
}