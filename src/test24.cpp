#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/optional.h>
#include <vector>
#include <string>
#include <regex>
#include <numeric>
#include <optional>

namespace nb = nanobind;
using namespace nb::literals;

// Join vector of strings
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

struct BaseParameters
{
    std::vector<std::string> exclude;
    std::optional<bool> check;
};

NB_MODULE(_test24_impl, m)
{
    m.def("hello", []()
          { return "Hello world!"; });
    m.def("hello2", []()
          { return "Hello world2!"; });
    m.def(
        "hello3",
        [](
            std::vector<std::string> &words,
            std::optional<bool> check)
        {
            std::string result("Hello world3!\n$words");
            return std::regex_replace(result, std::regex("\\$words"), join(',', words.begin(), words.end())); });

    nb::class_<BaseParameters>(m, "BaseParameters")
        .def(nb::init<>(), "Instantiates an instance of BaseParameters.\n\n")
        .def("__init__", [](BaseParameters *t, std::vector<std::string> exclude, std::optional<bool> check)
             {
                new (t) BaseParameters();
                t->exclude = exclude;
                t->check = check; }, "exclude"_a = std::vector<std::string>(), "check"_a = true)
        .def_rw("exclude", &BaseParameters::exclude)
        .def_rw("check", &BaseParameters::check);
}