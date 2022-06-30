#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#define f(x) (x * x * x) - (6 * x * x) - 7
#define g(x) (3 * x * x)-(12 * x)
using namespace std;

void NewtonMethod(float a, float e);
void IterationMethod(float a, float b, float e);
double canon(double x);
double polinom(double x);
double derivative(double x);
double canon_derivative(double x);


int main(){
	float a, b, e;
    cout << setprecision(7) << fixed;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Enter error:";
    cin >> e;

	cout << endl<< "-------------------" <<endl;
    cout << "Newton method:" << endl;
    cout<< "-------------------" <<endl;
    NewtonMethod(a, e);

	cout << endl<< "-------------------" <<endl;
    cout << "Iterations method:" << endl;
    cout<< "-------------------" <<endl;
    IterationMethod(a, b, e);

    return 0;
}


void NewtonMethod(float a, float e){
	float x1, f0, f1, g0, temp, temp2;
	int step = 1;
	do
	 {
		  g0 = g(a);
		  f0 = f(a);
		  if(g0 == 0.0)
		  {
			   cout<<"Mathematical Error.";
			   exit(0);
		  }


		  x1 = a - f0/g0;
	if(x1 == temp || x1 == temp2){
       cout << "Root found. " << endl;
       break;
      }
		  temp = x1;
		  a = x1;
		  step = step+1;
		  if(step > 71)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }
		  f1 = f(x1);
		  if(step%2 == 0){
			  temp2 = x1;
		  }
		  
	 }while(step<71);

	 cout<< endl<<"Root is: "<< x1 << endl;
	 cout << "Iterations: " << step-1 << endl;
}
void IterationMethod(float a, float b, float e)
{
	short int Sign = 1;
	bool canoncheck = true;
	double x0, x1, temp = 0, k, maxd;
	maxd = fabs(derivative(a));
		while (temp <= b)
		{
			if (fabs(canon_derivative(temp)) > 1)
			canoncheck = 0;
			if (fabs(derivative(temp) > maxd))
			{
				maxd = fabs(derivative(temp));
				if (derivative(temp) < 0)
					Sign = -1;
				else
					Sign = 1;
			}
			temp = temp + 0.00001;						
		}
		int i = 0;
		x1 = a;
		if(!canoncheck)
		{
			k = (int)maxd/2;
			if(Sign > 0)
			k = k;
			else
			k = -k;
			do{
				x0 = x1;
				x1 = x0 -(polinom(x0)/k);
				++i;
			}while (fabs(x0-x1) > e);
		}	else
		{
			do{
				x0 = x1;
				x1 = canon(x0);
				++i;
			}while (fabs(x0 - x1) > e);
		}
		cout << endl << "Root is " << x1 << endl;
		cout << "Iterations: " << i << endl;
		}
double canon(double x){
	return 7/((x*x) - (6*x));
}
double polinom(double x){
	return (x * x * x) - (6 * x * x) - 7;
}
double derivative(double x){
	return (3*x*x) - (12 * x);
}
double canon_derivative(double x){
	return (3*x*x)/12;
}