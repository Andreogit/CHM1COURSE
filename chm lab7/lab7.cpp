#include <iostream>
#include <math.h>
#include <iomanip>
#define eps 0.00001
using namespace std;
double det2x2 (double matrix[2][2]);
double f1 (double x, double y);
double f2 (double x, double y);
void iterationMethod();
void NewtonMethod ();

double det2x2 (double matrix[2][2]){
  double result = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
  return result;
}

double f1 (double x, double y){
  return sin(x+2)-y-1.5;
}

double f2 (double x, double y){
  return x+cos(y-2)-0.5;
}

void iterationMethod (){
  double x0, y0;
  double x = 0;
  double y = 0;
  int count = 0;
    do{
        x0 = x;
        y0 = y;
        x = -(cos (y - 2) - 0.5);
        y = sin(x + 2) - 1.5;
        count++;
        cout << "x = " << x << "\t";
        cout << "y = " << y << endl;
      }while (abs (x - x0) > eps && abs (y - y0) > eps);
  cout << "Iterations with iteration method: " << count << endl;
}

void NewtonMethod (){
  double x = 0, y = 0, x0 = 0, y0 = 0, deltaX = 0, deltaY = 0, count = 0;
  double JacobiMatr[2][2], firstDet[2][2], secondDet[2][2];
      do{
          x0 = x;
          y0 = y;
          JacobiMatr[0][0] = cos (x0 + 2);
          JacobiMatr[0][1] = -1;
          JacobiMatr[1][0] = 1;
          JacobiMatr[1][1] = -sin (y0 - 2);
          for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 2; ++j){
              firstDet[i][j] = JacobiMatr[i][j];
              secondDet[i][j] = JacobiMatr[i][j];
              if (j == 0 && i == 0)
              firstDet[i][j] = f1 (x0, y0);
              		else if (i == 1 && j == 0)
              firstDet[i][j] = f2 (x0, y0);
              		else if (i == 0)
              secondDet[i][j] = f1 (x0, y0);
              		else
              secondDet[i][j] = f2 (x0, y0);
            }
          }
          deltaX = -1 / det2x2 (JacobiMatr) * det2x2 (firstDet);
          deltaY = -1 / det2x2 (JacobiMatr) * det2x2 (secondDet);
          x = x0 + deltaX;
          y = y0 + deltaY;
          count++;
          cout << "x = " << x << "\t";
          cout << "y = " << y << endl;
        }while (abs (deltaX) > eps + abs (deltaY) > eps);
  cout << "Iterations with Newton's method: " << count << endl;
}

int main(){
  cout<< endl <<"\tIteration method:"<<"\n";
  iterationMethod();
  cout<< endl <<"\tNewton's method:"<<"\n";
  NewtonMethod();
  return 0;
}
