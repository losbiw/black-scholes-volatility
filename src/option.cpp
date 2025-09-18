#include "math.h"
#include "option.h"
#include <cmath>
#include <iostream>

#define TOLERANCE_LEVEL pow(10, -6)

Option::Option(float C, float S, float K, float T, float r) : C(C), S(S), K(K), T(T), r(r)
{
}

// estimates initial guess for implied volatility using Brenner's and Subrahmanyam's method
float Option::iv_guess()
{
    const float atm_value = 0.398f;
    float isd = (C / S) / (atm_value * sqrt(T));

    return isd;
}

float Option::calculate_iv()
{
    float initial_guess = iv_guess();
    float newton_result = Math::newton_raphson(std::bind(&Option::price_volatility, this, std::placeholders::_1), initial_guess, TOLERANCE_LEVEL);

    if (newton_result != NULL)
    {
        return newton_result;
    }

    // use brent's as a fallback in case newton doesn't converge
}

float Option::price_volatility(float sigma)
{
    return Option::estimate_price(sigma) - C;
}

float Option::estimate_price(float sigma)
{
    float sqrtT = sqrt(T);
    float d1 = (log(S / K) + (r + pow(sigma, 2) / 2) * T) / (sigma * sqrtT);
    float d2 = d1 - sigma * sqrtT;

    float phi1 = Math::cdf(d1);
    float phi2 = Math::cdf(d2);

    float price = S * phi1 - std::exp(-r * T) * K * phi2;
    return price;
}
