#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef struct Market{
    int id;
    string name;
    double income;
    double money;
    int customers[5];
} Market;

int main()
{
    int N;
    cin>>N;
    Market arr[N];
    
    for(int i = 0; i < N; i++){
        cin>>arr[i].id;
        cin>>arr[i].name;
        cin>>arr[i].income;
        cin>>arr[i].money;
        cin>>arr[i].customers[0];
        cin>>arr[i].customers[1];
        cin>>arr[i].customers[2];
        cin>>arr[i].customers[3];
        cin>>arr[i].customers[4];
    }
    
    int X;
    cin >> X;
    double X_income = 0;
    int m = 0;
    
    for(int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++){
			if (arr[i].customers[j] == X) {
				X_income += arr[i].income;
				m++;
				break;
			}
		}
	}
	if (m == 0) cout << "0";
	else {
		int avr_income = int (X_income/m) + 1;
		cout << avr_income;
	}

    return 0;
}

