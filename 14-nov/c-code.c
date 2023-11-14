int countPalindromicSubsequence(char *s) {
    int n = strlen(s);
    if (n < 3) {
        return 0;
    }
    int cnt = 0;
    for (int c = 0; c < 26; c++) {
        int i = 0;
        int j = n - 1;
        while (i < j && s[i] != c + 97) {
            i++;
        }
        while (i < j && s[j] != c + 97) {
            j--;
        }
        if (i == j) {
            continue;
        }
        int freq[26] = {0};
        for (int k = i + 1; k < j; k++) {
            freq[s[k] - 97]++;
        }
        for (int k = 0; k < 26; k++) {
            if (freq[k] > 0) {
                cnt++;
            }
        }
    }
    return cnt;
}