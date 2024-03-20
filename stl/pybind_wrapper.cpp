#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <algorithm>
#include <random>
#include <stdexcept>
#include <vector>

std::vector<int> generate_random_integers(int n, int a, int b) {
  if (n < 1 || a > b) {
    throw std::invalid_argument(
        "Invalid arguments for generate_random_integers");
  }

  std::vector<int> random_numbers(n);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(a, b);

  std::generate(random_numbers.begin(), random_numbers.end(),
                [&gen, &distrib]() { return distrib(gen); });

  return random_numbers;
}

PYBIND11_MODULE(stl_module, m) {
  m.def("generate_random_integers", &generate_random_integers);
}
