#include<stdio.h>
void sapxep(int A[], int a, int n){
    int c,min=A[a];
    for (int i=a; i<n; i++){
        if(min>A[i]){
            min=A[i];
            c=i;
        }
    }
    A[c]=A[a];
    A[a]=min;
}
void in (int A[], int n){
    for (int i=0; i<n; i++){
        printf ("%d ", A[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    for(int j=0; j<n; j++){
        sapxep(A,j,n);
        in (A,n);
        printf("\n");
        }
    return 0;
    }
