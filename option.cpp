#include "option.hpp"
#include <cmath>
#include <iostream>

#define TOLERANCE_LEVEL pow(10, -8)
#define DERIVATIVE_STEP_SIZE 0.0001

Option::Option(float C, float S, float K, float T, float r) : C(C), S(S), K(K), T(T), r(r)
{
}

// estimates initial guess for implied volatility using Brenner's and Subrahmanyam's method
float Option::iv_guess()
{
    const float atm_value = 0.398;
    float isd = (C / S) / (atm_value * sqrt(T));

    return isd;
}

float Option::calculate_iv()
{
    float initial_guess = iv_guess();
    return newton_raphson(&Option::estimate_price, initial_guess, TOLERANCE_LEVEL);
}

float Option::newton_raphson(float (Option::*func)(float x), float prev_guess, float tolerance)
{
    float f_at_x0 = (this->*func)(prev_guess);
    float derivative = ((this->*func)(prev_guess + DERIVATIVE_STEP_SIZE) - f_at_x0) / DERIVATIVE_STEP_SIZE;
    float improved_guess = prev_guess - (f_at_x0 / derivative);

    if (abs(improved_guess - prev_guess) > tolerance)
    {
        return newton_raphson(func, improved_guess, tolerance);
    }

    return improved_guess;
}

float Option::estimate_price(float sigma)
{
    float d1 = (log(S / K) + (r + pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));
    float d2 = d1 - sigma * sqrt(T);

    // cumulative density function of the standard normal distribution
    float phi1 = cdf(d1);
    float phi2 = cdf(d2);

    float price = S * phi1 - std::exp(-r * T) * K * phi2;
    return price;
}

// cumulative density of the standard normal distribution
float Option::cdf(float x)
{
    float error = Option::erf(x / sqrt(2));
    float cdf = 0.5 * (1 + error);

    return cdf;
}

float Option::power_expansion(float x, int depth)
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
float Option::erf(float x)
{
    float expansion = power_expansion(x, 5);
    float erf = (2 / sqrt(M_PI)) * expansion;

    return erf;
}

int Option::factorial(int x)
{
    if (x <= 1)
        return 1;

    return x * factorial(x - 1);
}
