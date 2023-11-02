//Nguyen Huu Dung - 20215545
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
int val1, val2;
cin >> val1 >> val2;
vector< vector<int> > a = { //Tao Vector chua Vector trong phan tu
{1, 3, 7},
{2, 3, 4, val1},
{9, 8, 15},
{10, val2},
};
//# sap xep cac vector trong a theo tong cac phan tu giam dan
/*Nguyen Huu Dung - 20215545*/
for (int i=0; i<(int)a.size()-1; i++ ) {
    for (int j=i; j<(int)a.size(); j++) 
        if (accumulate(a[i].begin(), a[i].end(), 0) < accumulate(a[j].begin(), a[j].end(), 0)) {
            vector <int> tmp = a[i]; 
            a[i] = a[j];
            a[j] = tmp;
        } /*Neu tong cua Vector phia truoc ma 
        be hon tong cua Vector phia sau thi hoan doi cho nhau.
        accumulate (vt.begin(),vt.end(),0): tinh tong Vector*/
}
for (const auto &v : a) { //duyet tung vector trong a
    for (int it : v) { //duyet tung phan tu trong vector
        cout << it << ' ';
    }
    cout << endl;
}
return 0;
}//Nguyen Huu Dung - 20215545

