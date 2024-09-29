#include "main.hpp"

using namespace std;
//!  build g++ -fsanitize=address -o main -Iinclude -std=c++17 main.cpp
//! run : ./main
int main(int argc, char *argv[])
{
  // xt::xarray<double> a = {{1., 2.}, {3., 4.}, {5., 6.}, {7., 8.}};
  // auto shape = a.shape();
  // cout << xt::adapt(shape) << endl;

  // xt::xtensor<double, 2> b = {{1., 2.}, {3., 4.}};
  // std::cout << b << std::endl;

  // xt::xtensor_fixed<double, xt::xshape<2, 2>> c = {{1., 2.}, {3., 4.}};
  // auto sh = c.shape();

  xt::xarray<string> labels = {"a", "b", "c"};
  cout << labels << endl;

  auto shape = labels.shape();
  cout << xt::adapt(shape) << endl;

  return 0;
}