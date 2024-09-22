#include <nanobind/nanobind.h>

NB_MODULE(_test24_impl, m) {
    m.def("hello", []() { return "Hello world!"; });
}