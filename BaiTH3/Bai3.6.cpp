//Nguyen Huu Dung - 20215545
#include <iostream>
using namespace std;
int gcd(int a, int b){ //Tim uoc chung lon nhat bang de quy
	if (b == 0) return a;
	return gcd(b, a % b);
}
int gcd2(int a, int b) {
	//# Khu de quy
	/*Nguyen Huu Dung - 20215545*/
	for (int i=a; i>0; i--) { //Do tu a den 1 de tim uoc chung lon nhat
	    if (a%i == 0 && b%i == 0) return i; //Tra ve uoc chung lon nhat
	}
	return 1; 
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl << gcd2(a, b);
	return 0;
}//Nguyen Huu Dung - 20215545
