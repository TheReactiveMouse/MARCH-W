cmake_minimum_required(VERSION 3.21)
project(MARCHW)

set(CMAKE_CXX_STANDARD 23)

add_executable(MARCHW main.cpp arch/ErrorProtectedMemory.h arch/ErrorOutOfTheRange.h arch/ErrorInvalidMathExecution.h arch/ErrorIsNotAValue.h arch/ErrorDivideByZero.h)
