#include<stdio.h>
//quy uoc thu tu nguon-dich-phu la A-B-C, su dung mang dai dien cho cot
//gan trong so cho cac dia tang dan tu tren xuong, cot o co dia thi coi nhu chua dia =0
//mac dinh A[0]=B[0]=C[0]
int findtop(int A[], int n){
    int i = 0;
    while (i < n && A[i + 1] <= n) {
        i++;
    }
    return i;
}

int check(int B[], int n){
    for (int i = 1; i <= n; i++) {
        if (B[i] > n) {
            return 0;
        }
    }
    return 1;
}

void swap(int X[], int Y[], int n, char tenx, char teny){
    int a = findtop(X, n);
    int b = findtop(Y, n);
    int dia;
    int dcNguon;
    int dcDich;
    int *nguon;
    int *dich;
    char tenNguon;
    char tenDich;
     if (a == 0) {
        nguon = Y;
        dich = X;
        dcNguon = b;
        dcDich = a;
        dia = Y[b];
        tenNguon = teny;
        tenDich = tenx;
    }
    else if (b == 0) {
        nguon = X;
        dich = Y;
        dcNguon = a;
        dcDich = b;
        dia = X[a];
        tenNguon = tenx;
        tenDich = teny;
    }
    else if (X[a] < Y[b]) {
        nguon = X;
        dich = Y;
        dcNguon = a;
        dcDich = b;
        dia = X[a];
        tenNguon = tenx;
        tenDich = teny;
    }
    else {
        nguon = Y;
        dich = X;
        dcNguon = b;
        dcDich = a;
        dia = Y[b];
        tenNguon = teny;
        tenDich = tenx;
    }
    printf("Chuyen dia thu %d tu %c sang %c\n",
           dia, tenNguon, tenDich);
    nguon[dcNguon] = n + 1;
    dich[dcDich + 1] = dia;
}

void chuyenle(int A[], int B[], int C[], int n){
    // le theo quy luan AB-AC-BC
    while (check(B, n) == 0) {
        swap(A, B, n, 'A', 'B');
        if (check(B, n) == 1) {
            break;
        }
        swap(A, C, n, 'A', 'C');
        if (check(B, n) == 1) {
            break;
        }
        swap(B, C, n, 'B', 'C');
        if (check(B, n) == 1) {
            break;
        }
    }
}

void chuyenchan(int A[], int B[], int C[], int n){
    // chan theo quy luan AC-AB-BC
    while (check(B, n) == 0) {
        swap(A, C, n, 'A', 'C');
        if (check(B, n) == 1) {
            break;
        }
        swap(A, B, n, 'A', 'B');
        if (check(B, n) == 1) {
            break;
        }
        swap(B, C, n, 'B', 'C');
        if (check(B, n) == 1) {
            break;
        }
    }
}

int main(){
    int n;
    printf("so luong dia\n");
    scanf("%d", &n);
    if (n < 1) {
        printf("So luong dia phai lon hon 0\n");
        return 0;
    }
    int A[n + 5], B[n + 5], C[n + 5];//khai bao du ra cho chac khi dung
    A[0] = B[0] = C[0] = 0;
    for (int i = 1; i <= n + 1; i++) {//n+1 bao hieu vi tri trong
    A[i] = n + 1;
    B[i] = n + 1;
    C[i] = n + 1;
}
    for (int i = 1; i <= n; i++) {
        A[i] = n - i + 1;
    }
    if (n % 2 == 0) {
        chuyenchan(A, B, C, n);
    }
    else {
        chuyenle(A, B, C, n);
    }
    return 0;
}