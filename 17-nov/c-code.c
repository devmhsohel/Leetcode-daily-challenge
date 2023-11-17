char* findDifferentBinaryString(char** nums, const unsigned short n) {
    char *const r = *nums;
    for (unsigned short i = 0; i < n; i++)
        r[i] = nums[i][i] ^ 1;
    return r;
}