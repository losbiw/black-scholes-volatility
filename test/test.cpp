#include "../src/option.h"
#include <cassert>
#include <format>
#include <iostream>

int main()
{
  float C = 3.99;
  float S = 100;
  float K = 105;
  float T = 0.5;
  float r = 0.02;
  float actual_vol = 0.2;

  Option *option = new Option(C, S, K, T, r);

  float sigma = option->calculate_iv();

  std::cout << "Supposed to be: " << actual_vol << std::endl;
  std::cout << "Instead got: " << sigma << std::endl;

  assert(actual_vol == sigma && "Prices do not match");
}