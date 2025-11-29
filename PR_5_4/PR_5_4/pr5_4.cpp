#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

double term(const int i, const int K, const int N) {
    double i_sq = (double)i * i;
    double denominator = (double)K * K + (double)N * N;

    if (denominator == 0.0) {
        return 0.0;
    }

    return i_sq / denominator;
}

double sum_iterative(const int K, const int N) {
    double s = 0.0;
    for (int i = K; i <= N; i++) {
        s += term(i, K, N);
    }
    return s;
}

double sum_rec_descent_inc(const int K, const int N, const int i) {
    if (i > N) {
        return 0.0;
    }
    else {
        return term(i, K, N) + sum_rec_descent_inc(K, N, i + 1);
    }
}

double sum_rec_descent_dec(const int K, const int N, const int i) {
    if (i < K) {
        return 0.0;
    }
    else {
        return term(i, K, N) + sum_rec_descent_dec(K, N, i - 1);
    }
}

double sum_rec_ascent_inc(const int K, const int N, const int i, double t) {
    if (i > N) {
        return t;
    }
    else {
        return sum_rec_ascent_inc(K, N, i + 1, t + term(i, K, N));
    }
}

double sum_rec_ascent_dec(const int K, const int N, const int i, double t) {
    if (i < K) {
        return t;
    }
    else {
        return sum_rec_ascent_dec(K, N, i - 1, t + term(i, K, N));
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int K, N;

    cout << "Введіть нижню межу K (ціле число): ";
    if (!(cin >> K)) {
        cerr << "Помилка введення K." << endl;
        return 1;
    }
    cout << "Введіть верхню межу N (ціле число): ";
    if (!(cin >> N)) {
        cerr << "Помилка введення N." << endl;
        return 1;
    }

    if (K > N) {
        cout << "Увага: K > N. Сума в такому разі дорівнює 0 (порожня сума)." << endl;
    }

    cout << fixed << setprecision(10) << endl;

    cout << "### Результати обчислення суми ###" << endl;

    cout << "1) Ітераційний (iter): \t\t\t"
        << sum_iterative(K, N) << endl;

    cout << "2) Рекурсивний спуск, i++: \t\t"
        << sum_rec_descent_inc(K, N, K) << endl;

    cout << "3) Рекурсивний спуск, i--: \t\t"
        << sum_rec_descent_dec(K, N, N) << endl;

    cout << "4) Рекурсивний підйом, i++ (акум.): \t"
        << sum_rec_ascent_inc(K, N, K, 0.0) << endl;

    cout << "5) Рекурсивний підйом, i-- (акум.): \t"
        << sum_rec_ascent_dec(K, N, N, 0.0) << endl;

    return 0;
}