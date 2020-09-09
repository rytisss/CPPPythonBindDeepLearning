#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{};

    auto py_module = py::module::import("trainModel");
    py::object result = py_module.attr("test")();//void
    std::cout << "Finish!" << std::endl;
}