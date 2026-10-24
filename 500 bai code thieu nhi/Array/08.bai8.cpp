//Find the frequency of each element in a sorted array containing duplicates
#include<stdio.h>
void find(int A[], int n){
    int c=1; //bien dem
    for (int i=0; i<n; i++){
        if(A[i]==A[i+1]){
            c++;
        }
        else{
        printf("%d:%d ", A[i], c);
        c=1;
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