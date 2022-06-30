#include <iostream>
#include <array>

void LaGrange_polynomial(std::array <const double, 10 > x, std::array < double, 10 > y, const double x0);
void Newton_polynomial(std::array <const double, 10 > x, std::array < double, 10 > y, const double x0);

void LaGrange_polynomial(std::array <const double, 10 > x, std::array < double, 10 > y, const double x0){
  double L {};
  double res = 1;
  for (int i = 0; i != x.size(); ++i) {
    for (int j = 0; j != y.size(); ++j) {
      if (i != j)
        res *= (x0 - x[j]) / (x[i] - x[j]);
    }
    L += res * y[i];
    res = 1;
  }
  std::cout << L << '\n';
}
void Newton_polynomial(std::array <const double, 10 > x, std::array < double, 10 > y, const double x0){
  double L {};
  double res = 1;
  for (int i = 0; i != x.size() - 1; ++i)
    for (int j = x.size() - 1; j != i; --j)
      y[j] = (y[j] - y[j - 1]) / (x[j] - x[j - i - 1]);
  for (int i = x.size() - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++)
      res *= (x0 - x[j]);
    res *= y[i];
    L += res;
    res = 1;
  }
  std::cout << L;
}

int main() {
  std::array < const double, 10 > x {
      0.01,
      0.06,
      0.11,
      0.16,
      0.21,
      0.26,
      0.31,
      0.36,
      0.41,
      0.46
    };
  std::array < double, 10 > y {
    0.99,
    0.95,
    0.91,
    0.88,
    0.84,
    0.81,
    0.78,
    0.74,
    0.71,
    0.68
  };
  const double x0 = 0.08;
  std::cout << std::endl;
  std::cout << "LaGrange method:" << std::endl;
  LaGrange_polynomial(x, y, x0);
  std::cout << std::endl << "Newton method:" << std::endl;
  Newton_polynomial(x, y, x0);
}