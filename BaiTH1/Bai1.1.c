// Nguyen Huu Dung - 20215545

# include <stdio.h>
int main(){
    int x, y, z; //Khai bao bien x,y,z
    int* ptr; //Khai bao con tro ptr
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z); //Nhap 3 so nguyen x,y,z
    printf("\nThe three integers are:\n");
    ptr = &x; //gan dia chi cua bien x cho con tro ptr
    printf("x = %d\n", *ptr);
    //*****************
    /*YOUR CODE HERE - Nguyen Huu Dung - 20215545*/
    ptr = &y; //gan dia chi cua bien y cho con tro ptr
    printf("y = %d\n", *ptr);
    ptr = &z; //gan dia chi cua bien z cho con tro ptr
    printf("z = %d\n", *ptr);
    //*****************
    return 0;
}
//Nguyen Huu Dung - 20215545
