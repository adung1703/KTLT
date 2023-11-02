//Nguyen Huu Dung - 20215545
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// #include <utility>
// using namespace std;
// using Point = pair<double, double>;
double area(Point a, Point b, Point c) {
//# Nguyen Huu Dung - 20215545 #
	double A = sqrt(pow(b.first - c.first , 2) + pow(b.second - c.second , 2)); 
	    //A = BC = sqrt((x_b-x_c)^2 + (y_b-y_c)^2)
	double B = sqrt(pow(c.first - a.first , 2) + pow(c.second - a.second , 2)); 
	    //B = CA = sqrt((x_c-x_a)^2 + (y_c-y_a)^2)
	double C = sqrt(pow(a.first - b.first , 2) + pow(a.second - b.second , 2)); 
	    //C = AB = sqrt((x_a-x_b)^2 + (y_a-y_b)^2)
	return sqrt((A+B+C) * (A+B-C) * (A+C-B) * (B+C-A)/16); // Cong thuc Herong
}
// int main() {
// cout << setprecision(2) << fixed;
// cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
// return 0;
// } 
//Nguyen Huu Dung - 20215545
