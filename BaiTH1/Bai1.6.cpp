/*Bai 1.6. Viet ham dao nguoc mot mang cac so 
nguyen theo hai cach: dung chi so va dung con tro.
Vi du mang dau vao la [9, -1, 4, 5, 7] thi 
ket qua la [7, 5, 4, -1, 9].
*/
//Nguyen Huu Dung - 20215545
#include <iostream>
using namespace std;
void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp; 
    //*****************
    //# YOUR CODE HERE - Nguyen Huu Dung - 20215545#
    while (l<r) { //Khi a[l] van con nam truoc a[r]
        tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp; //Dao vi tri a[l] voi a[r]
        l++; //Tang bien l
        r--; //Giam bien r
    }
    //*****************
}
void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    //*****************
    //# YOUR CODE HERE - Nguyen Huu Dung - 20215545#
    while (l<r) { //Khi a[l] van con nam truoc a[r]
        tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp; //Dao vi tri a[l] voi a[r]
        l++; //Tang bien l
        r--; //Giam bien r
    }
    //*****************
}
int main(){
	int arr[] = {9, 3, 5, 6, 2, 5};
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++) cout << arr[i] << " ";
	printf("\n");
	int arr2[] = {4, -1, 5, 9};
	ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
}
//Nguyen Huu Dung - 20215545

