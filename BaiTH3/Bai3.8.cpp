//Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;
struct state{
	int i, j; 
	// i la so thu tu cua qua can
	// j de xac dinh dia chua qua can (j = +-1)
	state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};
int main() {	
	int n, M;
	cin >> n >> M;
	int m[n+1]; //Can nang cac qua can
	for (int i = 1; i <= n; ++i) cin >> m[i];
	int x[n+1]; //x[i] = -1 neu qua can i nam o dia can chua vat
	//x[i] = 1 neu nam o dia can con lai
	stack<state> s;
	//# sum of selected weights
	int sum = 0;
	s.push(state(1, -1));
	while (!s.empty()){
		state &top = s.top();
		if (top.i > n){
			if (sum == M){
				for (int i = 1; i <= n; ++i){
					if (x[i] == -1) cout << '-' << m[i];
					if (x[i] == 1) cout << '+' << m[i];
				}
				cout << "=" << M;
				exit(0);
			} s.pop();
			continue;
		}
		//# Khu de quy
		//Nguyen Huu Dung - 20215545
		//# YOUR CODE HERE #
		//Quay lui
		if (top.j > -1) //Neu qua can nam o dia khong chua vat 
			sum -= m[top.i] * x[top.i];  //Giam tong 
		//Moi truong hop con deu da duoc xet 
		if (top.j > 1) { //j > 1 thi push sai mau, pop ra
			s.pop();
			continue;
		} //top.j = -1 hoac top.j =1
		x[top.i] = top.j; 
		sum += m[top.i] * x[top.i];
		s.push(state(top.i+1, -1));
		++top.j;
	}
	cout << -1;
	return 0;
} //Nguyen Huu Dung - 20215545
