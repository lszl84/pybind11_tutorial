#include <pybind11/pybind11.h>

int simple_cpp_function(int a, int b) { return a + b; }

PYBIND11_MODULE(simple_module, m) {
  m.def("simple_cpp_function", &simple_cpp_function);
}
