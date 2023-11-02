// Nguyen Huu Dung - 20215545 
// #include <iostream>
// #include <set>

// using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    //# Nguyen Huu Dung - 20215545 #
    set<T> c; //Tao mot set chua ket qua
    for (const T &x : a) c.insert(x); 
    for (const T &x : b) c.insert(x); 
		//Dua tat ca phan tu trong a va b vao c
    return c;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    //# Nguyen Huu Dung - 20215545 #
    set<T> c; //Tao mot set chua ket qua
    for (const T &x : a) {
        if (*b.find(x) == x) c.insert(x); 
    }	//Phan tu nao co trong ca a va b thi cho vao c
    return c;
}

// template<class T>
// void print_set(const std::set<T> &a) {
//     for (const T &x : a) {
//         std::cout << x << ' ';
//     }
//     std::cout << std::endl;
// }

// int main() {
//     std::set<int> a = {1, 2, 3, 5, 7};
//     std::set<int> b = {2, 4, 5, 6, 9};
//     std::set<int> c = set_union(a, b);
//     std::set<int> d = set_intersection(a, b);
    
//     std::cout << "Union: "; print_set(c);
//     std::cout << "Intersection: "; print_set(d);

//     return 0;
// } //Nguyen Huu Dung - 20215545
