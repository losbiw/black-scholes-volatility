#include "math.h"
#include <cmath>
#include <functional>

#define DERIVATIVE_STEP_SIZE 0.00001

// cumulative density of the standard normal distribution
float Math::cdf(float x)
{
  float error = Math::erf(x / sqrt(2));
  float cdf = 0.5 * (1 + error);

  return cdf;
}

float Math::power_expansion(float x, int depth)
{
  float sum = 0;

  for (int i = 0; i < depth; i++)
  {
    int common_factor = 2 * i + 1;
    float numerator = pow(-1, i) * pow(x, common_factor);
    float denumerator = factorial(i) * common_factor;

    sum += numerator / denumerator;
  }

  return sum;
}

float Math::newton_raphson(std::function<float(float)> f, float x0, float tolerance)
{
  float fx0 = f(x0);
  float dx = (f(x0 + DERIVATIVE_STEP_SIZE) - fx0) / DERIVATIVE_STEP_SIZE;
  float x1 = x0 - (fx0 / dx);

  if (abs(x1 - x0) > tolerance)
  {
    return newton_raphson(f, x1, tolerance);
  }

  return x1;
}

// error function
float Math::erf(float x)
{
  float expansion = power_expansion(x, 5);
  float erf = (2 / sqrt(M_PI)) * expansion;

  return erf;
}

int Math::factorial(int x)
{
  if (x <= 1)
    return 1;

  return x * factorial(x - 1);
}