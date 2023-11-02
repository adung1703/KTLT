//Nguyen Huu Dung - 20215545
#include<bits/stdc++.h>
using namespace std;

struct bigNum {
    char sign;
    char num[101];
};

// Nhap va xu ly xau
void input(bigNum &x, bigNum &y){
    string tmp;
    cin >> tmp;
    x.sign = tmp[0];
    int lens1 = tmp.length() - 1;
    for(int i=0; i<lens1; i++){
        x.num[101-lens1+i] = tmp[i+1];
    }
    for(int i=0; i<101-lens1; i++) x.num[i] = '0';
    cin >> tmp;
    y.sign = tmp[0];
    int lens2 = tmp.length() - 1;
    for(int i=0; i<lens2; i++){
        y.num[101-lens2+i] = tmp[i+1];
    }
    for(int i=0; i<101-lens2; i++) y.num[i] = '0';
}

// Cong hai so nguyen cung dau
void add(char result[], char *x, char *y){
    int c = 0;

    for(int i=100; i>=0; i--){
        int tmp = (int)x[i] - 48 + (int)y[i] - 48 + c;
        c = tmp / 10;
        result[i] = tmp % 10 + 48;
    }
}

// Tru hai so nguyen cung dau (|x| > |y|)
void sub(char result[], char *x, char* y){
    int c = 0;

    for(int i=100; i>=0; i--){
        int tmp1 = (int)x[i] - 48;
        int tmp2 = (int)y[i] - 48;

        if(tmp1 >= tmp2 + c){
            result[i] = tmp1 - tmp2 - c + 48;
            c = 0;
        } else {
            tmp1 = tmp1 + 10;
            result[i] = tmp1 - tmp2 - c + 48;
            c = 1;
        }
    }
}

//Nhan hai so nguyen
void multi(char result[], char *x, char *y){
    // clear array result
    for(int i=0; i<101; i++) result[i] = '0';

    for(int i=100; i>=0; i--){
        // int 1 array temp
        char tmp[101];

        // add i number 0 to last array
        int k;
        for(k = 0; k < i; k++)
            tmp[100-k] = '0';

        int c = 0, sum = 0;
        for(int j=100; j>=0; j--){
            sum = ((int)x[i] - 48) * ((int)y[j] - 48) + c;
            tmp[k] = (sum % 10) + 48;
            c = sum / 10;
            k--; if(k < 0) break;
        }

        add(result,tmp,result);
    }
}

// Kiem tra x > y ?
bool check(char *x, char *y){
    int i, k;
    for(i = 0; i < 101; i++){
        if(x[i] != '0') break;
    }

    for(k = 0; k < 101; k++){
        if(y[k] != '0') break;
    }

    if(i > k) return false;
    else if(i < k) return true;
    else { // i == k
        int t = i;
        while(t < 101){
            if(x[t] < y[t]) return false;
            else if (x[t] > y[t]) return true;
            else {
                t++;
            }
        }
    }

    return true;
}

// Toan tu +
bigNum operator + (bigNum x, bigNum y){
    bigNum result;

    if(x.sign == '1' && y.sign == '1'){
        result.sign = '1';
        add(result.num,x.num,y.num);
        return result;
    } else if(x.sign == '1' && y.sign == '0'){
        if(check(x.num,y.num)){
            result.sign = '1';
            sub(result.num,x.num,y.num);
            return result;
        } else {
            result.sign = '0';
            sub(result.num,y.num,x.num);
            return result;
        }
    } else if(x.sign == '0' && y.sign == '1'){
        if(check(x.num,y.num)){
            result.sign = '0';
            sub(result.num,x.num,y.num);
            return result;
        } else {
            result.sign = '1';
            sub(result.num,y.num,x.num);
            return result;
        }
    } else {
        result.sign = '0';
        add(result.num,x.num,y.num);
        return result;
    }
}
//Toan tu -
bigNum operator - (bigNum x, bigNum y){
    bigNum result;

    if(x.sign == '1' && y.sign == '0'){
        y.sign = '1';
        result = x + y;
        return result;
    } else if(x.sign == '1' && y.sign == '1'){
        y.sign = '0';
        result = x + y;
        return result;
    } else if(x.sign == '0' && y.sign == '1'){
        y.sign = '0';
        result = x + y;
        return result;
    } else {
        y.sign = '1';
        result = x + y;
        return result;
    }
}
//Toan tu *
bigNum operator * (bigNum x, bigNum y){
    bigNum result;

    if(x.sign == '1' && y.sign == '1'){
        result.sign = '1';
        multi(result.num,x.num,y.num);
        return result;
    } else if(x.sign == '1' && y.sign == '0'){
        result.sign = '0';
        multi(result.num,x.num,y.num);
        return result;
    } else if(x.sign == '0' && y.sign == '1'){
        result.sign = '0';
        multi(result.num,x.num,y.num);
        return result;
    } else {
        result.sign = '1';
        multi(result.num,x.num,y.num);
        return result;
    }
}

// In ra
void printBigNumber(bigNum number){
    cout << number.sign;
    int start;
    for(start=0; start<101; start++)
        if(number.num[start] != '0') break;

    for(int i = start; i<101; i++)
        cout << number.num[i];
}

int main(){
    bigNum a, b;
    input(a,b);

    bigNum so3, so4;
    so3.sign = '1', so4.sign = '1';
    for(int i=0; i<100; i++){
        so3.num[i] = '0';
        so4.num[i] = '0';
    }
    so3.num[100] = 3 + 48;
    so4.num[100] = 4 + 48;

    bigNum result = a*b - so3 * a + so4 * b;

    printBigNumber(result);
} //Nguyen Huu Dung  - 20215545
