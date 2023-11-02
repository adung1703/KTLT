//Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, c[MAX][MAX]; //# so thanh pho va ma tran chi phi
int cmin = INT_MAX; //# chi phi di lai nho nhat giua hai thanh pho khac nhau
int best = INT_MAX; //# tong chi phi nho nhat can tim, ban dau dat bang gia tri vo cung lon INT_MAX = 2^31-1
int curr; //# tong chi phi tai thoi diem hien tai
int mark[MAX]; //# danh dau nhung thanh pho da di
int x[MAX]; //# luu giu cac thanh pho da di
//# Doc du lieu vao
void input(){
	cin >> n; 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			cin >> c[i][j];
			if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
	}
}
//# Thuat toan quay lui
void TRY(int k){
	for(int i = 2; i <= n; i++){
	/*Nguyen Huu Dung - 20215545*/
	if (mark[i] != 1) {
            mark[i] = 1; //Danh dau thanh pho da di 
            x[k] = i; //Thanh pho den thu k la i
            curr += c[x[k-1]][x[k]]; //Cap nhat chi phi
            if (k == n) best = min(best, curr + c[x[n]][1]); //Neu da di qua het cac thanh pho
            else if (best > cmin*(n-k+1)) TRY(k+1); //Gioi han re nhanh
            //Tra ve trang thai truoc
            mark[i] = 0; 
            curr -= c[x[k-1]][x[k]];
        }
	}
}
int main() {
	input(); //Nhap vao 
	x[1] = 1; //Thanh pho 1 da di qua
	TRY(2); //Bat dau tu buoc thu 2
	cout << best; //In ra chi phi tot nhat
	return 0;
} //Nguyen Huu Dung - 20215545
