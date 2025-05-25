class Option
{
    float P; // value of the option
    float K; // strike price
    float T; // time to expiry
    float S; // price of the underlying asset
    float r; // risk-free interest rate
    float estimated_price;

public:
    Option(float P, float S, float K, float T, float r);

    float estimate_price(float sigma);

private:
    float cdf(float x);
    float erf(float x);
};

float cdf(float x);