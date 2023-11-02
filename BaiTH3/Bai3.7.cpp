#include <bits/stdc++.h>
using namespace std;
struct state{
    int i, j, old_L; 
    //i : so vi tri hien tai trong xau
    //j : gia tri cua bit hien tai
    //old_L : so bit 1 truoc do
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
    i(_i), j(_j), old_L(_L){}
};
int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        //# Kh? ?? quy
        /*Nguyen Huu Dung - 20215545*/
        if (top.j > 0) L = top.old_L; //Neu bit hien tai >0 thi gan L=old.L
        if (top.j > 1) { //Neu bit hien tai lon hon 1 thi nem ra
            s.pop();
            continue;
        }
        if (L+1 < k || top.j == 0) { //Neu L<k-1 hoac bit hien tai = 0
            x[top.i] = top.j; //Luu bit hien tai vao mang x
            top.old_L = L; //So luong bit 1 lien tiep la L
            if (top.j) L++; //Neu bit hien tai bang 1 thi L++
            else L = 0; //Nguoc lai L=0
            s.push(state(top.i+1,0)); //Them bit 0 vao
        }
        ++top.j; //Bit hien tai tang 1 don vi
    }
    return 0;
} //Nguyen Huu Dung - 20215545

