#include <stdio.h>

int main() {
    int i, j, n, s[30], f[5], m, k, flag, count = 0;

    printf("Enter the size of pages: ");
    scanf("%d", &n);

    printf("Enter page reference: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    printf("Enter the size of frame: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        f[i] = -1;
        printf("%d \n", f[i]);
    }

    k = 0;
    for (i = 0; i < n; i++) {
        flag = 0; // Added semicolon here
        for (j = 0; j < m; j++) {
            if (f[j] == s[i]) {
                flag = 1; 
            }
        }
        if (flag == 0) {
            f[k] = s[i];
            k = (k + 1) % m;
            count++;
        }
    }

    printf("Total number of page faults = %d\n", count);
    return 0;
}
