//Nguyen Huu Dung - 20215545
#include <iostream>
#include <cmath>
using namespace std; //Khai bao thu vien 

int main(){
	int N, M; 
	cin>>N; 
	int a[N+1]; //Mang a chua he so cua A(x) co N+1 phan tu
	for (int i = 0; i <= N; i++) cin>>a[i]; //a[i] la he so cua x^i
	cin>>M; 
	int b[M+1]; //Mang b chua he so cua B(x) co M+1 phan tu
	for (int i = 0; i <= M; i++) cin>>b[i]; //b[i] la he so cua x^i
	int K = N + M; 
	long c[K+1]={0}; //Mang c chua he so cua tich C(x) = A(x)*B(x)
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			c[i+j] += a[i] * b[j]; //Tinh C(x) va gan vao mang c
		}
	}
	int S = 0; //S la ket qua cua XOR cac he so
	for (int i = 0; i <= K; i++) S = S^c[i];
	cout<<S;
return 0;
} //Nguyen Huu Dung - 20215545

