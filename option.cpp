#include "math.h"
#include "option.h"
#include <cmath>
#include <functional>
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
    return newton_raphson(std::bind(&Option::estimate_price, this, std::placeholders::_1), initial_guess, TOLERANCE_LEVEL);
}

float Option::newton_raphson(std::function<float(float)> func, float prev_guess, float tolerance)
{
    float f_at_x0 = func(prev_guess);
    float derivative = (func(prev_guess + DERIVATIVE_STEP_SIZE) - func(prev_guess)) / DERIVATIVE_STEP_SIZE;
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

    float phi1 = Math::cdf(d1);
    float phi2 = Math::cdf(d2);

    float price = S * phi1 - std::exp(-r * T) * K * phi2;
    return price;
}
