#pragma once

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
    float price_volatility(float sigma);
    float calculate_iv();

private:
    float iv_guess();
};
