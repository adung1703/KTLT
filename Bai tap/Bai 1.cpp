#include <bits/stdc++.h>
using namespace std;

int input(int N) {
	if (N > 100) return 1;
	else return 0;
}

typedef struct Home{
	double square;
	double cost;
	int yr;
} 

int avrsqr(Home h[], int N){
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += h[i].square;
	}
	double avr = sum/N;
	if (avr > 100) return 1;
	else return 0;
}

int maxyr(Home h[], int N){
	Home home;
	int max_yr = h[0].yr;
	for (int i = 1; i < N; i++) {
		if (h[i].yr > max_yr) {
			max_yr = h[i].yr;
			home = h[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (h[i].yr == max_yr && h[i].square > home.square) home = h[i];
	}
	if ((double)home.yr > home.square) return 1;
	else return 0;
}

int mincost(Home h[], int N){
	Home home;
	int min_cost = h[0].cost;
	int k = 0;
	for (int i = 1; i < N; i++) {
		if (h[i].cost < min_cost) {
			min_cost = h[i].cost;
			home = h[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (h[i].cost == min_cost && h[i].yr < home.yr) home = h[i];
	}
	for (int i = 0; i < N; i++) {
		if (h[i].cost == min_cost && h[i].yr == home.yr) k++;
	}
	return k;
}

int invest(Home h[],int N){
	double inv = h[0].cost*h[0].yr/h[0].square;
	int k = 0;
	for (int i = 1; i < N; i++) {
		if (h[i].cost*h[i].yr/h[i].square > inv) 
		inv = h[i].cost*h[i].yr/h[i].square;
	}
	for (int i = 0; i < N; i++) {
		if (h[i].cost*h[i].yr/h[i].square == inv) k++;
	}
	return k;
}

int main(){
	int N;
	cin >> N;
	Home h[N];
	for (int i = 0; i < N; i++) {
		cin >> h[i].square >> h[i].cost >> h[i].yr; 
	}
	cout << "Cau a: " << input(N) << endl;
	cout << "Cau b: " << avrsqr(h, N) << endl;
	cout << "Cau c: " << maxyr(h, N) << endl;
	cout << "Cau d: " << mincost(h, N) << endl;
	cout << "Cau e: " << invest(h, N) << endl;
	return 0;
} 
