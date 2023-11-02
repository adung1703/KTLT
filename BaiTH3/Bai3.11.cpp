//Nguyen Huu Dung - 20215545
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <climits>

using namespace std;

const int INF = INT_MAX;

//Ham hoan doi 2 phan tu
void swap(int& x, int& y) { 
    int temp = x;
    x = y;
    y = temp;
}

//Ham tinh chi phi moi lich trinh
void price(const vector<int>& a, int x, const vector<vector<int>>& graph, vector<int>& cost) {
//a la lich trinh, x chi nguoi thu x, graph la mang chi phi, cost chua chi phi nho nhat cua lich trinh
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++) {
        if (graph[a[i]][a[i + 1]] == 0) { //Neu khong the di chuyen thi chi phi bang vo cung
            sum = INF;
            break;
        }
        sum += graph[a[i]][a[i + 1]]; //Nguoc lai cong don chi phi
    }
    if (cost[x] > sum) {
        cost[x] = sum; //Ghi lai chi phi
    }
}

//Thuat toan nguoi du lich
void permute(vector<int>& a, int i, int k, int x, const vector<vector<int>>& graph, vector<int>& cost) {
//a la lich trinh, i/k la vi tri dau tien/cuoi cung co the thay doi trong lich trinh
//x chi nguoi thu x, graph la mang chi phi, cost chua chi phi nho nhat
    if (i == k) {
        price(a, x, graph, cost);
    }
    else {
        for (int j = i; j <= k; j++) { //Thuat toan TSP
            swap(a[i], a[j]);
            permute(a, i + 1, k, x, graph, cost);
            swap(a[i], a[j]);
        }
    }
}

int main() {
	cout << "Input: " << endl; 
    int n, r;
    cin >> n >> r;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1)); //Mang chi phi

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }

    cin.ignore(); //Xoa bo nho dem nhap vao

    vector<vector<int>> preferences(r); //Mang chua lich trinh cua tung nguoi

    for (int i = 0; i < r; ++i) { //Nhap lich trinh tung nguoi
        string line;
        getline(cin, line);

        stringstream ss(line);

        while (!ss.eof()) {
            int temp;
            ss >> temp;
            preferences[i].push_back(temp);
        }
    }

    vector<int> cost(r, INF); //Mang cost chua chi phi can tim cua tung nguoi

    for (int i = 0; i < r; ++i) { //Thuc hien TSP cho tung lich trinh
        permute(preferences[i], 1, preferences[i].size() - 2, i, graph, cost);
        if (cost[i] == INF) { 
		//Neu khong the di chuyen duoc thi chi phi bang vo cung, nhung theo de bai in ra 0
            cost[i] = 0;
        }
    }
	
	cout << "Output:" << endl;
	
    for (int i = 0; i < r; ++i) {
        cout << cost[i] << endl;
    }

    return 0;
} //Nguyen Huu Dung - 20215545

