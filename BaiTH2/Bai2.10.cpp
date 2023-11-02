//Nguyen Huu Dung - 20215545
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
const int N = 128;
struct Matrix {
	unsigned int mat[N][N];
	Matrix() {
		memset(mat, 0, sizeof mat);
	}
};
bool operator == (const Matrix &a, const Matrix &b) { //Ham so sanh hai ma tran
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a.mat[i][j] != b.mat[i][j]) return false;
		}
	}
	return true;
}
Matrix multiply_naive(const Matrix &a, const Matrix &b) { //Ham tinh tich 2 ma tran cach thong thuong
	Matrix c;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
		}
	}
	return c;
}
Matrix multiply_fast(const Matrix &a, const Matrix &b) { //Ham tinh nhanh tich 2 ma tran
	/*Nguyen Huu Dung - 20215545*/
	Matrix c;
	
	for (int i = 0; i < 128; ++i) {
		for (int j = 0; j < 128; ++j) {
			int sum = 0;
			for (int k = 0; k < 128; ++k) {
				sum += a.mat[i][k] * b.mat[k][j];
			}
			c.mat[i][j] = sum;
		}
	}
	return c;
}
Matrix gen_random_matrix() { //Tao ngau nhien ma tran
	Matrix a;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			a.mat[i][j] = rand();
		}
	}
	return a;
}
Matrix base;
double benchmark(Matrix (*multiply) (const Matrix&, const Matrix&), Matrix &result) { //Ham do toc do tinh toan
	const int NUM_TEST = 10;
	const int NUM_ITER = 64;
	Matrix a = base;
	result = a;
	double taken = 0;
	for (int t = 0; t < NUM_TEST; ++t) {
		clock_t start = clock();
		for (int i = 0; i < NUM_ITER; ++i) {
			a = multiply(a, result);
			result = multiply(result, a);
		}
		clock_t finish = clock();
		taken += (double)(finish - start);
	}
	taken /= NUM_TEST;
	printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
	return taken;
}
int main() {
	base = gen_random_matrix();
	Matrix a, b;
	printf("Slow version\n");
	double slow = benchmark(multiply_naive, a);
	printf("Fast version\n");
	double fast = benchmark(multiply_fast, b);
	if (a == b) {
		printf("Correct answer! Your code is %.2f%% faster\n", slow / fast* 100.0);
	} else {
		printf("Wrong answer!\n");
	}
	return 0;
}//Nguyen Huu Dung - 20215545
