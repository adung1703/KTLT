//Nguyen Huu Dung - 20215545
/* Viet chuong trinh in ra tat ca cac day con cua mot day cho truoc. 
*/
#include <stdio.h>
#include <cstdlib>
int main(){
int n, *a;
printf("Nguyen Huu Dung - 20215545\n");
printf("Enter size of array: ");
scanf("%d",&n);
a = (int*) malloc(n * sizeof(int)); //Cap phat bo nho dong cho mang
printf("\nThe input array is: ");
for (int i=0; i<n; i++) scanf("%d", a+i); 
for (int i=0; i<n; i++) { //i la chi so ngoai cung ben trai day con
	for (int j=i; j<n; j++) { //j la chi so ngoai cung ben phai day con
		for (int k=i; k<=j; k++) printf("%d ",*(a+k)); //in day con ra
		printf("\n");
	}
}
return 0;
}
// Nguyen Huu Dung - 20215545
