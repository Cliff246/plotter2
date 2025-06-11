# Minimum required version of CMake.
cmake_minimum_required(VERSION 3.10)

# Define the project name and language.
project(plotter2)

# Set C++ standard (adjust as needed) and ensure it's required.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Optionally set the build type (you can override this via the command line)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# --- Python3 Setup ---

# Locate Python3 including its Interpreter and Development components.
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Debug output for Python3 information.
message(STATUS "Python3 Found: ${Python3_EXECUTABLE}")
message(STATUS "Python3 Include Dir: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3 Library: ${Python3_LIBRARY}")

# Override the Python3::Python target's INTERFACE_LINK_LIBRARIES property.
# This forces CMake to only use the absolute library path, which avoids adding
# the extra '-lPython3' flag that causes the linker error.
get_target_property(PYTHON_LINKS Python3::Python INTERFACE_LINK_LIBRARIES)
message(STATUS "Python3::Python INTERFACE_LINK_LIBRARIES before modification: ${PYTHON_LINKS}")

# Set the interface link libraries to the absolute path you know is valid.

if(APPLE)

    set_target_properties(Python3::Python PROPERTIES
        INTERFACE_LINK_LIBRARIES "/Library/Frameworks/Python.framework/Versions/3.13/lib/libpython3.13.dylib"
    )
elseif()
    set(Python3::Python ${Python3_LIBRARY})
endif()
#FUCK
get_target_property(PYTHON_LINKS_NEW Python3::Python INTERFACE_LINK_LIBRARIES)
message(STATUS "Python3::Python INTERFACE_LINK_LIBRARIES after modification: ${PYTHON_LINKS_NEW}")

# --- Eigen3 Setup ---

# Find the Eigen3 library (required for your project).
find_package(Eigen3 REQUIRED)
message(STATUS "Eigen3 found at: ${EIGEN3_INCLUDE_DIR}")


find_package(pybind11 REQUIRED)

# --- Global Include Directories (if needed) ---

include_directories(
    ${Python3_INCLUDE_DIRS}
    ${Eigen3_INCLUDE_DIRS}
	
)

add_subdirectory(src)





