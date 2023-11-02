//Nguyen Huu Dung - 20215545
/* Bai 1.10. Viet chuong trinh nhap vao 2 ma tran vuong 
cung kich thuoc n*n, trong do n nhap tu ban phim.
Sau do tinh tong va tich cua hai ma tran do va dua ket qua ra man hinh.
*/
#include <stdio.h>
#include <cstdlib>
void allocate_mem(int ***a, int n){
//#Allocate memory for the matrix
    *a = (int**)malloc(n * sizeof(int*)); //Cap phat cho ma tran
    for (int i = 0; i < n; i++) 
        (*a)[i] = (int*)malloc(n * sizeof(int)); //Cap phat tung hang
}
void input(int **mt, int n){
//#Input elements of the matrix
    int i=0;	
	while(i < n){
    	printf("Row[%d] = ",i);
    	for (int j = 0; j < n; j++) scanf("%d", &mt[i][j]);	
    	i++;
	}
}
void output(int **mt, int n){
//# Print all elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", mt[i][j]);
        printf("\n");
    }
}
void free_mem(int **mt, int n){
    for (int i = 0; i < n; i++) delete [] mt[i]; //Giai phong cac hang
    delete [] mt; //Giai phong ma tran
}
void add(int **a, int **b, int n){
// Add two matrix
	int **mt;
	allocate_mem(&mt, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) mt[i][j] = a[i][j] + b[i][j];
	output(mt, n);
	free_mem(mt, n);
}
void mult(int **a, int **b, int n){
// Multiply two matrix
	int **mt;
	allocate_mem(&mt, n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++){
			mt[i][j] = 0;
			for (int k=0; k<n; k++)	mt[i][j] += a[i][k] * b[k][j];
		}
	output(mt, n);
	free_mem(mt, n);
}

int main(){
int n, **a, **b;
printf("Enter n = ");
scanf("%d", &n);
allocate_mem(&a, n);
allocate_mem(&b, n);
printf("Enter the first matrix:\n");
input(a, n);
printf("First matrix:\n");
output(a, n);
printf("Enter the second matrix:\n");
input(b, n);
printf("Second matrix:\n");
output(b, n);
printf("Sum of two matrix:\n");
add(a,b,n);
printf("Product of two matrix:\n");
mult(a,b,n);
free_mem(a, n);
free_mem(b, n);
return 0;
} //Nguyen Huu Dung - 20215545

