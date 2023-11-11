int getWinner(int* arr, int arrSize, int k) {
    int win_count = 0;
    int winner = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] > winner) {
            winner = arr[i];
            win_count = 0;
        }
        if (++win_count == k) {
            break;
        }
    }
    return winner;
}