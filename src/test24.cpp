#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/string.h>
#include <vector>
#include <string>
#include <regex>
#include <numeric>

namespace nb = nanobind;

// template <class T>
std::string join(char delimiter,
                 std::vector<std::string>::iterator begin,
                 std::vector<std::string>::iterator end)
{

    if (begin == end)
    {
        return std::string();
    }
    if (std::next(begin) == end)
    {
        return std::string(*begin);
    }
    return std::accumulate(std::next(begin),
                           end,
                           *begin,
                           [delimiter](const std::string a,
                                       const std::string b) -> std::string
                           { return a + delimiter + b; });
}

NB_MODULE(_test24_impl, m)
{
    m.def("hello", []()
          { return "Hello world!"; });
    m.def("hello2", []()
          { return "Hello world2!"; });
    m.def("hello3", [](std::vector<std::string> &words)
          {
            std::string result("Hello world3!\n$words");
            return std::regex_replace(result, std::regex("\\$words"), join(',', words.begin(), words.end())); });
}