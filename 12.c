#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int tnum(int n) {
    return (n * n + n) / 2;
}


int main (int argc, char const *argv[])
{
    int index = 1;
    int t;
    int c;
    while (1) {
        t = tnum(index);
        // printf("t: %d", t);
        c = 0;
        
        int i;
        for(i = 1; i < sqrt(t); i++)
        {
            if(t % i == 0)
            {
                c += 2;
            }
        }
        
        index += 1;
        
        if(c > 1000)
        {
            printf("index: %d, t: %d, c: %d", index, t, c);
            break;
        }

    }
    
    return 0;
}