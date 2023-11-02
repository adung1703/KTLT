//Nguyen Huu Dung - 20215545
#include <stdio.h>
void rotate(int &x, int &y, int &z) {
//*****************
//# Nguyen Huu Dung - 20215545 #
int tmp = x;
x=y;
y=z;
z=tmp;
//*****************
}
int main() {
int x, y, z;
//# Nh?p 3 s? nguyên
scanf("%d %d %d", &x, &y, &z);
printf("Before: %d, %d, %d\n", x, y, z);
rotate(x, y, z);
printf("After: %d, %d, %d\n", x, y, z);
return 0;
}//Nguyen Huu Dung - 20215545

