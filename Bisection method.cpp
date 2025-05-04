#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

int main() {
    double a = 1, b = 2, c;
    double error = 0.0001;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval! f(a) and f(b) should have opposite signs." << endl;
        return 1;
    }

    while ((b - a) >= error) {
        c = (a + b) / 2;

        if (f(c) == 0.0)
            break;
            
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    cout << "The root is: " << c << endl;
    return 0;
}

