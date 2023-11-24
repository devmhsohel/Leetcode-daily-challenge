int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxCoins(int* piles, int pilesSize) {
    /* Sort the piles */
    qsort(piles, pilesSize, sizeof(int), cmp);

    int terms = pilesSize / 3;
    int mine = 0;

    /* Get mine coins */
    for (int i = 0, idx = pilesSize - 2; i < terms; ++i, idx -= 2) {
        mine += piles[idx];
    }

    return mine;
}