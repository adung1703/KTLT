// Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
	// i: Thu tu ngay trong lich
	// j: Ngay do lam hay nghi
	// old_L : So ngay lam viec lien tiep
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
            i(_i), j(_j), old_L(_L){}
};

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;
    int x[N+1];
    stack<state> s;
    
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > N){ //Neu da co lich trinh du cac ngay
            if (x[N] && top.old_L >= K1 || !x[N]) { //Neu ngay cuoi di lam va so ngay di lam lien tiep >= k1
            										//Hoac ngay cuoi nghi 
                for (int i = 1; i <= N; ++i)		//In ra lich trinh
                    cout << x[i];
                cout << endl;
            }
            s.pop(); //Xoa ra khoi stack
            continue;
        } 
        s.pop(); 
        x[top.i] = top.j;
        if (top.j == 1) { //Neu ngay hien tai di lam
            L = top.old_L + 1; //So ngay di lam = old_L + 1
            if (L >= K1) { //Neu so ngay di lam lien tiep >= K1
                s.push(state(top.i + 1, 0, L)); 
            } else {
                s.push(state(top.i + 1, 1, L));
            }
        } else {
            L = 0;
            if (top.old_L + 1 <= K2) { //Neu so ngay di lam lien tiep khong vuot qua K2
                s.push(state(top.i, 1, top.old_L));
            }
            s.push(state(top.i+1, 1, L));
        }
    }
    return 0;
}// Nguyen Huu Dung - 20215545