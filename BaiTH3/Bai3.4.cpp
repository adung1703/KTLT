//Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mang ghi nho loi giai cac bai toan con da duoc giai
void init(){
    memset(mem, -1, sizeof(mem));
}
//# Quy hoach dong,
//# Ham lis(i) tra ve do dai day con tang dai nhat ket thuc boi a[i]
int lis(int i) {
    /*Nguyen Huu Dung - 20215545*/
    if (mem[i] != -1)
        return mem[i]; //Neu da tim duoc day con tang dai nhat thi tra ve do dai day con
    int res = 1; //Ban dau do dai day bang 1 (chi co a[i])
    for (int j = 0; j < i; j++){
        if (a[j] < a[i]){ //Neu tim duoc phan tu a[j] < a[i]
            res = max(res, 1 + lis(j)); //thi tinh lai do dai
        }
    }
    mem[i] = res;
    return res;
}
//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){ 
            //Neu day ket thuc boi i co do dai = do dai day ket thuc boi j + 1
            trace(j); //Truy vet day ket thuc boi j
            break;
        }
    }
    cout << a[i] << " "; //In ra phan tu cuoi
}
    int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0; //Ban dau do dai day bang 1, ket thuc boi a[0]
    for(int i = 1; i < n; i++){
        if (res < lis(i)){ //Tim do dai lon nhat va vi tri ket thuc
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl; //In ra 
    trace(pos);
    return 0;
} //Nguyen Huu Dung - 20215545
