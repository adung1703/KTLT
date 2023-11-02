// Nguyen Huu Dung - 20215545
#include <iostream>
#include <unordered_map>
using namespace std;

// Dem so xau con co so bit 1 va bit 0 bang nhau
int count(string binary) {
    int c = 0; // Bien luu ket qua
    int zeros = 0; // Dem so bit 0
    int ones = 0; // Dem so bit 1 
    unordered_map<int, int> countMap; // luu so luong xau thoa man voi kich thuoc cua no
    countMap[0] = 1;  // So luong xau con rong

    for (char ch : binary) {
        if (ch == '0') { 
            zeros++;
        } else {
            ones++;
        }

    //Dem so xau con thoa man
        int diff = zeros - ones;
        if (countMap.count(diff)) {
            c += countMap[diff]; 
        }
        countMap[diff]++;
    }
    return c;
}

int main() {
    string binary;
    cin >> binary;
    cout << count(binary) << endl;

    return 0;
} // Nguyen Huu Dung - 20215545