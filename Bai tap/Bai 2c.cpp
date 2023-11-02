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
    
    int m=0;
    
    for (int i = 0; i < N; i++){
    	bool k = true;
    	for (int j = 0; j < 5; j++) {
    		for (int t = 0; t < N; t++) 
				if (arr[t].id == arr[i].customers[j])
				if (arr[t].income <= arr[i].income) {
					k = false;
					break;
				}
		}
		if (k == true) m++;
	}	

	cout << m;
    return 0;
}

