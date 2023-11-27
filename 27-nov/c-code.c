#define MOD 1000000007
int knightDialer(int n) {
    unsigned int sum = 0;
    unsigned int* prevMove = (unsigned int*) malloc(10 * sizeof(int));
    unsigned int* curMove = (unsigned int*) malloc(10 * sizeof(int));
    for(int i = 0; i < 10; i++)
    {
        prevMove[i] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        curMove[0] = (prevMove[4] + prevMove[6]) % MOD;
        curMove[1] = (prevMove[6] + prevMove[8]) % MOD;
        curMove[2] = (prevMove[7] + prevMove[9]) % MOD;
        curMove[3] = (prevMove[4] + prevMove[8]) % MOD;
        curMove[4] = (prevMove[0] + prevMove[3] + prevMove[9]) % MOD;
        curMove[5] = 0;
        curMove[6] = (prevMove[0] + prevMove[1] + prevMove[7]) % MOD;
        curMove[7] = (prevMove[2] + prevMove[6]) % MOD;
        curMove[8] = (prevMove[1] + prevMove[3]) % MOD;
        curMove[9] = (prevMove[2] + prevMove[4]) % MOD;
        
        unsigned int* temp = prevMove;
        prevMove = curMove;
        curMove = temp;
    }

    for(int i = 0; i < 10; i++)
    {
        sum = (sum + prevMove[i]) % MOD;
    }
    return sum;
}