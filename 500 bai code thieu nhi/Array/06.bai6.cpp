//Find the maximum product of two integers in an array
#include<stdio.h>
void sort(int A[], int n){ //sap xep chen
    for(int i= 1; i<n; i++){
        int x=A[i];
        int j=i-1;
        while(j>=0 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = x;
    }
}
int main(){
    int n; 
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    sort (A,n);
    if(A[0]*A[1]>A[n-1]*A[n-2]){
        printf("(%d,%d)",A[0],A[1]);
    }
        sort (A,n);
    if(A[0]*A[1]<A[n-2]*A[n-1]){
        printf("(%d,%d)",A[n-1],A[n]);
    }
        sort (A,n);
    if((A[0]*A[1])==(A[n-2]*A[n-1])){
        printf("(%d,%d) or (%d,%d)",A[0],A[1],A[n-2],A[n-1]);
    }
    return 0;
}
