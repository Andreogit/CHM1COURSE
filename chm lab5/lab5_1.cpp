#include <iostream> 
#include <Windows.h> 
#include <math.h>
#define N 4
using namespace std;
void JacobiMethod(double A[N][N], double B[N], double e);
void SeidelMethod(double A[N][N], double B[N], double e); 
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double A[4][4] = {0.65, -0.06, -0.12, 0.14, 0.04, -0.82, 0.08, 0.11, 0.34, 0.08, -0.66, -0.14, 0.11, 0.12, 0.00, -0.53};
    double B[4] = {2.17, -1.4, 2.1, -0.8};
    double e = 0.001;

cout << endl << "Seidel method:\n";
SeidelMethod(A, B, e);
cout << "\nJacobi method:\n";
JacobiMethod(A, B, e);
}
void SeidelMethod(double A[N][N], double B[N], double e){
    double a[N][N], b[N], X1[N], X[N], T[N];
    for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][i] != 0) {
                    b[i] = B[i] / A[i][i];
                    a[i][j] = -A[i][j] / A[i][i];
                    a[i][i] = 0;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        X1[i] = b[i];
        T[i] = b[i];
    }
    double sum = 0;
    int c = 0, count = 1;
    do {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    sum += a[i][j] * X1[j];
                }
            }
            X[i] = b[i] + sum;
            X1[i] = X[i];
            sum = 0;
        }
        for (int k = 0; k < N; ++k) {
            if (fabs(T[k] - X[k]) > e) continue;
            else c = 1;
        }
        if (c == 1) break;
        else {
            cout << count << " iteration " << X[0] << " " << X[1] << " " << X[2] << " " << X[3] << endl;
        }
        for (int i = 0; i < N; ++i) {
            T[i] = X[i];
        }
        c = 0;
        count++;
    } while (1);
}
void JacobiMethod(double A[N][N], double B[N], double e){
    double a[N][N], b[N], X1[N], X[N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][i] != 0) {
                b[i] = B[i] / A[i][i];
                a[i][j] = -A[i][j] / A[i][i];
                a[i][i] = 0;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        X1[i] = b[i];
    }
    double sum = 0;
    int c = 0, count = 1;
    do {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    sum += a[i][j] * X1[j];
                }
            }
            X[i] = b[i] + sum;
            sum = 0;
        }
        for (int k = 0; k < N; ++k) {
            if (fabs(X1[k] - X[k]) > e) continue;
            else c = 1;
        }
        if (c == 1) break;
        else {
            cout << count << " iteration: " << X[0] << " " << X[1] << " " << X[2] << " " << X[3] << endl;
        }
        for (int i = 0; i < N; ++i) {
            X1[i] = X[i];
        }
        c = 0;
        count++;
    } while (1);
}