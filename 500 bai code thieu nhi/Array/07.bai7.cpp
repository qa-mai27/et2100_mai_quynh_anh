//Find the smallest missing element from a sorted array
#include<stdio.h>
void find(int A[], int n){
    for(int i=0; i<n; i++){
        if (A[i]!=i){
            printf("The smallest missing element is %d", i);
            break;
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
    find(A,n);
    return 0;
}