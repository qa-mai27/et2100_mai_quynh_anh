#include <stdio.h>
void find(int A[],int a,int b,int X){
    int k=(a+b)/2;
    if(A[k]>X){
        find(A,a,k,X);
    }
    if(A[k]<X){
        find(A,k,b,X);
    }
    if(A[k]==X){
        printf("X=A[%d]",k);
    }
    
}
int main(){
    int A[6]={1,2,3,4,5,6};
    int X=5;
    find(A,0,5,5);
    return 0;

}