#pragma once
#include <functional>

namespace Math
{
  float cdf(float x);
  float erf(float x);
  float power_expansion(float x, int depth);
  int factorial(int x);

  float newton_raphson(std::function<float(float)> func, float prev_guess, float tolerance);
  float brent();
}