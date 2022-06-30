#include <iostream>
#include <cmath>

double f(double x){
    return sqrt(x)* log(1+pow(x, (2/3)));
}
double f1(double x){
    return (-9*log(pow(x , (2/3))+1) - 8*(2/(pow(x, 2/3)+1) + 1/(pow(x, (2/3)))/pow(x, (1/6)*(pow(x, (2/3))+1))+(24/(pow(x, (2/3))+1)))/36);
}
double f4(double x){
    return (-1/(2*pow(x,(11/6))+2*pow(x, (5/2))))
     +(1/(3*sqrt(x)*(pow((pow(x, (2/3))+1), 3))))
     +(3*log(pow(x, (2/3))+1)/(8 * pow(x, (5/2))))
     -(8/(27*pow(x, (7/6))*pow((pow(x, (2/3)) + 1),3)))
     -(1/(27*pow(x, (11/6))*pow((pow(x, (2/3)) + 1),3)));
}
void leftRectangleMethod(double a, double b, int steps){

    double area = 0;
    double h = (a+b)/steps;
    for ( int i = 0; i < steps; ++i){
        area += h * (f(a + i * h));
    }
    double MaxF = f1(a + h);
    for( double x = a + 2 * h; x < b; x+=h)
            if(f1(x)> MaxF)
            MaxF = f1(x);
            double error = (MaxF / 24)* (b - a) * h * h;
            std::cout << "Left Rectangle method:\nResult: " << area << "\nError: " << error << '\n'; 
}
void rightRectangleMethod(double a, double b, double steps){
    double area = 0;
    double h = (a+b)/steps;
    for( int i = 0; i < steps; i++){
        area+= h * f (a + i*h);
    }
    double MaxF = f1(a+h);
    for(double x = a + 2 * h; x < b; x+=h)
    if(f1(x) > MaxF)
    MaxF = f1(x);
    double error = -1 * ((MaxF / 24) * (b - a) * h * h);
    std::cout << "Right Rectangle method:\nResult: " << area << "\nError: " << error << '\n'; 
}
void centerRectangleMethod(double a, double b, int steps){
    double area = 0;
    double h = (a+b)/steps;
    for(int i = 0; i < steps; ++i)
        area+= h * (f((a + i * h) + h / 2));
        double MaxF = f4(a+h);
        for(double x = a + 2 * h; x < b;x += h)
        if(f4(x) > MaxF)
        MaxF = f4(x);
        double error = (MaxF / 24) * (b-a) * h *h;
        std::cout << "Center Rectangle method:\nResult: " << area << "\nError: " << error << '\n';
}

void trapezoidalMethod(double a, double b, int steps){
    double area = 0;
    double h = (a + b) / steps;
    area = h * (f(a) + f(b)) / 2;
    for(int i = 1; i < steps; i++)
    area += h * f(a + i * h);
    double MaxF = f1(a + h);
    for(double x = a + 2 * h; x < b; x+=h)
    if(f1(x) > MaxF)
    MaxF = f1(x);
    double error = -1 * (MaxF / 12) * (b-a) * h * h;
    std::cout << "Trapezpidal method:\nResult: " << area << "\nError :" << error << '\n';
}

void simpsonMethod(double a, double b, int steps){
    double area = 0;
    double h = (a + b) / steps;
    area = f(a) + f(b);
    for(int i = 1; i <= steps/2; i++)
    area += 4 * f(a + (2 * static_cast<double>(i)-1) * h);
    for(int i = 1; i <= steps / 2; i++)
    area += 2 * f(a + (2 * static_cast<double>(i)) * h);
    area *= h/3;
    double MaxF = f4(a+h);
    for(double x = a + 2 * h; x < b; x += h)
    if(f4(x) > MaxF)
    MaxF = f4(x);
    double error = -1 * (MaxF / 180) * (b - a) * h * h *h * h;
    std::cout << "Simpson method\nResult: " << area << "\nError: " << error << '\n';
}
int main(){
    leftRectangleMethod(0, 3, 10);
    rightRectangleMethod(0, 3, 10);
    centerRectangleMethod(0, 3, 10);
    trapezoidalMethod(0, 3, 10);
    simpsonMethod(0, 3, 10);
    return 0;
}