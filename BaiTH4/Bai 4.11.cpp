//Nguyen Huu Dung - 20215545
#include<bits/stdc++.h>
using namespace std;
struct wall {
    int a; //a : so ten giac
    int k; //k : kha nang chong tra cua 1 linh

    wall(int a, int k){ //Constructor
        this->a = a;
        this->k = k;
    }
};

//Sap xep theo thu tu uu tien ve kha nang chong tra
struct compare{
    bool operator() (wall x, wall y){
        int X, Y;

        if(x.a <= x.k) X = x.a;
        else X = x.k;

        if(y.a <= y.k) Y = y.a;
        else Y = y.k;

        return X < Y;
    }
};

int n, s, kill_enemy, total_enemy;
priority_queue<wall, vector<wall>, compare> p_q; 
//Hang doi uu tien luu cac doan tuong

int main(){
    cin >> n >> s; //Nhap so doan tuong va so linh
    kill_enemy = 0;
    total_enemy = 0;
    //Nhap du lieu tuong ung cho tung doan tuong
    for(int i=0; i<n; i++){ 
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        total_enemy += tmp1;
        p_q.push(wall(tmp1, tmp2));
    }
    while(!p_q.empty() && s>0){ //Bo tri tung linh cho doan tuong
        wall tmp = p_q.top(); //Doan tuong dang xet
		p_q.pop();

        if(tmp.a <= tmp.k){
            kill_enemy += tmp.a; //So giac bi giet
        } else {
            int nenemy = tmp.a - tmp.k; //So giac con lai
            p_q.push(wall(nenemy, tmp.k));
            kill_enemy += tmp.k; //So giac bi giet
        }
        s -= 1; //Giam di 1 linh trong phan con lai
    }
    cout << total_enemy - kill_enemy;
    
    return 0;
} //Nguyen Huu Dung - 20215545