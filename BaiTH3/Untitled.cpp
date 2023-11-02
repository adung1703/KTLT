// Nguyen Van Duy - 20215334
/*
B�i 3.11. Superior l� m?t h�n d?o tuy?t d?p v?i  n  d?a di?m
ch?p ?nh v� c�c du?ng m?t chi?u n?i c�c di?m ch?p ?nh v?i nhau.
�o�n kh�ch tham quan c�  r  ngu?i v?i s? th�ch ch?p ?nh kh�c nhau.
Theo d�, m?i ngu?i s? dua ra danh s�ch c�c d?a di?m m� h? mu?n ch?p.
B?n c?n gi�p m?i ngu?i trong do�n l?p l?ch di chuy?n sao cho di qua
c�c di?m h? y�u c?u d�ng m?t l?n, kh�ng di qua di?m n�o kh�c,
b?t d?u t?i di?m d?u ti�n v� k?t th�c t?i di?m cu?i c�ng
trong danh s�ch m� h? dua ra, v� c� t?ng kho?ng c�ch
di l?i l� nh? nh?t.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <cstring>

using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
int curr; //# t?ng chi ph� t?i th?i di?m hi?n t?i
int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
int x[MAX]; //# luu gi? c�c th�nh ph? d� di

int r;

inline void show_curr() {
    cout << "curr : " << curr << endl;
}

//# �?c d? li?u v�o
inline void input(){
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
}

struct state {
    int i;
    int j;

    state(int i, int j) : i(i), j(j) {}
};

inline void show_x(size_t n) {
    for (int i = 1; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << " <- x[]" << endl;
}

inline void write(int i, int j) {
    mark[j] = 1;
    if (i == 1) {
        x[i] = j;
        return;
    }
    
    if (j) {
        x[i] = j;
        curr += c[x[i-1]][x[i]];
        return;
    } else {
        curr -= c[x[i-1]][x[i]];
        mark[x[i]] = 0;
        x[i] = j;
        return;
    }
}

int main() {
    input();

    cin.ignore();
    while (r--) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        vector<int> v;
        v.push_back(0);
        
        while (!ss.eof()) {
            int temp;
            ss >> temp;
            v.push_back(temp);
        }
        
        stack<state> s;
        memset(mark, 0, sizeof(mark));
        int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
        curr = 0;
        bool not_found = true;
        
        s.emplace(1, v[1]);
        while (!s.empty()) {
            state &top = s.top();
            int i = top.i, j = top.j;
            s.pop();
            
            write(i, j);
//            show_x(v.size());
            
            if (!j) continue;
            
            if (i == v.size() - 2 && c[j][v.back()]) {
                write(++i, v.back());
//                cout << "--";
//                show_x(v.size());
                
//                cout << ">> ";
//                show_x(v.size());
                if (curr < best) {
                    best = curr;
                    not_found = false;
                }
                
                write(i, 0);
//                cout << "--";
//                show_x(v.size());
                continue;
            }
            
            for (int k = 1; k < v.size() - 1; ++k) {
                if (!mark[v[k]] && c[j][v[k]]) {
                    s.emplace(i+1, 0);
                    s.emplace(i+1, v[k]);
                }
            }
        }

        if (not_found) {
            cout << "--> " << 0 << endl << endl << endl;
        } else {
            cout << "--> " << best << endl << endl << endl;
        }
        
    }
    
    return 0;
}
// Nguyen Van Duy - 20215334

