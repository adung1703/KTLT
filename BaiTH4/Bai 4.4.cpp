//Nguyen Huu Dung - 20215545
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
} //Ham in ra mang

void delete_even(vector<int> &a) {
    //# Nguyen Huu Dung - 20215545 #
    long unsigned int i = 0;
    while(i<a.size()) { //Duyet tung phan tu
    	if (a[i]%2 == 0){ 
    	    for (long unsigned int j = i; j < a.size(); j++) a[j] = a[j+1];
    	    a.pop_back();//Xoa phan tu chan trong mang bang phep dich chuyen
    	}
    	else i++; //Tranh truong hop 2 so chan lien tiep
	}
}

void sort_decrease(vector<int> &a) {
    //# Nguyen Huu Dung - 20215545 #
    //Sap xep giam dan
    for (long unsigned int i = 0; i < a.size()-1; i++){
    	for (long unsigned int j = i; j < a.size(); j++){
    		if (a[i] < a[j]) {
    			int tmp = a[i];
    			a[i] = a[j];
    			a[j] = tmp;
			}
		}
	}
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    //# Nguyen Huu Dung - 20215545 #
    long unsigned int i = 0, j = 0; //Ki thuat hai con tro
    vector<int> c;
    while ( i < a.size() && j < b.size()) {
    	if (a[i] < b[j]) {
    		c.push_back(b[j]);
    		j++;
		}
		else {
			c.push_back(a[i]);
			i++;
		}
	} //Lay lan luot phan tu lon nhat trong hai mang da sap xep
	while (i < a.size()) {
		c.push_back(a[i]);
		i++;
	}
	while (j < b.size()) {
		c.push_back(b[j]);
		j++;
	}
	//Neu mot trong hai mang van con phan tu thi dua not vao 
	return c;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
} //Nguyen Huu Dung - 20215545
