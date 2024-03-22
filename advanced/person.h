#pragma once

#include <string>

enum class Department {
    HR,
    Engineering,
    Sales,
    Marketing
};

struct Person {
    std::string name;
    std::string position;
    Department department;

    void ReassignDepartment(Department new_department);
};
