// Nguyen Van Duy - 20215334
/*
Bài 3.11. Superior là m?t hòn d?o tuy?t d?p v?i  n  d?a di?m
ch?p ?nh và các du?ng m?t chi?u n?i các di?m ch?p ?nh v?i nhau.
Ðoàn khách tham quan có  r  ngu?i v?i s? thích ch?p ?nh khác nhau.
Theo dó, m?i ngu?i s? dua ra danh sách các d?a di?m mà h? mu?n ch?p.
B?n c?n giúp m?i ngu?i trong doàn l?p l?ch di chuy?n sao cho di qua
các di?m h? yêu c?u dúng m?t l?n, không di qua di?m nào khác,
b?t d?u t?i di?m d?u tiên và k?t thúc t?i di?m cu?i cùng
trong danh sách mà h? dua ra, và có t?ng kho?ng cách
di l?i là nh? nh?t.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <cstring>

using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# s? thành ph? và ma tr?n chi phí
int curr; //# t?ng chi phí t?i th?i di?m hi?n t?i
int mark[MAX]; //# dánh d?u nh?ng thành ph? dã di
int x[MAX]; //# luu gi? các thành ph? dã di

int r;

inline void show_curr() {
    cout << "curr : " << curr << endl;
}

//# Ð?c d? li?u vào
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
        int best = INT_MAX; //# t?ng chi phí nh? nh?t c?n tìm, ban d?u d?t b?ng giá tr? vô cùng l?n INT_MAX = 2^31-1
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

