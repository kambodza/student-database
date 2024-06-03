cmake_minimum_required(VERSION 3.5.0)
project(student-database VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

include(CTest)
enable_testing()

include_directories(src)
add_executable(student-database 
src/main.cpp
src/student.cpp
src/database.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


