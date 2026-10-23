// find the duplicate element in a limited range array
#include<stdio.h>
void sort(int A[], int n){ //sap xep chen
    for(int i= 1; i<n; i++){
        int x=A[i];
        int j=i-1;
        while(j>=0 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j + 1] = x;
    }
}
void duplicate(int A[], int n){
    for (int i=0; i<n-1; i++) {
        if (A[i]==A[i+1]) {
            printf("The duplicate element is %d\n", A[i]);
            while ((i<n-1) && (A[i]==A[i + 1])) {
                i++;
            }
        }
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
    duplicate(A,n);
    return 0;
}
