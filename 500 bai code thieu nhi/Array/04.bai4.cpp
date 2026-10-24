//Merge two arrays by satisfying given constraints X[], Y[]
//The vacant cells in X[] is represented by 0
#include<stdio.h>
void ghep(int X[],int m,int Y[], int n){ //ghep Y vao X
    int j=0;
    for (int i=0; i<m; i++){
        if(X[i]==0){
            X[i]=Y[j];
            j++;
        }
  
}}
void sort(int X[], int m){ //sap xep chen
    for(int i= 1; i<m; i++){
        int c=X[i];
        int j=i-1;
        while(j>=0 && X[j]>c){
            X[j+1]=X[j];
            j--;
        }
        X[j+1] = c;
    }
}
int main(){
    int m; //khai bao va nhap mang X
    scanf("%d",&m);
    int X[m];
    for(int i=0; i<m; i++){
        scanf("%d",&X[i]);
    }
    int n; //khai bao va nhap mang Y
    scanf("%d",&n);
    int Y[n];
    for(int i=0; i<n; i++){
        scanf("%d",&Y[i]);
    }
    ghep(X,m,Y,n);
    sort(X,m);
    for (int k=0; k<m; k++){
        printf("%d ", X[k]);
    }
    return 0;

}