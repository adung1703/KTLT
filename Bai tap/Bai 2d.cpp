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
    
    int id;
    cin >> id;
    int res_id = -1;
    
    for (int i = 0; i < N; i++){
    	if (arr[i].id == id) {
    		double max = 0;
    		for (int k = 0; k < N; k++) {	
    			bool t = true;
    			for (int j = 0; j < 5; j++) {
    				if (arr[k].id == arr[i].customers[j]) t = false;
				}
				
				if (t) {
					if (max < arr[k].income) {
						max = arr[k].income;
						res_id = k;
					}
				}
			}
		}
		break;
	}
	
	if (res_id == -1) cout << "-1";
	else cout << arr[res_id].id;

    return 0;
}

