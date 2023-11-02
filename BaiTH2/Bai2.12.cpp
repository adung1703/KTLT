//Nguyen Huu Dung - 20215545
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {

    vector<pair<int, int>> list; //Chua ket qua

    while(cin) { //Khi du lieu nhap vao
        int key = INT_MIN, value = INT_MIN; //Khoi tao gia tri ban dau 
        cin >> key >> value;
        list.push_back(make_pair(key, value)); //Insert cap key, value vao vector list
    }

    // Sap xep danh sach bang ham nac danh
    sort(list.begin(), list.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) { //Neu value bang nhau
            return a.first > b.first; //So sanh key
        } 
        return a.second > b.second; //So sanh value
    });

    for (const auto& item : list) {
    	if (item.first != INT_MIN && item.second != INT_MIN) { 
    		cout << item.first << " " << item.second << endl;
		}
    }//In ra man hinh ket qua

    return 0;
} //Nguyen Huu Dung - 20215545

