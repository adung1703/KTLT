//Nguyen Huu Dung - 20215545
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Ham tim dien tich lon nhat trong luoc do
int findArea(vector<int>& h) {
    stack<int> s;
    int maxArea = 0;
    int area = 0;
    int i = 0; //cot phai nhat
    //Duyet cac cot tu trai qua phai
    while (i < h.size()) {
        //Neu ngan xep rong hoac chieu cao cot hien tai >= chieu cao cot o dinh stack
        if (s.empty() || h[i] >= h[s.top()]) {
            s.push(i); //Day vao ngan xep
            i++; 
        } else {
            int topIndex = s.top();
            s.pop();

            if (s.empty()) { //Neu stack co 1 phan tu
                area = h[topIndex] * i;
            } else {
                area = h[topIndex] * (i - s.top() - 1);
            } //Tinh dien tich

            maxArea = max(maxArea, area); //So sanh va lay gia tri max
        }
    }

    while (!s.empty()) { //Duyet stack tim dien tich lon nhat
        int topIndex = s.top();
        s.pop();

        if (s.empty()) {
            area = h[topIndex] * i;
        } else {
            area = h[topIndex] * (i - s.top() - 1);
        }
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    cout << findArea(h) << endl;

    return 0;
} //Nguyen Huu Dung - 20215545