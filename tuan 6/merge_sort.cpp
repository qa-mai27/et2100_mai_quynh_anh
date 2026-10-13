#include <stdio.h>
void in(int A[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void gop(int A[], int a, int mid, int b, int n){
    int m=b-a+1;
    int B[m];
    int i=a;      
    int j=mid+1; 
    int k=0;  
    while (i<=mid && j<=b){
        if (A[i]<=A[j]) {
            B[k]=A[i];
            i++;
        } 
        else {
            B[k]=A[j];
            j=j+1;
        }
        k=k+1;
    }
    while (i <= mid) {
        B[k]=A[i];
        i++;
        k++;
    }
    while (j<=b) {
        B[k]=A[j];
        j++;
        k++;
    }
    for (int p=0; p<m; p=p+1) {
        A[a+p]=B[p];
    }
    in(A,n);}

void sort(int A[], int a, int b, int n) {
    if (a>=b){ 
    return; 
    }
    int mid=(a+b)/2;
    sort(A,a,mid,n);     
    sort(A,mid+1,b,n); 
    gop(A,a,mid,b,n); 
}

int main() {
    int n;
    scanf("%d", &n) ;
    int A[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A,0,n-1,n);
    return 0;
}