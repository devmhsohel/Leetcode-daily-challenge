/*
 * 1727. Largest Submatrix With Rearrangements
 *
 * You are given a binary matrix matrix of size m x n, and 
 * you are allowed to rearrange the columns of the matrix in 
 * any order.
 * 
 * Return the area of the largest submatrix within matrix where 
 * every element of the submatrix is 1 after reordering the columns 
 * optimally.
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m * n <= 10^5
 * matrix[i][j] is either 0 or 1.
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmp(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {

    /*
     * Input:
     *  **matrix
     *  matrixSize
     *  *matrixColSize
     */

    int **ones = (int **)malloc(sizeof(int *) * matrixSize), ans = 0;

    for (int i = 0; i < matrixSize; i++) {
        ones[i] = (int *)malloc(sizeof(int) * matrixColSize[i]);
    }

    for (int i = 0; i < matrixColSize[0]; i++) {

        /* Find number of consecutive ones ending at each position */
        for (int j = matrixSize - 1, cnt = 0; j >=0; j--) {
            if (matrix[j][i] == 1) {
                cnt++;
            }
            else {
                cnt = 0;
            }

            ones[j][i] = cnt;
        }
    }

    for (int i = 0; i < matrixSize; i++) {

        /* Sort by consecutive ones value in descending order */
        qsort(ones[i], matrixColSize[i], sizeof(int), cmp);

        /* Compare the height and area */
        for (int j = 0, height = INT_MAX; j < matrixColSize[i]; j++) {
            height = MIN(height, ones[i][j]);
            ans = MAX(ans, height * (j + 1));
        }

        free(ones[i]);
    }

    free(ones);

    /*
     * Output:
     *  Return the area of the largest submatrix within matrix where 
     *  every element of the submatrix is 1 after reordering the columns 
     *  optimally.
     */

    return ans;
}