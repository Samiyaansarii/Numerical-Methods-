#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x=0, y=0, z=0, x1, y1, z1;
    int iter = 0;
    double e = 0.0001;

    cout << "Enter tolerance (e.g. 0.0001): ";
    cin >> e;

    do {
        x1 = (7 - y + z) / 4;
        y1 = (21 - 4 * x1 - z) / 8;
        z1 = (15 - 2 * x1 + y1) / 5;

        if (fabs(x - x1) < e && fabs(y - y1) < e && fabs(z - z1) < e)
            break;

        x = x1;
        y = y1;
        z = z1;
        iter++;

    } while (iter < 100);

    cout << "\nSolutions:\n";
    cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;

    return 0;
}
