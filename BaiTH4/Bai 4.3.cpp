// Nguyen Huu Dung - 20215545
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;
// using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    //# Nguyen Huu Dung - 20215545 #
    Vector c = make_tuple( 	get<1>(a)*get<2>(b) - get<2>(a)*get<1>(b) , 
							get<2>(a)*get<0>(b) - get<0>(a)*get<2>(b) , 
							get<0>(a)*get<1>(b) - get<1>(a)*get<0>(b) );
			//a = (a0, a1, a2); b = (b0, b1, b2)
			//[a,b] = ( a1.b2-a2.b1 , a2.b0-a0.b2 , a0.b1-a1.b0 )
    return c;
}

// int main() {
//     cout << setprecision(2) << fixed;
//     Vector a {1.2, 4, -0.5};
//     Vector b {1.5, -2, 2.5};
//     Vector c = cross_product(a, b);
//     cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
//     return 0;
// }
//Nguyen Huu Dung - 20215545
