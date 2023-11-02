/*
Bai 1.5. Viet ham tra ve con tro tro toi 
gia tri lon nhat cua mot mang cac so double. 
Neu mang rong hay tra ve NULL.
*/
//Nguyen Huu Dung - 20215545
#include <stdio.h>
double* maximum(double* a, int size){
    double *max; //Khoi tao con tro max
    max = a; //Ban dau cho max tro toi vi tri dau tien trong mang
    if (a==NULL) return NULL; //Neu mang rong tra ve NULL
    //*****************
    //# YOUR CODE HERE - Nguyen Huu Dung - 20215545#
    for (int i=0; i<size; i++){ //Duyet mang
        if(a[i]>*max) max=&a[i]; /*Neu gia tri phan tu lon hon max
        thi gan gia tri do vao max */
    }
    //*****************
    return max;
}
int main(){
	double arr[] = {1., 10., 2., -7., 25., 3.};
	double* max = maximum(arr, 6);
	printf("%.0f", *max);
	return 0;
}
//Nguyen Huu Dung - 20215545

