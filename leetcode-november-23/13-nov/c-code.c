char * sortVowels(char * s){
    char vowels[10] = {'A','E','I','O','U','a','e','i','o','u'};
    
    int count[10] = {0};
    for (size_t i=0 ; s[i] ; i++) {
        for (size_t j=0 ; j<10 ; j++) {
            if (s[i]==vowels[j]) {
                count[j]++;
                s[i]='*';
                break;
            }
        }
    }

    size_t j=0;
    while (j<10 && !count[j]) j++;

    if (j==10) return s;

    for (size_t i=0 ; s[i] ; i++) {
        if (s[i]=='*') {
            s[i] = vowels[j];
            count[j]--;
            while (j<10 && !count[j]) j++;

            if (j==10) return s;
        }
    }

    return s;
}