#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;  // Example: x³ - x - 2
}

int main() {
    double a, b, c;
    int max_iter;
    double tolerance;

    cout << "Enter lower bound (a): ";
    cin >> a;
    cout << "Enter upper bound (b): ";
    cin >> b;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) should have opposite signs." << endl;
        return 1;
    }
  
    cout << "Enter tolerance (e.g. 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> max_iter;

    int iter = 0;
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        cout << "Iteration " << iter + 1 << ": c = " << c << " f(c) = " << f(c) << endl;

        if (f(c) == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iter++;

    } while (fabs(f(c)) > tolerance && iter < max_iter);

    cout << "\nApproximate root: " << c << endl;

    return 0;
}
