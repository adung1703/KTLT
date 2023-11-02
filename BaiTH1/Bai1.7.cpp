/*
Bai 1.7. Viet chuong trinh nhap vao mot mang cac 
so nguyen voi so luong cac phan tu nhap tu ban phim.
Sau do sap xep mang theo thu tu tang dan. Hien thi
danh sach mang truoc va sau khi sap xep.
*/
//Nguyen Huu Dung - 20215545
#include <stdio.h>
#include <cstdlib> //Thu vien de cap phat bo nho dong
int *a; 
int n, tmp; 
int main(){
printf("Enter the number of elements: ");
scanf("%d", &n);
//#Allocate memory
//*****************
//# YOUR CODE HERE #
a = (int*) malloc(n*sizeof(int)); //Cap phat bo nho dong cho con tro a 
//*****************
for(int i = 0; i < n; i++)
scanf("%d", a + i);
printf("The input array is: \n");
for(int i = 0; i < n; i++)
printf("%d ", *(a + i)); // *(a+i) chinh la a[i]
printf("\n");
//#Sort array
//*****************
//# YOUR CODE HERE #
for (int i=0; i < n-1; i++)
    for (int j=i+1; j<n; j++)
        if (*(a+i) > *(a+j)) {
            tmp = *(a+i);
            *(a+i) = *(a+j);
            *(a+j) = tmp;
        }
//*****************
printf("The sorted array is: \n");
for(int i = 0; i < n; i++)
printf("%d ", *(a + i));
printf("\n");
delete [] a; //Giai phong bo nho cap phat
return 0;
}
//Nguyen Huu Dung - 20215545

