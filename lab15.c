#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, nmax, test, i, j, i1, j1;
    long long int k, kv, kn, b;
    scanf("%d", &test);
    scanf("%d", &nmax);
    k = 0; kv = 0; kn = 0;
    b = 0;
    while ((test != 0) && (nmax != 0) && (test != ' ') && (nmax != ' ')) {
        scanf("%d", &n);
        if ((n <= nmax) && (n != 0)) {
            long long int a[n][n];
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    scanf("%lli", &a[i][j]);
                }
            }
            n = n - 1;
            for (i = 1; i < n; i++) {
                j = n - i;
                i1 = i;
                j1 = j;
                b = a[i1][j1];
                do {
                    kv = kv + a[i1 - 1][j1 - 1];
                    j1 = j1 - 1;
                    i1 = i1 - 1;
                } while ((i1 != 0) && (j1 != 0));
                i1 = i;
                j1 = j;
                do {
                    kn = kn + a[i1 + 1][j1 + 1];
                    j1 = j1 + 1;
                    i1 = i1 + 1;
                } while ((j1 != n) && (i1 != n));
                k = kv + kn + b;
                a[i][j] = k;
                k = 0;
                kv = 0;
                kn = 0;
                b = 0;
            }
            n = n + 1;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    printf("%*lli", 10, a[i][j]);
                }
                printf("\n");
            }
        }
        test = test - 1;
    }
    return 0;
}
