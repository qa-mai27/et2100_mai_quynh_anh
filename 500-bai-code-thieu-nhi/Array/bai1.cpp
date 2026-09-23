#include <stdio.h>
int find (int A[],int n, int B[], int t){
    int c=0;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (A[i]+A[j]==t){
                B[c]=A[i];
                B[c+1]=A[j];
                c=c+2;                
            }
        }
    }
    return c;
}

int main(){
    int n,t,x; //số số hạng, target, số cặp x 2
    scanf("%d",&n);
    int A[n]; //A: mang so
    int B[n]; //B: mang luu so
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&t);
    x=find (A,n,B,t);
    if(x==0){
        printf("Pair not found");
    }
    if (x!=0){
    printf("Pair found (%d,%d)\n", B[0], B[1]);
    if (x>2){
        for (int j=2; j<x;j+=2){
            printf("or\n");
            printf("Pair found (%d,%d)\n", B[j], B[j+1]);
        }
    }}
    return 0;

}