#pragma once
#include <functional>

class Option
{
    float C; // price of the call
    float S; // price of the underlying asset
    float K; // strike price
    float T; // time to expiry
    float r; // risk-free interest rate

public:
    Option(float C, float S, float K, float T, float r);

    float estimate_price(float sigma);
    float calculate_iv();

private:
    float iv_guess();
    float newton_raphson(std::function<float(float)> func, float prev_guess, float tolerance);
};
