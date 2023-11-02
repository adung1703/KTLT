// Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;

int A = 0, B = 0, C = 0, D = 0, F = 0; 
//Dua cac bien dem so diem ra toan cuc

//Su dung ham truc tiep tang so luong diem tuong ung

void cal(double a){
	if (a < 4) F++;
    else if (4 <= a && a < 5.5) D++;
    else if (5.5 <= a && a < 7) C++;
    else if (7 <= a && a < 8.5) B++;
    else if (8.5 <= a) A++;
}

//char cal(double a){
//    if (a < 4) return 'F';
//    if (4 <= a && a < 5.5) return 'D';
//    if (5.5 <= a && a < 7) return 'C';
//    if (7 <= a && a < 8.5) return 'B';
//    if (8.5 <= a) return 'A';
//}

int main(){
    int n;
    cin >> n;
//    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
//        int a;
//Khai bao bien a sai
		double a;
        cin >> a;
        cal(a);
//        if (cal(a) == 'A') ++A;
//        if (cal(a) == 'B') ++B;
//        if (cal(a) == 'C') ++C;
//        if (cal(a) == 'D') ++D;
//        if (cal(a) == 'F') ++F; 
// Giam so lan kiem tra lai
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
} // Nguyen Huu Dung - 20215545
