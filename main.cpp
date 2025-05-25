#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "option.hpp"

void assign_user_vars(float &P, float &S, float &K, float &T, float &r)
{
    std::cout << "Option price: ";
    std::cin >> P;

    std::cout << "Asset price: ";
    std::cin >> S;

    std::cout << "Strike price: ";
    std::cin >> K;

    std::cout << "Time to expiry: ";
    std::cin >> T;

    std::cout << "Risk-free interest rate: ";
    std::cin >> r;
}

// int main()
// {
//     float P, S, K, T, r;
//     assign_user_vars(P, S, K, T, r);

//     Option *option = new Option(P, S, K, T, r);

//     float hard_coded_sigma = 0.2;
//     float price = option->estimate_price(hard_coded_sigma);

//     std::cout << price << std::endl;
// }

int main()
{
    std::cout << cdf(1);
}