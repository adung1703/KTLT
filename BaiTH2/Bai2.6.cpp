//Nguyen Huu Dung - 20215545
#include <stdio.h>
void print(int n) {
    printf("n=%d\n", n); //Ham in ra n
}
int mul3plus1(int n) {
    return n * 3 + 1; //Ham tra ve 3n+1
}
int div2(int n) { //Ham tra ve n/2
    return n / 2;
}
// khai bao cac tham so cho cac con tro ham odd, even va output
void simulate(int n, int (*odd) (int n), int (*even) (int n), void (*output) (int n)) {
    (*output)(n);
    if (n == 1) return; //Neu n=1 thi in thoat ham
    if (n % 2 == 0) { //Neu n chan 
        n = (*even)(n);
    } else {
        n = (*odd)(n); //Neu n le 
        }
    simulate(n, odd, even, output); //Tiep tuc de quy
}
int main() {
int (*odd)(int) = mul3plus1; //Gan con tro cho ham tuong ung
int (*even)(int) = div2; 
/*Nguyen Huu Dung - 20215545*/
int n;
scanf("%d", &n);
simulate(n, odd, even, print);
return 0;
} //Nguyen Huu Dung - 20215545

