#include <iostream>
#include <Python.h>
#include <filesystem>
#include "manifest.hpp"
#include <pybind11/embed.h>
namespace py = pybind11;

int32_t main() 
{
	py::scoped_interpreter guard{};
	py::exec(R"(
        kwargs = dict(name="World", number=42)
        message = "Hello, {name}! The answer is {number}".format(**kwargs)
        print(message)
    )");
	return 0;
}
