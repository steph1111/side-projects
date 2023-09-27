#include <iostream>
#include <iomanip>
#include <cmath>

double simpson(double x_0, double x_n, double (*func)(double), int n=100) {
  /**
    * Find the definite integral using the simpson's rule
    *
    * @param x_0: Lower limit of integration
    * @param x_n: Upper limit of integration
    * @param func: The integrand as a function of x
    * @param n: Number of sub intervals. Defaults to `n` = 100
    * @return The definite integral of func
  */
  // Cannot use the simpson's rule unless n is a even integer
  if (n % 2) throw std::invalid_argument("n must be devisable by 2");
  double h = (x_n - x_0) / n; // Number of sub intervals
  double result = func(x_0) + func(x_n);  // First and last value
  // Simpson's rule
  for (double x_i = x_0 + h, i = 0; x_i < x_n; x_i += h, i++) {
    result += !(int(i) % 2) ? 2 * func(x_i) : 4 * func(x_i);
  }
  return h / 3.0 * result;
}

double f(double x) {
  return (pow(x, 3) / 3.0) + sin(2*x);
}

int main() {
  std::cout << std::fixed << std::setprecision(10) << std::endl;
  std::cout << simpson(2, 3, f, 10000) << std::endl;
  return 0;
}