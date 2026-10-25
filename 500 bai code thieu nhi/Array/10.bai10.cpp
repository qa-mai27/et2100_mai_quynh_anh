//Decode a given sequence to construct a minimum number without repeated digits

#include <stdio.h>

void D(int num[], int a, int b) {
    while (a < b) {
        int temp=num[a];
        num[a]=num[b];
        num[b]=temp;
        a++;
        b--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char A[n];
    int num[n+1];
    for (int i=0; i<n; i++) {
        scanf(" %c", &A[i]);
    }
    for (int i=0; i<=n; i++) {
        num[i]=i+1;
    }
    int i = 0;
    while (i<n) {
        if (A[i]=='D') {
            int a=i;
            while (i<n && A[i]=='D') {
                i++;
            }
            int b = i;
            D(num,a,b);
        } else {
            i++;
        }
    }
    for (int i = 0; i <= n; i++) {
        printf("%d", num[i]);
    }
    return 0;
}
