#include <cstdlib>
#include <stdio.h>

/*
 * Read a number, N, from standard input and print the permutations.
 */

void print(const int *v, const int size)
{
    if (v != 0) {
        for (int i = 0; i < size; i++) {
            printf("%d", v[i]);
        }
        printf("\n");
    }
    exit(0);
} // print


void swap(int *v, const int i, const int j)
{
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
} 


void rotateLeft(int *v, const int start, const int n)
{
    int tmp = v[start];
    for (int i = start; i < n-1; i++) {
        v[i] = v[i+1];
    }
    v[n-1] = tmp;
} // rotateLeft


void permute(int *v, const int start, const int n, const int limit)
{
    static int count = 0;
    count++;
    if(count == limit)
    {
        print(v, n);
    }
    if (start < n) {
        int i, j;
        for (i = n - 2; i >= start; i--) {
            for (j = i + 1; j < n; j++) {
                swap(v, i, j);
                permute(v, i + 1, n, limit);
            } // for j
            rotateLeft(v, i, n);
        } // for i
    }
} // permute


void init(int *v, int N)
{
    for (int i = 0; i < N; i++) {
        v[i] = i;
    }
} // init


int main()
{
    int N = 10;

    if (N > 0) {
        int *v = new int[N];
        init(v, N);
        permute(v, 0, N, 1000000);
        delete [] v;
    }
    return 0;
}
