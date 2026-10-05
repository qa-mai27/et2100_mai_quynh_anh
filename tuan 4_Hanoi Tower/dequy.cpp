// thu tu: nguon-phu-dich
#include <stdio.h>
void sapxep(int n, char nguon, char phu, char dich) {
    if (n == 1) {
        printf("Chuyen dia 1 tu cot %c sang cot %c\n", nguon, dich);
        return; 
    }
    sapxep(n-1, nguon, dich, phu);//chuyen n-1 dia ve phu
    printf("Chuyen dia %d tu cot %c sang cot %c\n", n, nguon, dich);// chuyen dia thu n sang dich
    sapxep(n - 1, phu, nguon, dich);//chuyen n-1 dia tu phu ve dich
}

int main() {
    int n;
    scanf("%d", &n); 
    sapxep(n, 'A', 'C', 'B');
    return 0;
}