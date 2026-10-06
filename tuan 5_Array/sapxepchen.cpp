#include <stdio.h>
void in (int A[], int n){
    for (int i=0; i<n; i++){
        printf ("%d ", A[i]);
    }
    printf ("\n");
}
void sapxep(int A[], int n){
    for(int i= 1; i<n; i++){
        int x=A[i];
        int j=i-1;
        while(j>=0 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j + 1] = x;
        in(A,n);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    sapxep(A, n);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}