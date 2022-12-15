#include <iostream>
#include <cmath>

using namespace std;

void inputA(double& a) {
        cout << "Input a: ";
        while (!(cin >> a)) {
            if (cin.eof()) return;      
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. Try again." << endl;
            cout << "Input a: ";
        }
}

void inputB(double& b, double& a) {
    do {
        cout << "Input b: ";
        while (!(cin >> b)) {
            if (cin.eof()) return;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error. 'b' should be more than 'a'." << endl;
            cout << "Input b: ";
        }
    } while (a > b);
}

void inputN(double& n) {
    do {
        cout << "Input n (n >= 4): " ;
        while (!(cin >> n)) {         
            if (cin.eof()) return;      
            cin.clear();             
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "'n' should be equal to or more than 4." << endl;
            cout << "Input n: ";
        }
    } while (n < 4|| !(n == (int)n));
}

void inputStep(double& step) {
    do {

        cout << "Input step: ";
        while (!(cin >> step)) {
            if (cin.eof()) return;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "'step' should be positive." << endl;
            cout << "Input step: ";
        }
    } while (step <= 0);
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
    inputA(a);
    inputB(b, a);
    inputN(n);
    inputStep(step);
    sequence(a, b, n, step);

    return 0;
}
