//Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;

inline void print(const vector<int>& v) { //Ham in ra Vector
    for (int i : v) {
        cout << i;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t; //t la so test case
    int n[t], h[t]; 
    for (int i=0; i<t; i++) {
    	cin >> n[i] >> h[i];
	}
	for (int i=0; i<t; i++) { //Voi moi test case, ta co bo input n[i], h[i]
    	vector<int> v(n[i]); //tao ra mot vector chieu dai n
        for (int j = 0; j < n[i]; ++j) { 
            v[j] = j < h[i] ? 1 : 0; //Tao mot thu tu ban dau voi h chu so 1 va n-h chu so 0
        }
        vector<int> v_end(n[i]);
        v_end = v; //Danh dau so lon nhat
        do {
            next_permutation(v.begin(), v.end()); //tao cac hoan vi
            print(v); //in ra
        } while (v != v_end); //Cho toi khi in ra chuoi lon nhat
        cout << endl;
	}
    return 0;
} //Nguyen Huu Dung - 20215545
