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

    static float cdf(float x);
    static float erf(float x);

private:
    float iv_guess();
    float newton_raphson(float (Option::*)(float x), float prev_guess, float tolerance);

    static float power_expansion(float x, int depth);
    static int factorial(int x);
};
