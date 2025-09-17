#include "math.h"
#include <cmath>

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