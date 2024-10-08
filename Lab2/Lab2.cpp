#include <iostream>
#include <cmath>
#include <complex>
#include <limits>


using namespace std;

// rafal.potempa@polsl.pl

/*
Proszę napisać fragment kodu, który

1. rozwiązuje równanie liniowe
   ax + b = 0

2. rozwiązuje układ równań liniowych
   ax + by + c = 0
    dx + ey + f = 0

3. rozwiązuje równanie kwadratowe (także dla pierwiastków zespolonych)
   ax² + bx + c = 0

*/


void solve_linear(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Równanie tożsamościowe (nieskończenie wiele rozwiązań)" << endl;
        }
        else {
            cout << "Brak rozwiązań" << endl;
        }
    }
    else {
        double x = -b / a;
        cout << "Rozwiązanie równania liniowego: x = " << x << endl;
    }
}


void solve_linear_system(double a, double b, double c, double d, double e, double f) {
    double determinant = a * e - b * d;

    if (determinant == 0) {
        cout << "Brak rozwiązań lub nieskończenie wiele rozwiązań" << endl;
    }
    else {
        double x = (c * e - b * f) / determinant;
        double y = (a * f - c * d) / determinant;
        cout << "Rozwiązanie układu równań: x = " << x << ", y = " << y << endl;
    }
}

// ax^2 + bx + c = 0
void solve_quadratic(double a, double b, double c) {
    if (a == 0) {
        // Redukuje się do równania liniowego
        solve_linear(b, c);
        return;
    }

    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Rozwiązania rzeczywiste: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (delta == 0) {
        double x = -b / (2 * a);
        cout << "Jedno rozwiązanie: x = " << x << endl;
    }
    else {
        complex<double> sqrt_delta = sqrt(complex<double>(delta, 0));
        complex<double> x1 = (-b + sqrt_delta) / (2.0 * a);
        complex<double> x2 = (-b - sqrt_delta) / (2.0 * a);
        cout << "Rozwiązania zespolone: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
}

//int main() {
//    double a = 2, b = -4;
//    solve_linear(a, b);
//    return 0;
//}
//
//
//int main() {
//    double a = 2, b = -1, c = -1;
//    double d = -3, e = 4, f = -2;
//    solve_linear_system(a, b, c, d, e, f);
//    return 0;
//}
//
//
int main() {
    double a, b, c;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;

    solve_quadratic(a, b, c);
    return 0;
}


