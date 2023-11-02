//Nguyen Huu Dung - 20215545
/*
Bai 1.3. Viet chuong trinh yeu cau nhap gia tri cho 
3 bien so nguyen x, y, z kieu int. Sau do su dung duy 
nhat mot con tro de cong gia tri cua moi bien them 100.
*/
#include <stdio.h>
int main() {
    int x, y, z;
    int *ptr;
    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    //*****************
    //YOUR CODE HERE - Nguyen Huu Dung - 20215545
    ptr=&x; //Gan dia chi cua x cho con tro ptr
    *ptr+=100; //Tang gia tri bien ma con tro tro toi them 100
    ptr=&y; //Gan dia chi cua y cho con tro ptr
    *ptr+=100; //Tang gia tri bien ma con tro tro toi them 100
    ptr=&z; //Gan dia chi cua x cho con tro ptr
    *ptr+=100; //Tang gia tri bien ma con tro tro toi them 100
    //*****************
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    return 0;
}   
//Nguyen Huu Dung - 2021554

