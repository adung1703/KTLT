//Nguyen Huu Dung - 20215545
#include <iostream>
using namespace std;

int lucas(int n) {
	/*Nguyen Huu Dung - 20215545*/
	//# YOUR CODE HERE #
	if (n==0) return 2; //L_0 = 2
	else if (n==1) return 1; //L_1 = 1
	else return lucas(n-1) + lucas(n-2); //L_n = L_(n-1) + L_(n-2)
}
//Nguyen Huu Dung - 20215545

