//Nguyen Huu Dung - 20215545
#include <iostream>
using namespace std;
//# viet ham arr_sum
/*Nguyen Huu Dung - 20215545*/
template <typename T> //Khai quat hoa ham
T arr_sum (T *a, int m, T *b, int n){ 
    T tmp=0;
    for (int i=0; i<m; i++)    tmp+= *(a+i); //Cong tong day thu nhat
    for (int i=0; i<n; i++)    tmp+= *(b+i); //Cong tong day thu hai
    return tmp; //Tra ve tong 2 day
}
int main() {
int val;
cin >> val; //Nhap vao a[3]
{
int a[] = {3, 2, 0, val};int b[] = {5, 6, 1, 2, 7};
cout << arr_sum(a, 4, b, 5) << endl;
} {
double a[] = {3.0, 2, 0, val * 1.0};
double b[] = {5, 6.1, 1, 2.3, 7};
cout << arr_sum(a, 4, b, 5) << endl;
}
return 0;
}//Nguyen Huu Dung - 20215545

