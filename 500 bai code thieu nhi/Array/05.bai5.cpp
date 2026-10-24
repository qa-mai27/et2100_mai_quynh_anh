//sort binary array
#include<stdio.h>
void sort(int A[], int n){
    for(int i=0; i<n; i++){
        if (A[i]>A[i+1]){
            int c=A[i];
            A[i]=A[i+1];
            A[i+1]=c;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    sort(A,n);
    for (int j=0; j<n; j++){
        printf ("%d ",A[j]);
    }
    return 0;

}