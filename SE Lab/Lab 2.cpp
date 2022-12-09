#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, n;
    double step;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input step(should be positive): ";
    cin >> step;
    if (!(step > 0)) {
        do {
            cout << "Step should be positive: ";
            cin >> step;
        } while (!(step > 0));
    }
    cout << "Input n >= 4, n: ";
    cin >> n;
    if (!(n >= 4)) {
        do {
            cout << "N should be equal to or more than 4" << endl;
            cout << "Input n: ";
            cin >> n;
        } while (!(n >= 4));
    }


    for (double x = a; x <= b; x += step) {
        if (x >= 0) {
            double mlt = 1;
            double sum = 0;
            for (int i = 0; i <= n - 1; i++) {
                for (int j = 0; j <= n - 1; j++) {
                    int j_0 = pow(j, 2);
                    mlt *= x + i + j_0;
                }
                sum += mlt;
                mlt = 1;
            }
            cout << "x = " << x << "  ";
            cout << "y = " << sum << endl;
        }
        else if (x < 0) {
            double mlt = 1;
            double y = 0;
            for (int j = 2; j <= n - 2; j++) {
                mlt = 1;
                mlt *= (j + 1);
            }
            y += mlt;
            cout << "x = " << x << "  ";
            cout << "y = " << mlt << endl;
        }
    }
    return 0;
}
