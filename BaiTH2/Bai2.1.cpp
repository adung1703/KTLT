//Nguyen Huu Dung - 20215545
/* Bài 2.1.  Viet ham tinh do dai canh huyen cua 
tam giac theo do hai canh goc vuong.
*/
#include <stdio.h>
#include <math.h>
float get_hypotenuse(float x, float y) {
//*****************
//# Nguyen Huu Dung - 20215545 #
return sqrt(x*x+y*y); //Tinh canh huyen
//*****************
}
int main(){
float x, y;
scanf("%f%f", &x, &y);
float z = get_hypotenuse(x, y);
printf("z = %.2f\n", z);
return 0;
} //Nguyen Huu Dung - 20215545
