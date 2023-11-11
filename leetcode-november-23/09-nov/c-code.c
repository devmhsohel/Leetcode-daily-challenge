

int countHomogenous(char * s){
    long long count = 1, result = 0;
    char prev = s[0];
    long long MOD = 1000000007;
    
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == prev) {
            count++;
        } else {
            result += (count * (count + 1) / 2) % MOD;
            count = 1;
            prev = s[i];
        }
    }
    
    result += (count * (count + 1) / 2) % MOD;
    
    return result % MOD;
}