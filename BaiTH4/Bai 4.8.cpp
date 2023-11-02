// Nguyen Huu Dung - 20215545
// #include <iostream>
// #include <map>

// using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    //# Nguyen Huu Dung - 20215545 #
    map<T, double> c; //Tao mot map chua ket qua
    for (const auto &x : a) { //Duyet tung phan tu trong map
    	c[x.first] = x.second; //Insert phan tu do vao c
    }
    for (const auto &y :b) { //Duyet tung phan tu trong b
    	if (c.find(y.first)->first == y.first) { //Neu trong c da co phan tu dang duyet 
    		if (y.second > c[y.first]) c[y.first] = y.second; //Lay do thuoc lon hon
		}
		else c[y.first] = y.second; //Neu trong c chua co phan tu dang duyet
		//Insert phan tu va do thuoc trong b vao c
    }
    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    //# Nguyen Huu Dung - 20215545 #
    map<T, double> c; //Tao mot map chua ket qua
    for (const auto &x : a) {//Duyet tung phan tu trong a
    	if (b.find(x.first)->first == x.first) { //Neu phan tu do co trong b
    		if (b.find(x.first)->second > x.second) c[x.first] = x.second;
    		else c[x.first] = b.find(x.first)->second;
		} //Insert phan tu do voi do thuoc be hon
    }
    return c;
}

// template<class T>
// void print_fuzzy_set(const std::map<T, double> &a) {
//     cout << "{ ";
//     for (const auto &x : a) {
//         std::cout << "(" << x.first << ", " << x.second << ") ";
//     }
//     cout << "}";
//     std::cout << std::endl;
// }

// int main() {
//     std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
//     std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
//     std::cout << "A = "; print_fuzzy_set(a);
//     std::cout << "B = "; print_fuzzy_set(b);
//     std::map<int, double> c = fuzzy_set_union(a, b);
//     std::map<int, double> d = fuzzy_set_intersection(a, b);
//     std::cout << "Union: "; print_fuzzy_set(c);
//     std::cout << "Intersection: "; print_fuzzy_set(d);
// } //Nguyen Huu Dung - 20215545
