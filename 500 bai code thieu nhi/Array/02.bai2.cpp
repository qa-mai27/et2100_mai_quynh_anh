// xuat mang con co sum=0
#include <stdio.h>
void in (int A[],int a,int b){ //dau vao la chi so phan tu dau, cuoi cua mang A thoa man
    printf("{");
    for (int i=a; i<b; i++){
        printf("%d,",A[i]);
    }
    printf("%d }\n",A[b]);
}
void find(int A[], int n){ //dau vao mang A va so luong phan tu cua A
    int sum,c=0; //c la bien dem
    for (int i=0; i<n; i++){
        sum=A[i];
        if(A[i]==0){
            printf("{%d}\n",A[i]);
            c+=1;
        }
        for (int j=i+1; j<n; j++){
            sum=sum+A[j];
            if(sum==0){
                c+=1;
                in(A,i,j);
            }

        }
    }
    if(c==0){
        printf("Subarray with zero-sum doesn't exist");
    }
}
int main(){
    int n; //khai bao so phan tu cua mang A
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    find(A,n);
    return 0;
}