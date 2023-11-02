//Nguyen Huu Dung - 20215545
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
using namespace std;
struct Complex {
double real;
double imag;
};
Complex operator + (Complex a, Complex b) {
//***************** Tinh tong hai so phuc
//# Nguyen Huu Dung - 20215545 #
Complex tmp;
tmp.real = a.real + b.real;
tmp.imag = a.imag + b.imag;
//*****************
return tmp;
}
Complex operator - (Complex a, Complex b) {
//***************** Tinh hieu hai so phuc
//# Nguyen Huu Dung - 20215545 #
Complex tmp;
tmp.real = a.real - b.real;
tmp.imag = a.imag - b.imag;
return tmp;
//*****************
}
Complex operator * (Complex a, Complex b) {
//***************** Tinh tich hai so phuc
//# Nguyen Huu Dung - 20215545 #
Complex tmp;
tmp.real = a.real*b.real - a.imag*b.imag;
tmp.imag = a.real*b.imag + a.imag*b.real; 
return tmp;
//*****************
}
Complex operator / (Complex a, Complex b) {
//***************** Tinh thuong hai so phuc
//# Nguyen Huu Dung - 20215545 #
Complex tmp;
tmp.real = (a.real*b.real + a.imag*b.imag) / (b.real*b.real + b.imag*b.imag);
tmp.imag = (a.imag*b.real - a.real*b.imag) / (b.real*b.real + b.imag*b.imag);
return tmp;
//*****************
}
ostream& operator << (ostream& out, const Complex &a) {
out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
return out;
}
int main() {
double real_a, real_b, img_a, img_b;
cin >> real_a >> img_a;
cin >> real_b >> img_b;
Complex a{real_a, img_a};
Complex b{real_b, img_b};
cout << a << " + " << b << " = " << a + b << endl;
cout << a << " - " << b << " = " << a - b << endl;
cout << a << " * " << b << " = " << a * b << endl;
cout << a << " / " << b << " = " << a / b << endl;
return 0;
}//Nguyen Huu Dung - 20215545

