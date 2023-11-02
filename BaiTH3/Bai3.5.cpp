//Nguyen Huu Dung - 20215545
#include <iostream>
using namespace std;
int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}
int binom2(int n, int k){
    //# Khu de quy
    /*Nguyen Huu Dung - 20215545*/
    //Cong thuc to hop: n!/(k!*(n-k)!) = (n-k+1)*...*n/k!
    long a = 1, b = 1; //a la mau so, b la tu so
    for (int i = 1; i <= k; i++) a *= i;
    for (int i = n - k + 1; i <= n; i++) b *= i;
    return b/a;
}
int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){ //Giai theo cach de quy
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){ //Giai theo cach khong dung de quy
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}//Nguyen Huu Dung - 20215545
