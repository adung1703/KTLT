// Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
//  bool found = false; 
	
    while(n--){ //Cac phep luu ket qua phai nam trong vong lap
        int a;
        cin >> a;
        string found = "No"; //Dung bien string luu truc tiep ket qua
        
	    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) //a % 400 ==0
	    found = "Yes";
//      found = true;
		cout << found << endl;
    }
//  if (found) cout << "Yes";
//  else cout << "No";
}// Nguyen Huu Dung - 20215545
