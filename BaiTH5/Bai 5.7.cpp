//Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        while(k--){
            int a;
            cin >> a;
            if (t == 1) sum += a;
            if (t == -1) sum -= a;
//          ans = max(ans, -sum);
        }
// Vi ca thon deu bi xin tien hoac duoc phat tien nen ta cho lenh ra ngoai
		ans = max(ans, -sum);
    }
    cout << ans;
} //Nguyen Huu Dung - 20215545
