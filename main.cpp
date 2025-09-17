#include "option.h"
#include <iostream>

void assign_user_vars(float &C, float &S, float &K, float &T, float &r)
{
    std::cout << "Call price: ";
    std::cin >> C;

    std::cout << "Current asset price: ";
    std::cin >> S;

    std::cout << "Strike price: ";
    std::cin >> K;

    std::cout << "Time to expiry: ";
    std::cin >> T;

    std::cout << "Risk-free interest rate: ";
    std::cin >> r;
}

int main()
{
    float C, S, K, T, r;
    assign_user_vars(C, S, K, T, r);

    Option *option = new Option(C, S, K, T, r);
    float sigma = option->calculate_iv();

    std::cout << sigma << std::endl;
}