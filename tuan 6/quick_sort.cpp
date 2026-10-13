#include <stdio.h>

void swap(int *x, int *y){
    int c=*x;
    *x=*y;
    *y=c;
}

void in(int A[], int n){
    for (int i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}


void sort(int A[], int a, int b, int n) {
    if(a>=b){
        return;
    }
    int chot = A[a];
    int i = a + 1;
    int j = b;
    while (i <= j) {
        while (i <= b && A[i] < chot) {
            i++;
        }
        while (j >= a + 1 && A[j] >= chot) {
            j--;
        }
        if (i < j) {
            swap(&A[i], &A[j]);
            in(A,n);
        }
    }
        swap(&A[a],&A[j]);
        in(A, n);
    sort(A, a, j - 1, n);
    sort(A, j + 1, b, n);
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, 0, n - 1, n);
    return 0;
}