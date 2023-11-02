/*
Bai 1.4. Viet ham countEven(int*, int) nhan mot mang so nguyen va 
kich thuoc cua mang, tra ve so luong so chan trong mang???
*/
// Nguyen Huu Dung - 20215545
#include<iostream>
using namespace std;
int counteven(int* arr, int size){ //arr tro toi mang
int count = 0; //Khoi tao bien dem 
//*****************
//# YOUR CODE HERE - Nguyen Huu Dung - 20215545#
for(int i=0; i<size; i++){ //Duyet tung phan tu
    if (arr[i]%2 == 0) count++; //Neu phan tu la chan thi tang bien dem
}
//*****************
return count;
}
int main(){
	int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
	cout << counteven(arr, 8);
}
// Nguyen Huu Dung - 20215545
