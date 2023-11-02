//Nguyen Huu Dung - 20215545
#include <stdio.h>
int cube(int x) {
//# tra ve lap phuong cua x
    return x*x*x;
} //Nguyen Huu Dung - 20215545
//# viet ham tinh lap phuong cua mot so kieu double
double cube(double y) {
    return y*y*y;
}//Nguyen Huu Dung - 20215545
int main() {
int n;
double f;
scanf("%d %lf", &n, &f);
printf("Int: %d\n", cube(n));
printf("Double: %.2lf\n", cube(f));
return 0;
}//Nguyen Huu Dung - 20215545

