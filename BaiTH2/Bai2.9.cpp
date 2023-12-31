#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
using namespace std;
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}
double x[NUM_INPUTS];
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}
//# BEGIN fast code
//# khai bao cac bien phu tro can thiet
/*Nguyen Huu Dung - 20215545*/
int N=20000;
double a[20000], Delta = (double)28.0/N;
//# ham chuan bi du lieu
void precalc() {
    /*Nguyen Huu Dung - 20215545*/
    for (int i=1; i<N-1; i++) {
        a[i]=1.0/(1.0+exp(14-i*Delta));
    }
}//# ham tinh sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    /*Nguyen Huu Dung - 20215545*/
    if (x>=14) return 1;
    else if (x<=-14) return 0;
    else {
        int i = (x+14)/Delta;
        return a[i]+a[i]*(1-a[i])*(x+14-Delta*i);
    }
}
//# END fast code
double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    //# printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;
    if (a.size() != b.size()) return false;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}
int main() {
prepare_input();
precalc();
vector<double> a, b;
double slow = benchmark(sigmoid_slow, a);
double fast = benchmark(sigmoid_fast, b);
double xval;
scanf("%lf", &xval);
printf("%.2f \n", sigmoid_fast(xval));
if (is_correct(a, b) && (slow/fast > 1.3)) {
    printf("Correct answer! Your code is faster at least 30%!\n");
} else {
    printf("Wrong answer or your code is not fast enough!\n");
}
return 0;
} //Nguyen Huu Dung - 20215545

