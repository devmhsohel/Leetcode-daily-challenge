int numberOfWays(char* corridor) {    
    int j = 0;
    long ans = 1, mod = 1000000007, s = 0, p = 0;;
    while(corridor[j]){
        if(corridor[j] == 'S') {
            s++;
        }
        if(s==2 && corridor[j] == 'P')
            p++;
        if(s == 3)
        {
            ans*=(p+1);
            ans%=mod;
            p = 0;
            s = 1;
        }
        j++;
    }
    return s < 2 ? 0 : ans;    
}