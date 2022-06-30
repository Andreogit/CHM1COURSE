#include <iostream>
#include <math.h>
using namespace std;
void cramer(double a[3][3]);
void print(double M[3][3]);
void invert(double a[3][3]);

void invert(double a[3][3], double x, double y, double z)
{
    double m11,m12,m13,m21,m22,m23,m31,m32,m33,det, solvedx, solvedy, solvedz;
    det = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1]) - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0]) + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    m11 = (1/det)*(a[1][1]*a[2][2]-a[1][2]*a[2][1]);
    m12 = (-1/det)*(a[1][0]*a[2][2]-a[1][2]*a[2][0]);
    m13 = (1/det)*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    m21 = (-1/det)*(a[0][1]*a[2][2]-a[0][2]*a[2][1]);
    m22 = (1/det)*(a[0][0]*a[2][2]-a[0][2]*a[2][0]);
    m23 = (-1/det)*(a[0][0]*a[2][1]-a[0][1]*a[2][0]);
    m31 = (1/det)*(a[0][1]*a[1][2]-a[0][2]*a[1][1]);
    m32 = (-1/det)*(a[0][0]*a[1][2]-a[0][2]*a[1][0]);
    m33 = (1/det)*(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    double tr_matxdet[3][3] ={  
   {m11, m21, m31},
   {m12, m22, m32},
   {m13, m23, m33}
};
solvedx = (m11*x) + (m21*y) + (m31*z);
solvedy = (m12*x) + (m22*y) + (m32*z);
solvedz = (m13*x) + (m23*y) + (m33*z);
cout << "Matrix is solved with invert method" << endl << "Answer: x = " << solvedx << "; y = " << solvedy << "; z = " << solvedz<< endl;
}
void cramer(double a[3][3], double x,double y,double z)
{
double det, detx, dety, detz, solvedx, solvedy, solvedz;
double xmat [3][3] ={  
   {x, a[0][1], a[0][2]} ,
   {y, a[1][1], a[1][2]} ,
   {z, a[2][1], a[2][2]}
};
double ymat [3][3] ={  
   {a[0][0], x, a[0][2]} ,
   {a[1][0], y, a[1][2]} ,
   {a[2][0], z, a[2][2]}
};
double zmat [3][3] ={  
   {a[0][0], a[0][1], x} ,
   {a[1][0], a[1][1], y} ,
   {a[2][0], a[2][1], z}
};
det = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1]) - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0]) + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
if(det == 0)
{
    cout << "Determinant = 0";
    return;
}
detx = xmat[0][0]*(xmat[1][1]*xmat[2][2]-xmat[1][2]*xmat[2][1]) - xmat[0][1]*(xmat[1][0]*xmat[2][2]-xmat[1][2]*xmat[2][0]) + xmat[0][2]*(xmat[1][0]*xmat[2][1]-xmat[1][1]*xmat[2][0]);
dety = ymat[0][0]*(ymat[1][1]*ymat[2][2]-ymat[1][2]*ymat[2][1]) - ymat[0][1]*(ymat[1][0]*ymat[2][2]-ymat[1][2]*ymat[2][0]) + ymat[0][2]*(ymat[1][0]*ymat[2][1]-ymat[1][1]*ymat[2][0]);
detz = zmat[0][0]*(zmat[1][1]*zmat[2][2]-zmat[1][2]*zmat[2][1]) - zmat[0][1]*(zmat[1][0]*zmat[2][2]-zmat[1][2]*zmat[2][0]) + zmat[0][2]*(zmat[1][0]*zmat[2][1]-zmat[1][1]*zmat[2][0]);
solvedx = detx/det;
solvedy = dety/det;
solvedz = detz/det;
//cout << "Determinant of matrix is: "<<det<< endl;
// cout << "Determinant of x matrix is: " << detx<< endl;
// cout << "Determinant of y matrix is: " << dety<< endl;
// cout << "Determinant of z matrix is: " << detz << endl;
cout << "Matrix is solved with Cramer's rule" << endl << "Answer: x = " << solvedx << "; y = " << solvedy << "; z = " << solvedz<< endl;
}
void print(double M[3][3])
{
    cout << "Your matrix: " << endl;
    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
}
int main() {
    double x, y, z;
    double matrix[3][3];
        cout << "Enter your matrix(3x3):" << endl;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << "Enter x, y, z: ";
        cin >> x >> y >> z;
        print(matrix);
        cramer(matrix, x, y, z);
        invert(matrix, x, y, z);
    return 0;
}
