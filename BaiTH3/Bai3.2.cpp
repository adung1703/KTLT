//Nguyen Huu Dung - 20215545
#include <iostream>
using namespace std;
int n;
int X[100], Y[100]; //# Luu toa do cac buoc di chuyen cua quan ma
int mark[100][100]; //# Danh dau vi tri cac o ma quan ma da di chuyen qua
//# Mang hx, hy mo ta 8 vi tri quan ma co the di chuyen ke tu vi tri hien tai
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
//# In ra day cac di chuyen tim duoc
void print_sol(){
    for (int j = 1; j <= n * n; ++j) {
        printf("(%d %d)\n", X[j], Y[j]);
    }
    exit(0);
}
//# Thuat toan quay lui
void TRY(int k){
	for(int i = 0; i < 8; i++){
		int xx = X[k-1] + hx[i];
		int yy = Y[k-1] + hy[i];
		/*Nguyen Huu Dung - 20215545*/
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && mark[xx][yy] != 1) {
		    //Neu toa do dang xet chua di qua va nam trong ban co thi
            X[k] = xx; 
            Y[k] = yy;
            //Cap nhat toa do hien tai
            mark[X[k]][Y[k]] = 1; //Danh dau toa do hien tai da di qua
            // Kiem tra neu da di qua tat ca cac o tren ban co
            if (k == n * n)
                print_sol();
            else
                TRY(k + 1);
            // Tiep tuc xet den buoc tiep theo
            mark[X[k]][Y[k]] = 0;
        }
    }
}
int main(){
    cin >> n;
    mark[1][1] = 1; //Vi tri ban dau la (1 1) 
    X[1] = Y[1] = 1; //Vi tri hien tai
    TRY(2); //Bat dau tu buoc thu 2
    return 0;
} //Nguyen Huu Dung - 20215545
