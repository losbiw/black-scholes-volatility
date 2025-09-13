#include <iostream>
#include <cassert>
#include <format>
#include "option.hpp"

int main()
{
  float C = 21.06;
  float S = 100;
  float K = 80;
  float T = 0.5;
  float r = 0.02;

  Option *option = new Option(C, S, K, T, r);

  float hard_coded_sigma = 0.2;
  float price = option->estimate_price(hard_coded_sigma);

  std::cout << "Supposed to be: " << C << std::endl;
  std::cout << "Instead got: " << price << std::endl;

  assert(C == price && "Prices do not match");
}