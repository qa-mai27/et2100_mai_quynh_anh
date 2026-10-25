//Given an unlimited supply of coins of given denominations, find the total number 
//of distinct ways to get the desired change
#include<stdio.h>
int count(int A[], int n, int target){ // A la mang menh gia tien, X la so cach tao ra cac menh gia
    int X[100]={0};
    X[0]=1;
    for(int i=0; i<n; i++){
        for(int j=A[i];j<target+1;j++){
            X[j]=X[j]+X[j-A[i]];
        }
    }
    return X[target];
}
int main(){
    int n; 
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    int target;
    scanf("%d", &target);
    printf ("The total number of ways is %d", count(A,n,target));
    return 0;
}
