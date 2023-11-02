//Nguyen Huu Dung - 20215545
#include <bits/stdc++.h>

using namespace std;

int m, w, h;
int table[601][601];

void init() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            table[i][j] = i*j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
//	int m, w, h; // Khai bao ra ben ngoai
    cin >> w >> h;
    cin >> m;
    init();
    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }

    //dp
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            int minWaste = table[i][j];
            // horizonal cut
            for(int k=1; k<=i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i-k][j]);
            }
            // vertical cut
            for (int k=1; k<=j; k++) { // k<=i -> k<=j
                minWaste = min(minWaste, table[i][k] + table[i][j-k]);
            }
            table[i][j] = minWaste;
        }
    }

    cout << table[h][w] << endl;
} //Nguyen Huu Dung - 20215545
