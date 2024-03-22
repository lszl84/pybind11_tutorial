cmake_minimum_required(VERSION 3.5...3.18)
project(AdvancedPyBindExample)

find_package (Python3 COMPONENTS Interpreter Development REQUIRED) # the Development component is required, else we get an error: https://github.com/pybind/pybind11/issues/3996

execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE PYBIND11_CMAKE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
set(pybind11_DIR ${PYBIND11_CMAKE_DIR})

message(STATUS "Using pybind11 found at: ${pybind11_DIR}")
find_package(pybind11 REQUIRED)

# Create Python module
pybind11_add_module(advanced_module SHARED pybind_wrapper.cpp person.cpp)

set_target_properties(advanced_module PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# Needed for importing the "advanced_module" module from the build directory
set(INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/__init__.py")
if(NOT EXISTS ${INIT_PY})
    file(WRITE ${INIT_PY} "")
endif()

add_custom_command(TARGET advanced_module POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE_DIR:advanced_module>/$<TARGET_FILE_NAME:advanced_module>
            ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_FILE_NAME:advanced_module>
)
