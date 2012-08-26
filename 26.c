#include <stdio.h>

int main (int argc, char const *argv[])
{
    int n, i, len, maxlen, maxn; 
    maxlen = 0; 
    for(n = 2 ; n <= 1000 ; n++) { 
        int rest = 1; 
        int r0; 
        for(i = 0 ; i < n ; i++) rest = (rest * 10) % n; 
        r0 = rest; 
        len = 0; 
        do { 
            rest = (rest * 10) % n; 
            len++; 
        } while(rest != r0); 
        if (len > maxlen){ 
            maxn = n; 
            maxlen = len; 
        } 
    } 
    printf("result: %d: %d\n", maxn, maxlen);
    return 0;
}