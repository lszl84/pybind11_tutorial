#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "person.h"

PYBIND11_MODULE(advanced_module, m)
{
    pybind11::enum_<Department>(m, "Department")
        .value("HR", Department::HR)
        .value("Engineering", Department::Engineering)
        .value("Sales", Department::Sales)
        .value("Marketing", Department::Marketing)
        .export_values();

    pybind11::class_<Person>(m, "Person")
        .def(pybind11::init<std::string, std::string, Department>())
        .def("ReassignDepartment", &Person::ReassignDepartment)
        .def_readwrite("name", &Person::name)
        .def_readwrite("position", &Person::position)
        .def_readwrite("department", &Person::department);
}
