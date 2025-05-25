#include "option.hpp"
#include <cmath>
#include <iostream>

Option::Option(float P, float K, float T, float S, float r) : P(P), K(K), T(T), S(S), r(r) {}

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
    float error = erf(x / sqrt(2));
    float cdf = 0.5 * (1 + error);

    return cdf;
}

// error function
float Option::erf(float x)
{
    float integral = std::exp(-pow(x, 2)) - 1;
    float erf = (2 / sqrt(M_PI)) * integral;

    return erf;
}

float cdf(float x)
{
    float error = erf(x / sqrt(2));
    float cdf = 0.5 * (1 + error);

    return cdf;
}