#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#define eps 0.0001
using namespace std;
double determinant3x3(double mat[3][3]){
double det;
det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
    - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
    + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
return det;
}
int main(){
double A1[5][4] = {-1,-5, 0,-6,
                    1,-1, 2,-3,
                   -1, 2,-5, 0,
                    1,-2, 3, 3,
                    1, 3, 2, 4 };
double matB[5] = {-6,-3, 0, 3, 4};
double AT[3][5], 
       B[5], 
       A[5][3];
//AX = B
//znaydemo matricyu koeficientiv - N,
//N = Aᵀ*A
for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 3; ++j) {
        A[i][j] = A1[i][j];
        AT[j][i] = A[i][j];
    }
}
for (int i = 0; i < 5; ++i) {
    B[i] = A1[i][3];
}
for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            AT[i][j];
        }
    }
double N[3][3] = {0}, 
       C[3] = {0},//matricya C viln'yh chleniv
       L[3][3] = {0},
       sum;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            C[i]=0;
            for (int k = 0; k < 5; ++k) {
                N[i][j] += AT[i][k] * A[k][j];
                C[i] += AT[i][k] * B[k];
            }
        }
    }

if (abs(determinant3x3(N)) < eps) {
    cout << "No roots by square method" << endl;
    return 1;
}
cout << "\tMatrix N" << endl;
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        cout << N[i][j] << "\t";
    }
    cout << endl;
}
cout <<endl << "\tMatrix C" << endl;
for (int i = 0; i < 3; ++i) {
    cout << "\t"<< C[i] << endl; 
}
cout << endl;
cout << "det N = "<<determinant3x3(N)<<endl << endl;

for (int i = 0; i < 3; i++) {
    double temp = 0;
    for (int k = 0; k < i; k++) {
        temp = temp + L[k][i] * L[k][i];
    }
    L[i][i] = sqrt(N[i][i] - temp);
    for (int j = i; j < 3; j++) {
            temp = 0;
            for (int k = 0; k < i; k++) {
                temp = temp + L[k][i] * L[k][j];
            }
            L[i][j] = (N[i][j] - temp) / L[i][i];
        }
}
cout << "\tMatrix L" << endl;
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        cout << std::setprecision(3) << L[i][j] << "\t";
    }
    cout << endl;
}
double LT[3][3];
for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        LT[i][j]=L[j][i];
    }
}
double x[3], y[3];
for (int i = 0; i < 3; ++i) {
    double sum=0;
    for (int j = 0; j < 3; ++j) {
        sum+=LT[i][j]*y[j];
    }
    y[i]=(C[i]-sum)/L[i][i];
}
cout<< endl <<"\tSolution SLAE (LY=C)"<<endl;
cout<<"y1 = "<<y[0]<<endl;
cout<<"y2 = "<<y[1]<<endl;
cout<<"y3 = "<<y[2]<<endl;
for(int i=2;i>=0;i--)
{
    double sum=0;
    for(int j=2;j>i;j--){
        sum+=L[i][j]*x[j];
    }
    x[i]=(y[i]-sum)/L[i][i];
}
cout << "\tNormal SLAE solved by square root method"<<endl;
cout<<"x1 = "<<x[0]<<endl << "x2 = "<<x[1]<<endl << "x3 = "<<x[2]<<endl;
}
