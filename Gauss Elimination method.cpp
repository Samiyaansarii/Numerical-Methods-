#include <iostream>
using namespace std;

int main() {
    double a[3][4], x[3];

    cout << "Enter augmented matrix (3x4):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];

    for (int i = 0; i < 3; i++) {
        for (int k = i + 1; k < 3; k++) {
            double f = a[k][i] / a[i][i];
            for (int j = 0; j < 4; j++)
                a[k][j] -= f * a[i][j];
        }
    }

    for (int i = 2; i >= 0; i--) {
        x[i] = a[i][3];
        for (int j = i + 1; j < 3; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    cout << "\nSolutions:\n";
    for (int i = 0; i < 3; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;

    return 0;
}
