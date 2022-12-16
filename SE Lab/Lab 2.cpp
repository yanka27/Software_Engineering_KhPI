#include <iostream>
#include <cmath>

using namespace std;

void inputA(double& a) {

    cout << "Input a: ";

    if (!(cin >> a)) {
        throw "Incorrect data.";
    }
}

void inputB(double& b, double& a) {

    cout << "Input b: ";

    if (!(cin >> b)) {
        throw "Incorrect data.";
    }
    if (a > b) {
        throw "Error. 'b' must be lower than 'a'.";
    }
}

void inputN(double& n) {

    cout << "Input n (n >= 4): ";

    if (!(cin >> n)) {
        throw "Incorrect data.";
    }
    if (n < 4) {
        throw "Error. 'n' cannot be lower than 4.";
    }
    if (!(n == (int)n)) {
        throw "Error. 'n' must be an integer.";
    }
}

void inputStep(double& step) {

    cout << "Input step: ";

    if (!(cin >> step)) {
        throw "Incorrect data.";
    }
    if (step <= 0) {
        throw "Error. 'step' must be higher than 0.";
    }
}

double equation(double x, int n) {

    double result;
    double mlt = 1;
    if (x < 0) {
        double y = 0;
        for (int j = 2; j <= n - 2; j++) {
            mlt = 1;
            mlt *= (j + 1);
        }
        y += mlt;
        result = mlt;
    }
    else if (x >= 0) {
        double sum = 0;
        for (int i = 0; i <= n - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                int j_0 = pow(j, 2);
                mlt *= x + i + j_0;
            }
            sum += mlt;
            mlt = 1;
        }
        result = sum;
    }
    return result;
}

void sequence(double& a, double& b, double n, double step) {

    for (a; a <= b; a = a + step) {
        cout << "x = " << a << " " << "y = " << equation(a, n) << endl;
    }
}

int main() {

    double a, b, n, step;
    try {
        inputA(a);
        inputB(b, a);
        inputN(n);
        inputStep(step);
        sequence(a, b, n, step);
    }
    catch (const char* message) {
        cout << message << endl;
    }
    catch (...) {
        cout << "Unknown error." << endl;
    }
    return 0;
}
